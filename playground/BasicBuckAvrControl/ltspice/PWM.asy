Version 4
SymbolType CELL
RECTANGLE Normal 64 49 -64 -48
TEXT 0 -33 Center 2 PWM
WINDOW 0 -65 -65 Left 2
WINDOW 39 -1 63 Center 2
SYMATTR SpiceLine VM=1V, fs=100kHz
SYMATTR Prefix X
SYMATTR Value PWM
SYMATTR SpiceLine2 Dmin=0.05, Dmax=0.9, Voffset=0
SYMATTR Description Trailing-edge pulse-width modulator
PIN -64 0 LEFT 8
PINATTR PinName vc
PINATTR SpiceOrder 1
PIN 64 0 RIGHT 8
PINATTR PinName c
PINATTR SpiceOrder 2
