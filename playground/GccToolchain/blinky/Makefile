#
#

# make the .o and .elf files hang around
.PRECIOUS: %.elf %.o

all: blinky.hex

%.o: %.c
	avr-gcc -w -Os -Wl,--gc-sections -DF_CPU=16000000UL -mmcu=atmega328p -c $<

%.elf: %.o
	avr-gcc -mmcu=atmega328p -Wl,-Map,$*.map $< -o $@

%.hex: %.elf
	avr-objcopy -j .text -j .data -O ihex $< $@
	avr-objdump -h -S $< > $*.lst

flash: blinky.hex
	avrdude -D -v -c arduino -p atmega328p -P /dev/cu.usbmodem14541 -b 115200 -U flash:w:$<:i

clean:
	rm *.o
	rm *.elf
	rm *.hex
	rm *.map
	rm *.lst
