; PIC16F84A Configuration Bit Settings

; Assembly source line config statements
#include "p16f84a.inc"

; CONFIG
; __config 0xFFFA
__CONFIG _FOSC_HS & _WDTE_OFF & _PWRTE_OFF & _CP_OFF

RES_VECT  CODE    0x0000            ; processor reset vector
    GOTO    START                   ; go to beginning of program

; TODO ADD INTERRUPTS HERE IF USED

MAIN_PROG CODE                      ; let linker place main program

START
    bsf STATUS, RP0                 ; select bank 1
    bcf TRISA, RA3                  ; set GPIO 0 as output (default is input)
    bcf STATUS, RP0                 ; select bank 0

LOOP
    bsf PORTA, RA3                  ; bit set file - set RA3 high
    call WasteLotsAndLotsOfTime
    bcf PORTA, RA3                  ; bit clear file - set RA3 low
    call WasteLotsAndLotsOfTime
    GOTO LOOP                       ; loop forever

WasteLotsAndLotsOfTime:             ; only using the working register, result is ~ 4Hz blink
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
    movlw       0x0;                  ; loop 0xFF times, costing 12 cycles + 8 cycles per loop

WasteTimeInnerLoop:
    xorlw       0xFF                  ; 1's complement of W
    sublw       0                     ; 2's complement W - 0, result is original number + 1
    nop                               ; pad this out to 8 cycles per loop
    nop
    nop
    skpz                              ; exit the loop if W has wrapped to 0
    goto        WasteTimeInnerLoop

    return

    END