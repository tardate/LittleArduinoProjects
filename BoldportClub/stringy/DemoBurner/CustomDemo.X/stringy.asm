;***************************************************************************
; FILE:      stringy.asm                                                   *
; CONTENTS:  Guitar synthesiser using Karplus-Strong algorithm             *
; COPYRIGHT: MadLab Ltd. 2005, 2017                                        *
; AUTHOR:    James Hutchby                                                 *
; UPDATED:   19/04/17                                                      *
;***************************************************************************

	processor 12F1840

	include "p12f1840.inc"

	__config _CONFIG1, _FOSC_INTOSC&_WDTE_ON&_PWRTE_ON&_MCLRE_OFF&_CP_ON&_CPD_ON&_BOREN_ON&_CLKOUTEN_OFF&_IESO_OFF&_FCMEN_ON&h'3fff'
	__config _CONFIG2, _WRT_ALL&_PLLEN_ON&_STVREN_ON&_BORV_19&_LVP_OFF&h'3fff'

	errorlevel -207,-302,-305

	__idlocs h'EE21'


;***************************************************************************
;															*
; Specification												*
;															*
;***************************************************************************

; power-up self-test - LED flashes and beeps twice

; plays notes over 5 octaves, a single octave at a time
; pushbuttons shift octave up and down

; both pushbuttons pressed and released changes voice

; both pushbuttons held down for >1 second plays demo tune
; demo tune played in current voice

; sleeps after ~10 minutes of inactivity
; pushbutton or key to awaken


;***************************************************************************
;															*
; Port assignments												*
;															*
;***************************************************************************

PORTA_IO	equ	b'011011'		; PORTA status

LED		equ	5			; LED
SPEAKER	equ	2			; speaker output (P1A)
KEYBOARD	equ	1			; resistor ladder (AN1)

BUTTON1	equ	4			; pushbutton #1
BUTTON2	equ	3			; pushbutton #2

; *** RA0 (pin 7) is currently unused and is available for expansion ***


LED_on	macro
		movlb 2
		bsf LATA,LED
		movlb 0
		endm

LED_off	macro
		movlb 2
		bcf LATA,LED
		movlb 0
		endm


;***************************************************************************
;															*
; Constants and timings											*
;															*
;***************************************************************************

CLOCK		equ	d'8000000'*4	; processor clock frequency in Hz

TEST			equ	0			; true if test

POLL_PERIOD	equ	d'10'		; keyboard poll period in ms

LINE			equ	d'128'		; maximum delay line length

FACTOR		equ	d'128'		; filter factor *** adjust to change sound ***

DAMPING		equ	d'250'		; damping factor *** adjust to shorten or lengthen decay times ***

OCTAVES		equ	d'5'			; number of octaves
VOICES		equ	d'2'			; number of voices

DEMO_DELAY	equ	d'1250'		; demo delay in ms

DURATION		equ	d'150'		; note duration
REST			equ	d'150'		; rest duration


;***************************************************************************
;                                                                          *
; File register usage                                                      *
;                                                                          *
;***************************************************************************

	cblock h'20'			; bank 0
	keys					; keys pressed
	tune_note				; tune note
	tune_pnt            	; tune pointer
	tune_ret            	; tune return
	cur_voice				; current voice, 0 to VOICES-1
	cur_octave          	; current octave, 0 to (OCTAVES-1)*12
	repeat				; note repeat
	length				; delay line length
	samples				; samples count
	acc:2				; accumulator
	arg:2				; argument
	timer1:2				; timer1 period
	timer				; button timer
	timeout				; sleep timer
	rand:2				; random number
	line_:0				; delay line (split across banks)
	endc

; address in linear memory
line		equ	h'2000'+(line_-h'20')

	cblock h'70'			; common RAM
	flags               	; various flags
	loop, count			; loop counters
	temp					; work register
	work1, work2			; work registers
	endc

