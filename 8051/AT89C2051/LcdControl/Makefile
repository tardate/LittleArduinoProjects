.PRECIOUS: %.ihx

all: LcdControl.hex

%.hex: %.ihx
	packihx $< > $@

%.ihx: %.c
	sdcc -mmcs51 --code-size 2048 $< -o $@

clean:
		rm -rf *.hex *.ihx *.lk *.lst *.map *.mem *.rel *.rst *.sym *.asm
