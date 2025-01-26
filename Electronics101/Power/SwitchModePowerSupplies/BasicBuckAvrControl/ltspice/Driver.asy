Version 4
SymbolType CELL
LINE Normal 80 0 -48 -64
LINE Normal -48 64 -48 -64
LINE Normal 80 0 -48 64
LINE Normal -48 -32 -64 -32
LINE Normal -48 32 -64 32
LINE Normal 16 -32 16 -80
LINE Normal 16 32 16 80
LINE Normal 96 0 80 0
RECTANGLE Normal 96 80 -64 -80
TEXT 0 0 Center 2 Driver
TEXT -42 -32 Left 2 c
WINDOW 0 -8 -52 Bottom 2
WINDOW 39 40 33 Left 2
SYMATTR SpiceLine Imax=3A
SYMATTR Prefix X
SYMATTR Value driver
SYMATTR Description Gate driver
SYMATTR SpiceLine2 Tdelay=30ns, IQ=1mA, Vuvl=9V
PIN -64 -32 NONE 8
PINATTR PinName c
PINATTR SpiceOrder 1
PIN 16 -80 NONE 8
PINATTR PinName Vdd
PINATTR SpiceOrder 2
PIN 16 80 NONE 8
PINATTR PinName Vss
PINATTR SpiceOrder 3
PIN -64 32 NONE 8
PINATTR PinName Vssin
PINATTR SpiceOrder 4
PIN 96 0 NONE 8
PINATTR PinName out
PINATTR SpiceOrder 5
