; CONFIG
;#include "p12f675.inc"            ; use my own definitions in this example
 __config 0x31F5
; __CONFIG _FOSC_INTRCCLK & _WDTE_OFF & _PWRTE_OFF & _MCLRE_ON & _BOREN_ON & _CP_OFF & _CPD_OFF


RES_VECT  CODE    0x0000            ; processor reset vector
    GOTO    START                   ; go to beginning of program

MAIN_PROG CODE                      ; let linker place main program

; SOME DEFINES
STATUS equ 0x03                     ; status register
FSR    equ 0x04                     ; File Select Register
GPIO   equ 0x05                     ; General Purpose Input Output (GPIO) register,
TRISIO equ 0x85                     ; TRIState Input Output (TRISIO) register
GP0    equ 0x00                     ; GPIO 0 bit of the TRISIO and GPIO registers
RP0    equ 0x05                     ; RP0 bit of the STATUS register

START
    bsf STATUS, RP0                 ; select bank 1
    bcf TRISIO, GP0                 ; set GPIO 0 as output (default is input)
    bcf STATUS, RP0                 ; select bank 0

LOOP
    bsf GPIO, GP0                   ; bit set file - set GPIO 0 high
    call WasteLotsAndLotsOfTime
    bcf GPIO, GP0                   ; bit clear file - set GPIO 0 low
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