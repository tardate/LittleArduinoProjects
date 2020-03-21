        LIST P=16F84
;;;
;;; Clock test: 
;;; 2/19/2000/tcy
;;; Copyright (C) 2000, Theodore C. Yapo.  All rights reserved.
;;; 
PORTA   EQU     0x05
PORTB   EQU     0x06 
TRISB   EQU     0x86
TRISA	EQU     0x85
;
BIT_OUT	EQU     0x00	; PORTA
;
OPTREG	EQU     0x81
INTCON  EQU     0x0b
STATUS	EQU     0x03
CARRY	EQU     0x00
RP0     EQU     0x05
W		EQU     0x00
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
                porta_value
                portb_value
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
        
        ;; set the hour LED values into the temp registers
        MOVF    hour, W
        CALL    HAND_PORTA
        MOVWF   porta_value
        MOVF    hour, W
        CALL    HAND_PORTB
        MOVWF   portb_value

        ;; set the minute LED values only if tick > 16
        ;;   this "blinks" the minute LED at 1Hz
        BTFSC   tick, 4
        GOTO    BLINK_MINUTE
        MOVF    minute_5, W
        CALL    HAND_PORTA
        XORWF   porta_value     ; XOR in the minute LED
        MOVF    minute_5, W
        CALL    HAND_PORTB
        XORWF   portb_value     ; XOR in the minute LED
BLINK_MINUTE:

        ;; set the second LED values only if tick bit 1 is set
        ;;   this "blinks" the minute LED at 8Hz
        BTFSC   tick, 1
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
        BTFSC   PORTB, 2        ; test RB2
        CALL    INC_MINUTES     ; increment minute, if pressed
        BTFSC   PORTA, 3        ; test RA3
        CALL    INC_HOURS       ; increment hour, if pressed
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
        CLRF	PORTB           ; clear port B
        BSF     STATUS, RP0     ;SELECT REGISTER BANK 1
        MOVLW	0x00            ; set portb to
        MOVWF	TRISB           ;   all output
        MOVLW	0x00            ; set porta to
        MOVWF	TRISA           ;   all outout
        MOVLW   b'11001000'     ; option
        MOVWF   OPTREG
        BCF     STATUS, RP0     ; select bank 0
        MOVLW   b'10100000'     ; enable TMR0 interrupt
        MOVWF   INTCON
;;;
;;; set time to 0:0:0 (like VCR blinking 12:00)
;;;
        CLRF    tick
        CLRF    hour
        CLRF    minute_1
        CLRF    minute_5
        CLRF    second_1
        CLRF    second_5
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