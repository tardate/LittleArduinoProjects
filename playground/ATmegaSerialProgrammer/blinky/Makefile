#
# for flash operation, set the PORT environment variable with the correct port to use for the USB-Serial adapter
# e.g.
#   export PORT=/dev/cu.wchusbserial14230
#   make flash
# or inline:
#   make flash PORT=/dev/cu.wchusbserial14230

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
	avrdude -v -D -c arduino -p atmega328p -P ${PORT} -b 115200 -U flash:w:$<:i

clean:
	rm *.o
	rm *.elf
	rm *.hex
	rm *.map
	rm *.lst
