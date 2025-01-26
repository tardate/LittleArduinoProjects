#include <irq.h>
#include <generated/csr.h>
#include <string.h>
#include <usb.h>

// #ifdef CSR_USB_EP_0_OUT_EV_PENDING_ADDR
#if 1

#define EP0OUT_BUFFERS 1
__attribute__((aligned(4)))
static uint8_t usb_ep0out_buffer_len[EP0OUT_BUFFERS];
static uint8_t usb_ep0out_buffer[EP0OUT_BUFFERS][128];
static uint8_t usb_ep0out_last_tok[EP0OUT_BUFFERS];
static uint8_t usb_ep0out_wr_ptr;
static uint8_t usb_ep0out_rd_ptr;
static const int max_byte_length = 64;

static const uint8_t * current_data;
static int current_length;
static int data_offset;
static int data_to_send;
static int next_packet_is_empty;

static uint8_t new_address;
static int have_new_address;

// Note that our PIDs are only bits 2 and 3 of the token,
// since all other bits are effectively redundant at this point.
enum USB_PID {
    USB_PID_OUT   = 0,
    USB_PID_SOF   = 1,
    USB_PID_IN    = 2,
    USB_PID_SETUP = 3,
};

enum epfifo_response {
    EPF_ACK = 0,
    EPF_NAK = 1,
    EPF_NONE = 2,
    EPF_STALL = 3,
};

#define USB_EV_ERROR 1
#define USB_EV_PACKET 2

// Firmware versions < 1.9 didn't have usb_address_write()
static void usb_set_address_wrapper(uint8_t address) {
    if (version_major_read() < 1)
        return;
    if (version_minor_read() < 9)
        return;
    usb_address_write(address);
}

void usb_idle(void) {
    usb_ep_0_out_ev_enable_write(0);
    usb_ep_0_in_ev_enable_write(0);

    // Reject all incoming data, since there is no handler anymore
    usb_ep_0_out_respond_write(EPF_NAK);

    // Reject outgoing data, since we don't have any to give.
    usb_ep_0_in_respond_write(EPF_NAK);

    irq_setmask(irq_getmask() & ~(1 << USB_INTERRUPT));
}

void usb_disconnect(void) {
    usb_ep_0_out_ev_enable_write(0);
    usb_ep_0_in_ev_enable_write(0);
    irq_setmask(irq_getmask() & ~(1 << USB_INTERRUPT));
    usb_pullup_out_write(0);
    usb_set_address_wrapper(0);
}

void usb_connect(void) {

    usb_ep_0_out_ev_pending_write(usb_ep_0_out_ev_enable_read());
    usb_ep_0_in_ev_pending_write(usb_ep_0_in_ev_pending_read());
    usb_ep_0_out_ev_enable_write(USB_EV_PACKET | USB_EV_ERROR);
    usb_ep_0_in_ev_enable_write(USB_EV_PACKET | USB_EV_ERROR);

    // Accept incoming data by default.
    usb_ep_0_out_respond_write(EPF_ACK);

    // Reject outgoing data, since we have none to give yet.
    usb_ep_0_in_respond_write(EPF_NAK);

    usb_pullup_out_write(1);

    irq_setmask(irq_getmask() | (1 << USB_INTERRUPT));
}

void usb_init(void) {
    usb_disconnect();
    usb_ep0out_wr_ptr = 0;
    usb_ep0out_rd_ptr = 0;
}

static void process_tx(void) {

    // Don't allow requeueing -- only queue more data if we're
    // currently set up to respond NAK.
    if (usb_ep_0_in_respond_read() != EPF_NAK) {
        return;
    }

    // Prevent us from double-filling the buffer.
    if (!usb_ep_0_in_ibuf_empty_read()) {
        return;
    }

    if (!current_data || !current_length) {
        return;
    }

    data_offset += data_to_send;

    data_to_send = current_length - data_offset;

    // Clamp the data to the maximum packet length
    if (data_to_send > max_byte_length) {
        data_to_send = max_byte_length;
        next_packet_is_empty = 0;
    }
    else if (data_to_send == max_byte_length) {
        next_packet_is_empty = 1;
    }
    else if (next_packet_is_empty) {
        next_packet_is_empty = 0;
        data_to_send = 0;
    }
    else if (current_data == NULL || data_to_send <= 0) {
        next_packet_is_empty = 0;
        current_data = NULL;
        current_length = 0;
        data_offset = 0;
        data_to_send = 0;
        return;
    }

    int this_offset;
    for (this_offset = data_offset; this_offset < (data_offset + data_to_send); this_offset++) {
        usb_ep_0_in_ibuf_head_write(current_data[this_offset]);
    }
    usb_ep_0_in_respond_write(EPF_ACK);
    return;
}

