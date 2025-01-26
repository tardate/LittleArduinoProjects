CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
GDB=arm-none-eabi-gdb
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -g -O0
LDFLAGS= -T stm32_ls.ld -nostdlib -Wl,-Map=blinky.map

all: blinky.bin

blinky.bin: blinky.elf
	$(OBJCOPY) -O binary $^ $@

blinky.elf: blinky.o delay.o led.o stm32_startup.o
	$(CC) $(LDFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm *.o *.elf

.PHONY: gdb
gdb: blinky.elf
	$(GDB) blinky.elf

flash: blinky.elf
	$(GDB) -nx --batch -ex 'target extended-remote $(BMP_PORT)' -x flash.scr $^