; flags
BLEND		equ	0		; set if waveform blended
RELEASE1		equ	1		; set if waiting for key release
RELEASE2		equ	2		; set if waiting for button release
BUTTONS		equ	3		; set if both buttons pressed


;***************************************************************************
;															*
; Macros														*
;															*
;***************************************************************************

routine	macro label			; routine
label
		endm

table	macro label			; lookup table
label	brw
		endm

entry     macro value              ; table entry
		retlw value
		endm

index     macro label              ; index table
		call label
		endm

jump      macro label              ; jump through table
		goto label
		endm

tstw		macro				; test w
		iorlw 0
		endm

movff     macro f1,f2              ; move file to file
		movfw f1
		movwf f2
		endm

movlf	macro n,f				; move literal to file
		movlw n
		movwf f
		endm

negw		macro				; negate w
		sublw 0
		endm


;---------------------------------------------------------------------------
; reset and interrupt vectors
;---------------------------------------------------------------------------

		org 0

		goto main_entry

		org 4

		goto isr


;***************************************************************************
;															*
; Lookup tables												*
;															*
;***************************************************************************

		table notes

note		macro len,tmr
		entry len
		entry high ((-tmr)&h'ffff')
		entry low ((-tmr)&h'ffff')
		endm

		note d'128',d'7645'		; C1
		note d'128',d'7215'		; C#1
		note d'128',d'6810'		; D1
		note d'128',d'6428'		; D#1
		note d'128',d'6067'		; E1
		note d'128',d'5727'		; F1
		note d'128',d'5405'		; F#1
		note d'128',d'5102'		; G1
		note d'128',d'4816'		; G#1
		note d'128',d'4545'		; A1
		note d'128',d'4290'		; A#1
		note d'128',d'4050'		; B1
		note d'128',d'3822'		; C2
		note d'128',d'3608'		; C#2
		note d'128',d'3405'		; D2
		note d'128',d'3214'		; D#2
		note d'128',d'3034'		; E2
		note d'128',d'2863'		; F2
		note d'128',d'2703'		; F#2
		note d'128',d'2551'		; G2
		note d'128',d'2408'		; G#2
		note d'128',d'2273'		; A2
		note d'128',d'2145'		; A#2
		note d'128',d'2025'		; B2
		note d'128',d'1911'		; C3
		note d'128',d'1804'		; C#3
		note d'128',d'1703'		; D3
		note d'128',d'1607'		; D#3
		note d'128',d'1517'		; E3
		note d'128',d'1432'		; F3
		note d'128',d'1351'		; F#3
		note d'128',d'1276'		; G3
		note d'128',d'1204'		; G#3
		note d'128',d'1136'		; A3
		note d'128',d'1073'		; A#3
		note d'126',d'1028'		; B3
		note d'119',d'1028'		; C4
		note d'112',d'1031'		; C#4
		note d'106',d'1028'		; D4
		note d'100',d'1029'		; D#4
		note d'94',d'1033'		; E4
		note d'89',d'1030'		; F4
		note d'84',d'1030'		; F#4
		note d'79',d'1033'		; G4
		note d'75',d'1027'		; G#4
		note d'71',d'1024'		; A4
		note d'67',d'1025'		; A#4
		note d'63',d'1028'		; B4
		note d'59',d'1037'		; C5
		note d'56',d'1031'		; C#5
		note d'53',d'1028'		; D5
		note d'50',d'1029'		; D#5
		note d'47',d'1033'		; E5
		note d'44',d'1041'		; F5
		note d'42',d'1030'		; F#5
		note d'39',d'1047'		; G5
		note d'37',d'1041'		; G#5
		note d'35',d'1039'		; A5
		note d'33',d'1040'		; A#5
		note d'31',d'1045'		; B5


		if TEST

		table sine

		entry d'0'
		entry d'0'
		entry d'1'
		entry d'1'
		entry d'2'
		entry d'4'
		entry d'5'
		entry d'7'
		entry d'10'
		entry d'12'
		entry d'15'
		entry d'18'
		entry d'21'
		entry d'25'
		entry d'29'
		entry d'33'
		entry d'37'
		entry d'42'
		entry d'46'
		entry d'51'
		entry d'56'
		entry d'62'
		entry d'67'
		entry d'73'
		entry d'78'
		entry d'84'
		entry d'90'
		entry d'96'
		entry d'102'
		entry d'108'
		entry d'115'
		entry d'121'
		entry d'127'
		entry d'133'
		entry d'139'
		entry d'146'
		entry d'152'
		entry d'158'
		entry d'164'
		entry d'170'
		entry d'176'
		entry d'181'
		entry d'187'
		entry d'192'
		entry d'198'
		entry d'203'
		entry d'208'
		entry d'212'
		entry d'217'
		entry d'221'
		entry d'225'
		entry d'229'
		entry d'233'
		entry d'236'
		entry d'239'
		entry d'242'
		entry d'244'
		entry d'247'
		entry d'249'
		entry d'250'
		entry d'252'
		entry d'253'
		entry d'253'
		entry d'254'
		entry d'254'
		entry d'254'
		entry d'253'
		entry d'253'
		entry d'252'
		entry d'250'
		entry d'249'
		entry d'247'
		entry d'244'
		entry d'242'
		entry d'239'
		entry d'236'
		entry d'233'
		entry d'229'
		entry d'225'
		entry d'221'
		entry d'217'
		entry d'212'
		entry d'208'
		entry d'203'
		entry d'198'
		entry d'192'
		entry d'187'
		entry d'181'
		entry d'176'
		entry d'170'
		entry d'164'
		entry d'158'
		entry d'152'
		entry d'146'
		entry d'139'
		entry d'133'
		entry d'127'
		entry d'121'
		entry d'115'
		entry d'108'
		entry d'102'
		entry d'96'
		entry d'90'
		entry d'84'
		entry d'78'
		entry d'73'
		entry d'67'
		entry d'62'
		entry d'56'
		entry d'51'
		entry d'46'
		entry d'42'
		entry d'37'
		entry d'33'
		entry d'29'
		entry d'25'
		entry d'21'
		entry d'18'
		entry d'15'
		entry d'12'
		entry d'10'
		entry d'7'
		entry d'5'
		entry d'4'
		entry d'2'
		entry d'1'
		entry d'1'
		entry d'0'

		endif


		table thresholds

		entry d'245'
		entry d'224'
		entry d'203'
		entry d'181'
		entry d'160'
		entry d'139'
		entry d'117'
		entry d'96'
		entry d'75'
		entry d'53'
		entry d'32'
		entry d'11'
		entry 0


		table voices

		entry 0				; acoustic guitar
		entry 1				; electric guitar


		table tune_esc

		goto tesc00			; end of tune or sub-tune
		goto tesc01			; play sub-tune
		goto tesc10			; long rest
		goto tesc11			; octave shift


