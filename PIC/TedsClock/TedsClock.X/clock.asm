        LIST P=16F84
;;;
;;; Clock I driver - LED clock
;;; 2/19/2000/tcy
;;; 2/29/2000/tcy updated
;;; Copyright (C) 2000, Theodore C. Yapo.  All rights reserved.
;;;
PORTA   EQU     0x05
PORTB   EQU     0x06
TRISB   EQU     0x86
TRISA   EQU     0x85
;
OPTREG  EQU     0x81
INTCON  EQU     0x0b
STATUS  EQU     0x03
CARRY   EQU     0x00
RP0     EQU     0x05
W               EQU     0x00
PCL     EQU     0x02
TMR0    EQU     0x01
T0IF    EQU     0x02
#define _Z STATUS, 2
#define _C STATUS, 0
;;;
;;; configuration word
;;; ~Code Protect|~PWRT Enable|WDT enable| OSC selection 2 bits|
;;;
        CPD     EQU     0xfff0; code protection
        PWRTE   EQU     b'1000'; code protect (inverted)
        WDTE    EQU     b'0100'; watchdog timer enable
        RC      EQU     b'0011'; external RC oscillator
        HS      EQU     b'0010'; high-speed crystal osc
        XT      EQU     b'0001'; standard crystal osc
        LP      EQU     b'0000'; low-power crystal osc

        __CONFIG        CPD | LP

        CBLOCK 0x0C
                tick            ; a tick is 1/32 second
                hour            ; 0-11
                minute_1        ; minutes mod 5
                minute_5        ; minutes / 5
                second_1        ; seconds mod 5
                second_5        ; seconds / 5
                porta_value     ; accumulates lit LEDs
                portb_value     ; accumulates lit LEDs
                minutes_button  ; saves left button state for debounce
                hours_button    ; saves right button state for debounce
        ENDC
;;;
;;; on reset, call the startup code
;;;
        ORG     0               ; reset vector
        GOTO    STARTUP
;;;
;;; this ISR gets called on every TMR0 overflow interrupt (32Hz)
;;;  increment the time, as appropriate
;;;  display the time on the LEDs
;;;  clear the TMR0 interrupt
;;;
        ORG     0x04            ; interrupt vector
        INCF    tick            ; incremented at 32 Hz
        BTFSS   tick, 5         ; check if tick has exceeded 32
        GOTO    NO_SECOND       ; nope, just display current time
        CLRF    tick            ; yes, a whole second has passed

        CALL    INC_SECONDS     ; increment to next second
NO_SECOND:

        CLRF    porta_value     ; clear display
        CLRF    portb_value     ; clear display

        ;; if minutes are being adjusted, don't display hours
        ;;  note that minute_button is 1 if not being pressed, > 1 if pressed
        DECF    minutes_button, W
        BTFSS   _Z
        GOTO    SKIP_HOUR_DISPLAY
        ;; set the hour LED values into the temp registers
        MOVF    hour, W
        CALL    HAND_PORTA
        MOVWF   porta_value
        MOVF    hour, W
        CALL    HAND_PORTB
        MOVWF   portb_value
SKIP_HOUR_DISPLAY:

        ;; if hours are being adjusted, don't display minutes
        ;;  note that hour_button is 1 if not being pressed, > 1 if pressed
        DECF    hours_button, W
        BTFSS   _Z
        GOTO    BLINK_MINUTE

        ;; if minutes are being adjusted, display minutes as solid
        ;;  note that minute_button is 1 if not being pressed, > 1 if pressed
        DECF    minutes_button, W
        BTFSS   _Z
        GOTO    SOLID_MINUTE

        ;; set the minute LED values only if tick bit 4
        ;;   this "blinks" the minute LED at 1Hz
        BTFSC   tick, 4
        GOTO    BLINK_MINUTE
