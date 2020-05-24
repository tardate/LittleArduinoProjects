CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy

MACH=cortex-m3
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

.PHONY: flash
flash: all
	st-flash write blinky.bin 0x08000000

.PHONY: reset
reset:
	st-flash reset

.PHONY: debughost
debughost:
	st-util

.PHONY: gdb
gdb: blinky.elf
	arm-none-eabi-gdb blinky.elf