;---------------------------------------------------------------------------
; Tune definitions
;---------------------------------------------------------------------------

; rrttnnnn = note:
;       rr = rest duration (00 = none ... 11 = max)
;       tt = tone duration (00 = min ... 11 = max)
;     nnnn = tone value (0001 = C ... 1111 = D')
; xxxx0000 = escape:
; xx000000 = end of tune or sub-tune
; xx010000 = play sub-tune (followed by address)
; rr100000 = long rest (00 = min ... 11 = max)
; xo110000 = octave shift (0 = -1, 1 = +1)

		cblock 1
		C1, C1S
		D1, D1S
		E1
		F1, F1S
		G1, G1S
		A1, A1S
		B1
		C2, C2S
		D2
		endc

tstart	macro label				; start of tune or sub-tune
label	equ	$&h'ff'
		endm

tnote	macro n,t,r				; note
		dw (r<<6)+((t-1)<<4)+n
		endm

tstop	macro					; end of tune or sub-tune
		dw b'000000'
		endm

ttune	macro address				; play sub-tune
		dw b'010000'
		dw address&h'ff'
		endm

trest	macro r					; long rest
		dw ((r-1)<<6)+b'100000'
		endm

toctave	macro o					; octave shift
		if o==-1
		dw (0<<6)+b'110000'
		endif
		if o==+1
		dw (1<<6)+b'110000'
		endif
		endm


;***************************************************************************
;                                                                          *
; Procedures                                                               *
;                                                                          *
;***************************************************************************

;---------------------------------------------------------------------------
; delay
;---------------------------------------------------------------------------

delay64	goto $+1						; [8]
		goto $+1						; [8]
		goto $+1						; [8]
		goto $+1						; [8]
		goto $+1						; [8]
		goto $+1						; [8]
delay16   return						; [8]

delay     macro cycles					; delay for a number of cycles

		if (cycles) < 0
		error "Delay cycles negative"
		endif

		variable i = cycles

		while i > d'64'
		call delay64					; [64]
		i -= d'64'
		endw

		if i >= d'16'
		variable n = (i-d'16')/d'8'
		call delay16-n					; [8+8n+8]
		i -= (n*d'8')+d'16'
		endif

		while i >= d'4'
		nop							; [4]
		i -= d'4'
		endw

		if i != 0
		error "Delay cycles not multiple of 4"
		endif

		endm


;---------------------------------------------------------------------------
; multiply w by 8-bit constant
;---------------------------------------------------------------------------

mult		macro c

		clrf arg+0
		movwf arg+1

		variable n = 0
		while n <= 7

		if ((c)&(1<<n)) != 0
		movfw arg+1
		addwf acc+1
		movfw arg+0
		addwfc acc+0
		endif

		if n != 7
		lslf arg+1
		rlf arg+0
		endif

		n += 1
		endw

		endm


;---------------------------------------------------------------------------
; interrupt service routine
;---------------------------------------------------------------------------

		routine isr

		movlb 0

		movff timer1+0,TMR1H			; reload timer
		movff timer1+1,TMR1L

		movff FSR0H,FSR1H
		movff FSR0L,FSR1L

		moviw FSR0++					; next sample

		movlb 5						; duty cycle
		bcf CCP1CON,DC1B1
		bcf CCP1CON,DC1B0
;		lsrf WREG						; *** uncomment these lines to ***
;		skpnc						; *** increase output volume ***
;		bsf CCP1CON,DC1B1
		movwf CCPR1L
		movlb 0

		decf samples					; end of delay line ?
		bnz isr1						; branch if not

		movlf high line,FSR0H			; wrap pointer
		movlf low line,FSR0L
		movff length,samples

isr1
		if !TEST

		clrf acc+0					; low-pass filter + damping
		clrf acc+1
		movfw INDF0
		mult (FACTOR*DAMPING)/d'256'
		movfw INDF1
		mult ((d'256'-FACTOR)*DAMPING)/d'256'

		btfss flags,BLEND
		bra isr2

		call get_random
		andlw b'11'					; *** b'1' can also be used ***
		bnz isr3

isr2		movff acc+0,INDF1

isr3
		endif

		movlb d'31'
		movff FSR0H,FSR0H_SHAD
		movff FSR0L,FSR0L_SHAD
		movlb 0

		bcf PIR1,TMR1IF

		retfie


;---------------------------------------------------------------------------
; waits, fed with the wait in ms in wreg
;---------------------------------------------------------------------------

		routine long_wait

		clrw

		routine wait_ms

		movwf work1

WAIT		equ	((CLOCK/4)/d'256')/d'1000'

wait1	movlf WAIT,work2

wait2	bcf PIR1,TMR2IF

wait3	clrwdt
		btfss PIR1,TMR2IF
		bra wait3

		decfsz work2
		bra wait2

		decfsz work1
		bra wait1

		return


;---------------------------------------------------------------------------
; polls the pushbuttons, returns the buttons state in w with the NZ flag
; set if either pushbutton pressed
;---------------------------------------------------------------------------

		routine poll_buttons

		clrw
		btfss PORTA,BUTTON1
		iorlw 1<<0
		btfss PORTA,BUTTON2
		iorlw 1<<1

		return


;---------------------------------------------------------------------------
; beeps
;---------------------------------------------------------------------------

BEEP_PITCH	equ  d'250'		; beep pitch
BEEP_PERIOD	equ  d'250'		; beep period

		routine beep

		movlf BEEP_PERIOD,work1

beep1	movlb 2						; toggle speaker output
		bsf LATA,SPEAKER
		movlb 0

		movlf BEEP_PITCH,work2       		; half-cycle delay
beep2     clrwdt
		nop
		nop
		nop
		nop
		nop
		nop
		decfsz work2
		bra beep2

		movlb 2						; toggle speaker output
		bcf LATA,SPEAKER
		movlb 0

		movlf BEEP_PITCH,work2       		; half-cycle delay
beep3     clrwdt
		nop
		nop
		nop
		nop
		nop
		nop
		decfsz work2
		bra beep3

		decfsz work1
		bra beep1

		return


;---------------------------------------------------------------------------
; reads from program memory, fed with the address offset in w, returns
; the byte in w
;---------------------------------------------------------------------------

		routine read_mem

		movlb 3

		movwf EEADRL					; address
		movlf high demo,EEADRH

		bcf EECON1,CFGS				; program memory
		bsf EECON1,EEPGD

		bsf EECON1,RD					; read byte
		nop
		nop
		movfw EEDATL

		movlb 0

		return


;---------------------------------------------------------------------------
; returns a pseudo random number in w
;---------------------------------------------------------------------------

		routine get_random

		movfw rand+0
		iorwf rand+1,w
		bnz rand1

		movfw TMR0					; seed generator
		movwf rand+0
		xorlw h'ff'
		movwf rand+1

rand1	rlf rand+0,w					; calculate next in sequence
		xorwf rand+0,w
		movwf temp					; msb <= Q15 ^ Q14
		swapf rand+1,w
		btfsc rand+0,4
		xorlw h'80'					; msb <= Q12 ^ Q3
		xorwf temp
		rlf temp
		rlf rand+1
		rlf rand+0					; << 1 + (Q15 ^ Q14 ^ Q12 ^ Q3)

		movfw rand+1					; random number

		return


;---------------------------------------------------------------------------
; returns the key pressed in w (1 to 12) or 0 if none, with the NZ flag
; set if any key pressed
;---------------------------------------------------------------------------

		routine poll_keyboard

		movlb 1
pollk1	clrwdt
		btfsc ADCON0,GO
		bra pollk1
		movff ADRESH,work1
		bsf ADCON0,GO
		movlb 0

		clrf work2
pollk2	movfw work2
		index thresholds
		subwf work1,w
		bc pollk3
		incf work2
		bra pollk2

pollk3	incf work2
		movlw d'13'
		subwf work2,w
		skpnz
		clrf work2

		movfw work2

		return


;---------------------------------------------------------------------------
; initialises the delay line with random samples
;---------------------------------------------------------------------------

		routine init_line

		movlf high line,FSR0H
		movlf low line,FSR0L
		movff length,samples

		if TEST

		movlf LINE,samples
initl1	movfw samples
		sublw LINE
		index sine
		movwi FSR0++
		decfsz samples
		bra initl1

		else

initl2	call get_random				; random waveform
		movwi FSR0++
		decfsz samples
		bra initl2

		endif

		return


;---------------------------------------------------------------------------
; plays a note in the current octave, fed with the note in w (0 - 11)
;---------------------------------------------------------------------------

		routine play_note

		call stop_note

		LED_off

		addwf cur_octave,w				; add current octave

		movwf work1
		addwf work1
		addwf work1					; * 3

		movfw work1
		index notes
		movwf length

		incf work1
		movfw work1
		index notes
		movwf timer1+0

		incf work1,w
		index notes
		movwf timer1+1

		movfw cur_voice				; select voice
		index voices
		tstw
		bcf flags,BLEND
		skpz
		bsf flags,BLEND

		call init_line

		LED_on

		movlf high line,FSR0H
		movlf low line,FSR0L
		movff length,samples

		movff timer1+0,TMR1H
		movff timer1+1,TMR1L

		movlb 5						; PWM output
		clrf CCPR1L
		clrf CCP1AS
		movlf b'00001100',CCP1CON
		movlb 0

		bcf PIR1,TMR1IF
		movlb 1
		bsf PIE1,TMR1IE
		movlb 0

		bsf INTCON,PEIE				; enable interrupts
		bsf INTCON,GIE

		clrf TMR2

		bsf T1CON,TMR1ON				; Timer1 on

		return


;---------------------------------------------------------------------------
; stops the note playing
;---------------------------------------------------------------------------

		routine stop_note

		bcf INTCON,GIE					; disable interrupts

		movlb 5						; PWM off
		clrf CCP1CON
		movlb 0

		bcf T1CON,TMR1ON				; Timer1 off

		return


;---------------------------------------------------------------------------
; plays the demo tune
;---------------------------------------------------------------------------

		routine play_tune

		movlf d'1'*d'12',cur_octave		; initial octave

		movlw 0
playt1	movwf tune_pnt

		clrf tune_ret

playt2	call poll_buttons				; exit if pushbutton pressed
		btfss flags,RELEASE2
		bra playt3
		skpnz
		bcf flags,RELEASE2
		clrw
playt3	bnz texit

		movfw tune_pnt					; get the next note in the tune
		call read_mem
		movwf tune_note
		incf tune_pnt

		andlw b'1111'					; escape ?
		bz playt8						; branch if yes

		clrf repeat

playt4	swapf tune_note,w
		andlw b'11'
		addwf repeat
		incf repeat

		movfw tune_note				; extended note ?
		andlw b'11110000'
		xorlw b'00110000'
		bnz playt5
		movfw tune_pnt
		call read_mem
		movwf work1
		xorwf tune_note,w
		andlw b'1111'
		bnz playt5					; branch if not

		movff work1,tune_note
		incf tune_pnt

		bra playt4

playt5	decf tune_note,w				; play the tune note
		andlw b'1111'
		call play_note

playt6	movlw DURATION
		call wait_ms
		decfsz repeat
		bra playt6

		call stop_note

		LED_off

		swapf tune_note				; xxxxrrtt
		rrf tune_note
		rrf tune_note
		movlw b'11'
		andwf tune_note

playt7	tstf tune_note
		bz playt2

		movlw REST					; rest
		call wait_ms

		decf tune_note
		bra playt7

playt8	swapf tune_note				; interpret the escape code
		movfw tune_note
		rrf tune_note
		rrf tune_note
		andlw b'11'
		jump tune_esc

tesc00    movfw tune_ret					; get the return address

		tstw							; end of tune ?
		bnz playt1					; branch if not

texit	bsf flags,RELEASE2

		goto main_loop

tesc01    incf tune_pnt,w				; save the return address
		movwf tune_ret

		movfw tune_pnt					; get the sub-tune address
		call read_mem
		movwf tune_pnt

		bra playt2

tesc10    movlw b'11'					; get the rest duration
		andwf tune_note
		incf tune_note					; 1,2,3,4

		bra playt7

tesc11	movfw cur_octave				; determine the new octave
		btfsc tune_note,0
		addlw d'12'
		btfss tune_note,0
		addlw -d'12'
		movwf cur_octave

		bra playt2


;---------------------------------------------------------------------------
; initialises the hardware
;---------------------------------------------------------------------------

		routine init_hardware

		movlb 0						; bank 0

		movlp 0						; page 0

		movlb 2						; initialise port
		clrf LATA
		movlb 1
		movlf PORTA_IO,TRISA
		movlb 0

		movlb 1						; weak pull-ups enabled,
		movlf b'00001000',OPTION_REG		; Timer0 internal clock
		movlb 0

		movlb 4
		movlf (1<<BUTTON1)|(1<<BUTTON2),WPUA
		movlb 0

		movlb 1						; 32MHz
		movlf b'01110000',OSCCON
		clrf OSCTUNE
		movlb 0

		clrf INTCON					; disable interrupts
		movlb 1
		clrf PIE1
		clrf PIE2
		movlb 0
		clrf PIR1
		clrf PIR2

		movlb 1						; watchdog timer - 1s
		movlf b'01010'<<1,WDTCON
		movlb 0

		movlb 2						; SR latch off
		clrf SRCON0
		clrf SRCON1
		movlb 0

		movlb 2						; comparator off
		clrf CM1CON0
		movlb 0

		movlb 2						; voltage reference off
		clrf FVRCON
		movlb 0

		movlb 5						; PWM off
		clrf CCP1CON
		clrf CCPR1L
		clrf CCP1AS
		movlb 0

		movlb 7						; interrupt-on-change
		clrf IOCAP
		movlf (1<<BUTTON1)|(1<<BUTTON2),IOCAN
		clrf IOCAF
		movlb 0

		movlb 3						; UART off
		clrf TXSTA
		clrf RCSTA
		movlb 0

		movlb 4						; SPI off
		clrf SSP1STAT
		clrf SSP1CON1
		clrf SSP1CON2
		clrf SSP1CON3
		movlb 0

		movlb 1
		movlf b'00000101',ADCON0			; AN1, ADC on
		movlf b'01110000',ADCON1			; left justified, Frc, Vdd
		bsf ADCON0,GO
		movlb 0

		movlb 3						; analogue
		movlf 1<<KEYBOARD,ANSELA
		movlb 0

		movlb 2						; DAC off
		clrf DACCON0
		movlb 0

		movlb 7						; reference clock off
		clrf CLKRCON
		movlb 0

		clrf CPSCON0					; capsense off
		clrf CPSCON1

		movlb 7						; modulation control off
		clrf MDCON
		movlb 0

		movlf b'01000000',T1CON			; Timer1 - system clock, no prescale
		clrf T1GCON

		movlf b'0000000',T2CON			; Timer2 - no prescale
		movlf h'ff',PR2				; PWM period
		clrf TMR2
		bsf T2CON,TMR2ON				; Timer2 on

MAX_SAMPLE_RATE	equ	(CLOCK/4)/d'256'

		return


;---------------------------------------------------------------------------
; main entry point
;---------------------------------------------------------------------------

		routine main_entry

		movfw STATUS					; wake-up from sleep ?
		andlw (1<<NOT_TO)|(1<<NOT_PD)
		clrwdt
		bz main2						; branch if yes

		call init_hardware

		clrf flags					; clear flags

		clrf rand+0
		clrf rand+1

		LED_on						; double flash and beep
		call beep
		LED_off
		call long_wait
		LED_on
		call beep
		LED_off
		call long_wait

		clrf cur_voice					; initial voice
		movlf d'2'*d'12',cur_octave		; initial octave

		clrf keys

		bsf flags,RELEASE1
		bsf flags,RELEASE2
		bcf flags,BUTTONS

		if TEST
		movlw d'0'
		call play_note
main1	clrwdt
		bra main1
		endif

		goto main_loop

main2	call poll_buttons				; pushbutton or key pressed ?
		skpz
		goto main_loop
		call poll_keyboard
		skpz
		goto main_loop					; branch if yes


;---------------------------------------------------------------------------
; sleep state
;---------------------------------------------------------------------------

		routine sleep_state

		movlb 2						; LED and sound off
		clrf LATA
		movlb 0

		movlb 7
		clrf IOCAF
		movlb 0

		bcf INTCON,GIE
		bcf INTCON,IOCIF
		bsf INTCON,IOCIE

		clrwdt

		sleep						; standby mode
		nop

OSCMASK	equ	(1<<PLLR)|(1<<HFIOFR)|(1<<HFIOFL)|(1<<HFIOFS)

		movlb 1						; wait until internal oscillator
sleep1	clrwdt						; ready, locked and stable
		movfw OSCSTAT
		andlw OSCMASK
		xorlw OSCMASK
		bnz sleep1
		movlb 0

		goto main_entry


;---------------------------------------------------------------------------
; pushbuttons executive
;---------------------------------------------------------------------------

		routine do_buttons

		call poll_buttons				; poll the pushbuttons

		bnz dob1

		LED_off

dob1		btfss flags,RELEASE2			; waiting for release ?
		bra dob3						; branch if not

		bz dob2						; branch if released

		LED_on

		xorlw b'11'					; both pushbuttons pressed ?
		bnz dob7						; branch if not

		movlw DEMO_DELAY/POLL_PERIOD		; both pushbuttons held down ?
		subwf timer,w
		bnc dob7						; branch if not

		bcf flags,BUTTONS

		goto play_tune					; play demo tune

dob2		bcf flags,RELEASE2

		btfss flags,BUTTONS
		bra dob7

		incf cur_voice,w				; next voice
		xorlw VOICES
		skpz
		xorlw VOICES
		movwf cur_voice

		bcf flags,BUTTONS

		movlw d'75'					; double flash
		call wait_ms
		LED_off
		movlw d'100'
		call wait_ms
		LED_on
		movlw d'100'
		call wait_ms
		LED_off

		bra dob7

dob3		bz dob7						; branch if no pushbutton pressed

		movlw POLL_PERIOD*4
		call wait_ms

		call poll_buttons				; poll the pushbuttons again

		bz dob7						; branch if no pushbutton pressed

		LED_on

		xorlw b'11'					; both pushbuttons pressed ?
		skpnz
		bsf flags,BUTTONS
		bz dob6						; branch if yes

		andlw 1<<0					; octave change
		bz dob4
		movfw cur_octave				; octave +
		addlw d'12'
		xorlw OCTAVES*d'12'
		bz dob6
		xorlw OCTAVES*d'12'
		bra dob5
dob4		movfw cur_octave				; octave -
		addlw -d'12'
		bnc dob6
dob5		movwf cur_octave

dob6		clrf timer					; reset timers
		clrf timeout

		bsf flags,RELEASE2				; signal waiting for release

dob7		return


;---------------------------------------------------------------------------
; main loop
;---------------------------------------------------------------------------

		routine main_loop

		clrwdt

		clrf timer					; reset timers
		clrf timeout

loop1	movlw POLL_PERIOD
		call wait_ms

		incf timer
		bnz loop2

		incf timeout					; sleep if timeout
		skpnz
		goto sleep_state

loop2	call do_buttons				; pushbuttons

		call poll_keyboard				; poll the keyboard

		swapf keys					; store key pressed
		xorwf keys,w
		andlw h'0f'
		xorwf keys

		movfw keys
		andlw h'0f'

		btfss flags,RELEASE1			; waiting for release ?
		bra loop3						; branch if not

		skpnz
		bcf flags,RELEASE1
		swapf keys,w
		xorwf keys,w
		skpz
		bcf flags,RELEASE1

		bra loop1

loop3	bz loop1						; debounce keyboard
		swapf keys,w
		xorwf keys,w
		bnz loop1

		decf keys,w					; play a note
		andlw h'0f'
		call play_note

		bsf flags,RELEASE1

		goto main_loop


;***************************************************************************
;															*
; Demo tune										    		     *
;															*
;***************************************************************************

		org (($-1)|h'ff')+1				; 256-byte boundary

demo
		include "demo.tun"


		end
