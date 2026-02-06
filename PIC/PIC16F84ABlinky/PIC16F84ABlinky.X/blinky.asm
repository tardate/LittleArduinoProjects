#include "xc.inc"

RADIX hex

; PIC16F84A Configuration Bit Settings
config "FOSC" = HS
config "WDTE" = OFF
config "PWRTE" = OFF
config "CP" = OFF

PSECT reset_vec,class=CODE,delta=2,abs
    ORG 0x0000                        ; processor reset vector
    GOTO START                        ; go to beginning of program

; Main code section
PSECT code,class=CODE,delta=2

START:
    BANKSEL TRISA
    bcf TRISA, TRISA_TRISA3_POSN       ; set RA3 as output (default is input)
    BANKSEL PORTA

LOOP:
    bsf PORTA, PORTA_RA3_POSN          ; bit set file - set RA3 high
    call WasteLotsAndLotsOfTime
    bcf PORTA, PORTA_RA3_POSN          ; bit clear file - set RA3 low
    call WasteLotsAndLotsOfTime
    GOTO LOOP                          ; loop forever

WasteLotsAndLotsOfTime:                ; only using the working register, result is ~ 4Hz blink
    call WasteLotsOfTime
    call WasteLotsOfTime
    call WasteLotsOfTime
    call WasteLotsOfTime

WasteLotsOfTime:
    call WasteTime
    call WasteTime
    call WasteTime
    call WasteTime
    call WasteTime
    call WasteTime
    call WasteTime
    call WasteTime
    call WasteTime
    call WasteTime

WasteTime:
    movlw       0x0;                     ; loop 0xFF times, costing 12 cycles + 8 cycles per loop

WasteTimeInnerLoop:
    xorlw       0xFF                     ; 1's complement of W
    sublw       0                        ; 2's complement W - 0, result is original number + 1
    nop                                  ; pad this out to 8 cycles per loop
    nop
    nop
    btfss       STATUS, STATUS_ZERO_POSN ; exit the loop if W has wrapped to 0
    goto        WasteTimeInnerLoop

    return

    END
