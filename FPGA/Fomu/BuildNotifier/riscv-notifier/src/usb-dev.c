#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <usb.h>

struct usb_setup_request {
    union {
        struct {
            uint8_t bmRequestType;
            uint8_t bRequest;
        };
        uint16_t wRequestAndType;
    };
    uint16_t wValue;
    uint16_t wIndex;
    uint16_t wLength;
};

static const uint8_t usb_device_descriptor[] = {
    0x12, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x40,
    0x09, 0x12, 0xf0, 0x5b, 0x01, 0x01, 0x01, 0x02,
    0x00, 0x01
};

static const uint8_t usb_config_descriptor[] = {
    0x09, 0x02, 0x12, 0x00, 0x01, 0x01, 0x01, 0x80,
    0x32, 0x09, 0x04, 0x00, 0x00, 0x00, 0xfe, 0x00,
    0x00, 0x02
};
        
static const uint8_t usb_string0_descriptor[] = {
    0x04, 0x03, 0x09, 0x04
};

static const uint8_t usb_string1_descriptor[] = {
    0x0c, 0x03, 0x46, 0x00, 0x6f, 0x00, 0x6f, 0x00,
    0x73, 0x00, 0x6e, 0x00
};

static const uint8_t usb_string2_descriptor[] = {
    0x16, 0x03, 0x46, 0x00, 0x6f, 0x00, 0x6d, 0x00,
    0x75, 0x00, 0x20, 0x00, 0x42, 0x00, 0x6c, 0x00,
    0x69, 0x00, 0x6e, 0x00, 0x6b, 0x00
};

static const uint8_t usb_bos_descriptor[] = {
    0x05, 0x0f, 0x1d, 0x00, 0x01, 0x18, 0x10, 0x05,
    0x00, 0x38, 0xb6, 0x08, 0x34, 0xa9, 0x09, 0xa0,
    0x47, 0x8b, 0xfd, 0xa0, 0x76, 0x88, 0x15, 0xb6,
    0x65, 0x00, 0x01, 0x02, 0x01,
};

static const uint8_t usb_ms_compat_id_descriptor[] = {
    0x28, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x57, 0x49, 0x4e, 0x55, 0x53, 0x42,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

#define MSFT_VENDOR_CODE    '~'     // Arbitrary, but should be printable ASCII
static const uint8_t usb_string_microsoft[18] = {
    18, 3, 'M','S','F','T','1','0','0', MSFT_VENDOR_CODE,
    0, 0, 0, 0, 0, 0, 0, 0,
};


static uint8_t reply_buffer[8];
static uint8_t usb_configuration = 0;
static uint8_t data_buffer[64];

__attribute__((section(".ramtext")))
void usb_setup(const struct usb_setup_request *setup, uint32_t size)
{
    const uint8_t *data = NULL;
    uint32_t datalen = 0;
    (void)size;

    switch (setup->wRequestAndType)
    {
    case 0x0500: // SET_ADDRESS
        usb_set_address(setup->wValue);
        break;

    case 0x0b01: // SET_INTERFACE
        break;

    case 0x0900: // SET_CONFIGURATION
        usb_configuration = setup->wValue;
        break;

    case 0x0880: // GET_CONFIGURATION
        reply_buffer[0] = usb_configuration;
        datalen = 1;
        data = reply_buffer;
        break;

    case 0x0080: // GET_STATUS (device)
        reply_buffer[0] = 0;
        reply_buffer[1] = 0;
        datalen = 2;
        data = reply_buffer;
        break;

    case 0x0082: // GET_STATUS (endpoint)
        if (setup->wIndex > 0)
        {
            usb_err();
            return;
        }
        reply_buffer[0] = 0;
        reply_buffer[1] = 0;
        data = reply_buffer;
        datalen = 2;
        break;

    case 0x0102: // CLEAR_FEATURE (endpoint)
        if (setup->wIndex > 0 || setup->wValue != 0)
        {
            // TODO: do we need to handle IN vs OUT here?
            usb_err();
            return;
        }
        break;

    case 0x0302: // SET_FEATURE (endpoint)
        if (setup->wIndex > 0 || setup->wValue != 0)
        {
            // TODO: do we need to handle IN vs OUT here?
            usb_err();
            return;
        }
        break;

    case 0x0680: // GET_DESCRIPTOR
    case 0x0681:
        #define CASE_VALUE(match, result) case match: data = result; datalen = sizeof(result); break
        switch (setup->wValue) {
            CASE_VALUE(0x0100, usb_device_descriptor);
            CASE_VALUE(0x0200, usb_config_descriptor);
            CASE_VALUE(0x0300, usb_string0_descriptor);
            CASE_VALUE(0x0301, usb_string1_descriptor);
            CASE_VALUE(0x0302, usb_string2_descriptor);
            CASE_VALUE(0x03ee, usb_string_microsoft);
            CASE_VALUE(0x0f00, usb_bos_descriptor);
            default: usb_err(); return;
        }
        #undef CASE_VALUE
        goto send;

    case (MSFT_VENDOR_CODE << 8) | 0xC0: // Get Microsoft descriptor
    case (MSFT_VENDOR_CODE << 8) | 0xC1:
        if (setup->wIndex == 0x0004)
        {
            // Return WCID descriptor
            data = usb_ms_compat_id_descriptor;
            datalen = sizeof(usb_ms_compat_id_descriptor);
            break;
        }
        usb_err();
        return;

#ifdef LANDING_PAGE_URL
    case (WEBUSB_VENDOR_CODE << 8) | 0xC0: // Get WebUSB descriptor
        if (setup->wIndex == 0x0002)
        {
            if (setup->wValue == 0x0001)
            {
                data = get_landing_url_descriptor(&datalen);
                break;
            }
        }
        usb_err();
        return;
#endif

    default:
        usb_err();
        return;
    }

send:
    if (data && datalen) {
        if (datalen > setup->wLength)
            datalen = setup->wLength;
        if (datalen > sizeof(data_buffer))
            datalen = sizeof(data_buffer);
        memcpy(data_buffer, data, datalen);
        usb_send(data_buffer, datalen);
    }
    else
        usb_ack_in();
    return;
}
