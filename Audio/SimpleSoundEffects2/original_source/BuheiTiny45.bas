'BUhei2 Tiny45
'Frequenzerzeugung
$regfile = "attiny45.dat"
$crystal = 8000000

'Pin B.0 wird Ausgang:
Ddrb = &B00010000
'Alles aus:
Portb.4 = 0

Dim Preload As Byte
Dim F As Word
Dim Fg As Word
Dim Fd As Word
Dim Tmax As Single
Dim Tclk As Single
Dim H As Single

On Timer0 Oszillator
Config Timer0 = Timer , Prescale = 256
Enable Timer0
Enable Interrupts
Preload = &H64:                                             '100 Hz
Timer0 = Preload

Config Adc = Single , Prescaler = Auto , Reference = Avcc
Start Adc

'------------------------------------------------------------------------------
'Init
Tclk = 256 / 8000000
Tmax = 256 * Tclk
Fg = 100
Fd = 100
'------------------------------------------------------------------------------
'Hauptprogramm
'F=200-4000
Do
   Fg = Getadc(1)
   H = Fg + 100
   Fg = Fg + H
   Fg = Fg + H
   F = Fg + Fd
   H = 2 * F
   H = 1 / H
   H = Tmax - H
   H = H / Tclk
   Preload = Int(h)
   H = Preload * Tclk
   H = Tmax - H
   H = 0.5 / H
   F = Int(h)

Loop
End
'------------------------------------------------------------------------------
Oszillator:
   Timer0 = Preload
   Portb.4 = Not Portb.4
   Incr Fd
   If Fd > 1000 Then Fd = 100
Return
'------------------------------------------------------------------------------