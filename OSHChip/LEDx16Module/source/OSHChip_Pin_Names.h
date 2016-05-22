/*  OSHChip_Pin_Names.h
    This is the version if you want the Serial Output on OSHChip_Pin_1
    This is the version if you want the Serial Input on OSHChip_Pin_2
    Tabs every 4 columns
*/

#ifndef OSHCHIP_PIN_NAMES_H
#define OSHCHIP_PIN_NAMES_H

#ifdef __cplusplus
extern "C" {
#endif

#define p0          ( 0)
#define p1          ( 1)
#define p2          ( 2)
#define p3          ( 3)
#define p4          ( 4)
#define p5          ( 5)
#define p6          ( 6)
#define p7          ( 7)
#define p8          ( 8)
#define p9          ( 9)
#define p10         (10)
#define p11         (11)
#define p12         (12)
#define p13         (13)
#define p14         (14)
#define p15         (15)
#define p16         (16)
#define p17         (17)
#define p18         (18)
#define p19         (19)
#define p20         (20)
#define p21         (21)
#define p22         (22)
#define p23         (23)
#define p24         (24)
#define p25         (25)
#define p26         (26)
#define p27         (27)
#define p28         (28)
#define p29         (29)
#define p30         (30)
#define p31         (31)

#define P0_0        (p0)
#define P0_1        (p1)
#define P0_2        (p2)
#define P0_3        (p3)
#define P0_4        (p4)
#define P0_5        (p5)
#define P0_6        (p6)
#define P0_7        (p7)

#define P0_8        ( p8)
#define P0_9        ( p9)
#define P0_10       (p10)
#define P0_11       (p11)
#define P0_12       (p12)
#define P0_13       (p13)
#define P0_14       (p14)
#define P0_15       (p15)

#define P0_16       (p16)
#define P0_17       (p17)
#define P0_18       (p18)
#define P0_19       (p19)
#define P0_20       (p20)
#define P0_21       (p21)
#define P0_22       (p22)
#define P0_23       (p23)

#define P0_24       (p24)
#define P0_25       (p25)
#define P0_26       (p26)
#define P0_27       (p27)
#define P0_28       (p28)
#define P0_29       (p29)
#define P0_30       (p30)
#define P0_31       (p31)

#define LED_RED     (p8)
#define LED_GREEN   (p5)
#define LED_BLUE    (p3)

//#define RED_LED     (p8)      // don't declare these, so the user can use these names is 
//#define GREEN_LED   (p5)      // something like:   DigitalOut RED_LED(LED_RED);
//#define BLUE_LED    (p3)

#define LED1        (LED_RED)               // These are used in board.c, so make a best effort
#define LED2        (LED_GREEN)
#define LED3        (LED_BLUE)
#define LED4        ((int)0xFFFFFFFF)

#define LED_0       (LED_RED)               // These are used in board.c, so make a best effort
#define LED_1       (LED_GREEN)
#define LED_2       (LED_BLUE)
#define LED_3       ((int)0xFFFFFFFF)

#define OSHChip_Pin_1       (p20)
#define OSHChip_Pin_2       (p18)
#define OSHChip_Pin_3       (p16)
#define OSHChip_Pin_4       (p15)
#define OSHChip_Pin_5       (p12)
#define OSHChip_Pin_6       (p11)
#define OSHChip_Pin_7       ( p9)
#define OSHChip_Pin_9       ( p1)
#define OSHChip_Pin_10      ( p2)
#define OSHChip_Pin_11      ( p0)
#define OSHChip_Pin_12      (p27)
#define OSHChip_Pin_13      (p26)
#define OSHChip_Pin_14      (p24)
#define OSHChip_Pin_15      (p21)

#define RX_PIN_NUMBER       (OSHChip_Pin_2)
#define TX_PIN_NUMBER       (OSHChip_Pin_1)
#define CTS_PIN_NUMBER      (p30)           // select an unused output of the nRF51822
#define RTS_PIN_NUMBER      (p29)           // select an unused output of the nRF51822

void OSHChip_Init(void);

#ifdef __cplusplus
}
#endif

#endif      // OSHCHIP_PIN_NAMES_H
