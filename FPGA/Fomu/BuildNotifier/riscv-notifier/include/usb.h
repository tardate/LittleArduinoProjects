#ifndef __USB_H
#define __USB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

struct usb_setup_request;

void usb_isr(void);
void usb_init(void);
void usb_connect(void);
void usb_idle(void);
void usb_disconnect(void);
void usb_setup(const struct usb_setup_request *setup, uint32_t size);
void usb_set_address(uint8_t address);

void usb_ack_in(void);
void usb_ack_out(void);
void usb_err(void);
void usb_send(const void *data, int total_count);

#ifdef __cplusplus
}
#endif

#endif
