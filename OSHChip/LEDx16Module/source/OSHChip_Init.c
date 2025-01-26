//
//  OSHChip_Init.cpp
//
//  This function allows OSHChip projects that use the UART for printf()
//  to work with the target board set to nRF51-DK
//

//
//  By the time your program gets to main(), the pre-main initialization has
//  (among other things) setup the UART to use the nRF51-DK UART pins, and a
//  transmission speed of 9600 Baud, 8N1.
//
//      nRF51-DK
//          RX_PIN_NUMBER  = p11,
//          TX_PIN_NUMBER  = p9,
//          CTS_PIN_NUMBER = p10,
//          RTS_PIN_NUMBER = p8,
//
//  For OSHChip, the default is TX on pin 1, RX on pin 2, and no CTS or RTS
//  because OSHChip has so few I/O pins.
//
//  Due to the default implementation of Serial I/O in mbed, when \n
//  is set to the UART, all that is actually transmitted is the "newline".
//  In a Unix/Mac environment this is usually sufficient, but in a 
//  DOS/Windows environment, \n\r needs to be sent.
//
//  If you are using the Serial to USB service on the OSHChip_CMSIS_DAP,
//  TXD (pin 1 on OSHChip as configured by this function) should be
//  connected to the pin closest to the corner of the PCB on connector J5,
//  which is labeled "RX In". RXD (pin 2 on OSHChip as configured by this
//  function) should be connected to the other pin on J5 which is labeled
//  "TX Out"
//

#include "nrf51.h"
#include "nrf51_bitfields.h"
#include "OSHChip_Pin_Names.h"

void OSHChip_Init(void)
{
    NRF_UART0->PSELTXD = TX_PIN_NUMBER;
    NRF_UART0->PSELRXD = RX_PIN_NUMBER;
    NRF_UART0->PSELRTS = 0xFFFFFFFF;
    NRF_UART0->PSELCTS = 0xFFFFFFFF;

//
//  If you want to change the default Baud, uncomment the following assignment
//
//  Here are the pre-defined Baud values:
//
// UART_BAUDRATE_BAUDRATE_Baud1200,    UART_BAUDRATE_BAUDRATE_Baud2400,    UART_BAUDRATE_BAUDRATE_Baud4800,
// UART_BAUDRATE_BAUDRATE_Baud9600,    UART_BAUDRATE_BAUDRATE_Baud14400,   UART_BAUDRATE_BAUDRATE_Baud19200,
// UART_BAUDRATE_BAUDRATE_Baud28800,   UART_BAUDRATE_BAUDRATE_Baud38400,   UART_BAUDRATE_BAUDRATE_Baud57600,
// UART_BAUDRATE_BAUDRATE_Baud76800,   UART_BAUDRATE_BAUDRATE_Baud115200,  UART_BAUDRATE_BAUDRATE_Baud230400,
// UART_BAUDRATE_BAUDRATE_Baud250000,  UART_BAUDRATE_BAUDRATE_Baud460800,  UART_BAUDRATE_BAUDRATE_Baud921600,
// UART_BAUDRATE_BAUDRATE_Baud1M

 //  NRF_UART0->BAUDRATE = UART_BAUDRATE_BAUDRATE_Baud115200;

}
