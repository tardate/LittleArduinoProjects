import time
import onewire
import ds18x20
from machine import Pin

pin = Pin(2)
ow = onewire.OneWire(pin)
ds = ds18x20.DS18X20(ow)
roms = ds.scan()

def read_temps(ds, roms):
    while True:
        ds.convert_temp()
        time.sleep(1)
        for rom in roms:
            addr = ''.join('{:02x}'.format(b) for b in rom)
            temp = ds.read_temp(rom)
            print(addr, temp)