SOLID_MINUTE:
        MOVF    minute_5, W
        CALL    HAND_PORTA
        XORWF   porta_value     ; XOR in the minute LED
        MOVF    minute_5, W
        CALL    HAND_PORTB
        XORWF   portb_value     ; XOR in the minute LED
BLINK_MINUTE:

        ;; if minutes are being adjusted, don't display seconds
        ;;  note that minute_button is 1 if not being pressed, > 1 if pressed
        DECF    minutes_button, W
        BTFSS   _Z
        GOTO    BLINK_SECOND

        ;; if hours are being adjusted, don't display seconds
        ;;  note that hour_button is 1 if not being pressed, > 1 if pressed
        DECF    hours_button, W
        BTFSS   _Z
        GOTO    BLINK_SECOND

        ;; set the second LED values only if tick bit 2 is set
        ;;   this "blinks" the minute LED at 4Hz
        BTFSC   tick, 2
        GOTO    BLINK_SECOND
        MOVF    second_5, W
        CALL    HAND_PORTA
        XORWF   porta_value     ; XOR in the second LED
        MOVF    second_5, W
        CALL    HAND_PORTB
        XORWF   portb_value     ; XOR in the second LED
BLINK_SECOND:

        ;; check for button press
        BSF     STATUS, RP0     ;SELECT REGISTER BANK 1
        BSF     TRISB, 2        ; set RB2 to input
        BSF     TRISA, 3        ; set RA3 to input
        BCF     STATUS, RP0     ; select bank 0
        ;; check minutes (must be pressed for at least 4 ticks)
        BTFSS   PORTB, 2        ; test RB2
        CLRF    minutes_button  ; button not pressed, clear count
        INCF    minutes_button  ; increment the minutes button count
        BTFSS   minutes_button, 4; wait for press of at least 16 counts
        GOTO    SKIP_MINUTE_INC
        MOVLW   d'2'            ; reset the count
        MOVWF  minutes_button   ;   to 2
        ;; increment 5_minutes
        CLRF    second_1        ; clear seconds (1x)
        CLRF    second_5        ; clear seconds (5x)
        CLRF    minute_1        ; clear the 1-minute inc
        INCF    minute_5        ; next minute (5x)
        MOVLW   d'12'           ; check for
        SUBWF   minute_5, W
        BTFSS   _Z              ; check minutes overflow
        GOTO    SKIP_MINUTE_INC ; minutes didn't overflow, so ripple ends
        CLRF    minute_5
SKIP_MINUTE_INC:
        ;; check hours (must be pressed for at least 4 ticks)
        BTFSS   PORTA, 3        ; test RA3
        CLRF    hours_button    ; button not pressed, clear count
        INCF    hours_button    ; increment the hours button count
        BTFSS   hours_button, 4 ; wait for press of at least 16 counts
        GOTO    SKIP_HOUR_INC
        MOVLW   d'2'            ; reset the count
        MOVWF   hours_button    ; to '2'
        CALL    INC_HOURS       ; increment hour, if pressed
SKIP_HOUR_INC:
        BSF     STATUS, RP0     ;SELECT REGISTER BANK 1
        BCF     TRISB, 2        ; set RB2 to output
        BCF     TRISA, 3        ; set RA3 to output
        BCF     STATUS, RP0     ; select bank 0

        ;; light the appropriate LEDs
        MOVF    porta_value, W
        MOVWF   PORTA
        MOVF    portb_value, W
        MOVWF   PORTB

        BCF     INTCON, T0IF    ; clear TMR0 interrupt
        RETFIE                  ; return from ISR
;;;
;;; INC_X routines: multiple entry points to increment seconds, minutes, hours
;;;   with appropriate ripple updating
INC_SECONDS:
        INCF    second_1        ; increment to next second
        MOVLW   d'5'
        SUBWF   second_1, W
        BTFSS   _Z              ; check seconds overflow
        GOTO    INC_DONE        ; seconds didn't overflow, so ripple ends
        CLRF    second_1        ;   ripple continues, reset second_1
        INCF    second_5        ; next 5 second
        MOVLW   d'12'
        SUBWF   second_5, W
        BTFSS   _Z              ; check seconds overflow
        GOTO    INC_DONE        ; seconds didn't overflow, so ripple ends
        CLRF    second_5        ;   ripple continues, reset second_5