void usb_send(const void *data, int total_count) {

    while ((current_length || current_data) && usb_ep_0_in_respond_read() != EPF_NAK)
        process_tx();
    current_data = (uint8_t *)data;
    current_length = total_count;
    data_offset = 0;
    data_to_send = 0;
    process_tx();
}

void usb_wait_for_send_done(void) {
    while (current_data && current_length)
        process_tx();
    while ((usb_ep_0_in_dtb_read() & 1) == 1)
        ;
}

void usb_isr(void) {
    uint8_t ep0o_pending = usb_ep_0_out_ev_pending_read();
    usb_ep_0_out_ev_pending_write(ep0o_pending);
    uint8_t ep0i_pending = usb_ep_0_in_ev_pending_read();
    usb_ep_0_in_ev_pending_write(ep0i_pending);

    // We got an OUT or a SETUP packet.  Copy it to usb_ep0out_buffer
    // and clear the "pending" bit.
    if (ep0o_pending) {
        uint8_t last_tok = usb_ep_0_out_last_tok_read();
        uint32_t obuf_len = 0;
        static uint8_t obuf[128];
        if (!usb_ep_0_out_obuf_empty_read()) {
            while (!usb_ep_0_out_obuf_empty_read()) {
                obuf[obuf_len++] = usb_ep_0_out_obuf_head_read();
                usb_ep_0_out_obuf_head_write(0);
            }
        }

        if (obuf_len >= 2)
            obuf_len -= 2 /* Strip off CRC16 */;

        if (last_tok == USB_PID_SETUP) {
            usb_ep_0_in_dtb_write(1);
            data_offset = 0;
            current_length = 0;
            current_data = NULL;
            usb_setup((const void *)obuf, obuf_len);
        }

        usb_ep_0_out_respond_write(EPF_ACK);
    }

    // We just got an "IN" token.  Send data if we have it.
    if (ep0i_pending) {
        usb_ep_0_in_respond_write(EPF_NAK);
        if (have_new_address) {
            have_new_address = 0;
            usb_set_address_wrapper(new_address);
        }
    }
    
    process_tx();
    return;
}

void usb_ack_in(void) {
    usb_ep_0_in_respond_write(EPF_ACK);
}

void usb_ack_out(void) {
    usb_ep_0_out_respond_write(EPF_ACK);
}

void usb_err(void) {
    usb_ep_0_out_respond_write(EPF_STALL);
    usb_ep_0_in_respond_write(EPF_STALL);
}

int usb_recv(void *buffer, unsigned int buffer_len) {

    // Set the OUT response to ACK, since we are in a position to receive data now.
    usb_ep_0_out_respond_write(EPF_ACK);
    while (1) {
        if (usb_ep0out_rd_ptr != usb_ep0out_wr_ptr) {
            if (usb_ep0out_last_tok[usb_ep0out_rd_ptr] == USB_PID_OUT) {
                unsigned int ep0_buffer_len = usb_ep0out_buffer_len[usb_ep0out_rd_ptr];
                if (ep0_buffer_len < buffer_len)
                    buffer_len = ep0_buffer_len;
                // usb_ep0out_buffer_len[usb_ep0out_rd_ptr] = 0;
                memcpy(buffer, (void *)&usb_ep0out_buffer[usb_ep0out_rd_ptr], buffer_len);
                usb_ep0out_rd_ptr = (usb_ep0out_rd_ptr + 1) & (EP0OUT_BUFFERS-1);
                return buffer_len;
            }
            else if (usb_ep0out_last_tok[usb_ep0out_rd_ptr] == USB_PID_SETUP) {
                return -1;
            }
            usb_ep0out_rd_ptr = (usb_ep0out_rd_ptr + 1) & (EP0OUT_BUFFERS-1);
        }
    }
    return 0;
}

void usb_set_address(uint8_t _new_address) {
    new_address = _new_address;
    have_new_address = 1;
}

#endif /* CSR_USB_EP_0_OUT_EV_PENDING_ADDR */
