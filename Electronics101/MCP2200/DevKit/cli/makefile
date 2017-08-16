OBJECTS=common.c
CFLAGS=`pkg-config --cflags hidapi` -g -Wall -O3
LDLIBS=`pkg-config --libs hidapi`
CC=gcc

all: device_info enable_leds disable_leds
device_info: $(OBJECTS)
enable_leds: $(OBJECTS)
disable_leds: $(OBJECTS)