INC_MINUTES:
        INCF    minute_1        ; next minute
        MOVLW   d'5'
        SUBWF   minute_1, W
        BTFSS   _Z              ; check minutes overflow
        GOTO    INC_DONE        ; minutes didn't overflow, so ripple ends
INC_5MINUTES:
        CLRF    minute_1
        INCF    minute_5        ; next minute
        MOVLW   d'12'
        SUBWF   minute_5, W
        BTFSS   _Z              ; check minutes overflow
        GOTO    INC_DONE        ; minutes didn't overflow, so ripple ends
        CLRF    minute_5
INC_HOURS:
        INCF    hour            ; next hour
        MOVLW   d'12'
        SUBWF   hour, W
        BTFSS   _Z              ; check hours overflow
        GOTO    INC_DONE        ; hours didn't overflow, so ripple ends
        CLRF    hour            ; hours overflowed, so reset
INC_DONE:
        RETURN

;;;
;;; ---------------------------------------------------------------
;;;

;;;
;;; startup code executes on reset
;;;
STARTUP:
        CLRF    PORTA           ; clear port A
        CLRF    PORTB           ; clear port B
        BSF     STATUS, RP0     ;SELECT REGISTER BANK 1
        MOVLW   0x00            ; set portb to
        MOVWF   TRISB           ;   all output
        MOVLW   0x00            ; set porta to
        MOVWF   TRISA           ;   all outout
        MOVLW   b'11001000'     ; option
        MOVWF   OPTREG
        BCF     STATUS, RP0     ; select bank 0
        MOVLW   b'10100000'     ; enable TMR0 interrupt
        MOVWF   INTCON
;;;
;;; set time to 0:0:0
;;;
        CLRF    tick
        CLRF    hour
        CLRF    minute_1
        CLRF    minute_5
        CLRF    second_1
        CLRF    second_5
        ;; clear debounce flags
        CLRF    minutes_button
        CLRF    hours_button
;;;
;;; the system is completely interrupt driven from the TMR0 overflow
;;;  interrupt, so this loop simply spins until interrupted
;;;
IDLE:   GOTO IDLE
;;;
;;;-----------------------------------------------------------------
;;;

;;;
;;; return the value to output on PORTA for a specific "hand position" in W
;;; 0-11
HAND_PORTA:
        ADDWF   PCL
        RETLW   0               ; 12 o'clock
        RETLW   0               ;  1 o'clock
        RETLW   0               ;  2 o'clock
        RETLW   0               ;  3 o'clock
        RETLW   0               ;  4 o'clock
        RETLW   0               ;  5 o'clock
        RETLW   0               ;  6 o'clock
        RETLW   0x8             ;  7 o'clock
        RETLW   0x4             ;  8 o'clock
        RETLW   0x2             ;  9 o'clock
        RETLW   0x1             ; 10 o'clock
        RETLW   0               ; 11 o'clock
;;;
;;; return the value to output on PORTB for a specific "hand position" in W
;;; 0-11
HAND_PORTB:
        ADDWF   PCL
        RETLW   0x40            ; 12 o'clock
        RETLW   0x20            ;  1 o'clock
        RETLW   0x10            ;  2 o'clock
        RETLW   0x08            ;  3 o'clock
        RETLW   0x04            ;  4 o'clock
        RETLW   0x02            ;  5 o'clock
        RETLW   0x01            ;  6 o'clock
        RETLW   0               ;  7 o'clock
        RETLW   0               ;  8 o'clock
        RETLW   0               ;  9 o'clock
        RETLW   0               ; 10 o'clock
        RETLW   0x80            ; 11 o'clock
        ;;;
        ;;;
        END