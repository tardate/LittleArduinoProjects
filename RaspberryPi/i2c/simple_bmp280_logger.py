#!/usr/bin/env python3
import sys
import smbus
import time

DEFAULT_BUS = 1
DEFAULT_ADDRESS = 0x76  # or 0x77

# Registers
REG_CHIP_ID   = 0xD0
REG_RESET     = 0xE0
REG_CALIB00   = 0x88
REG_CTRL_MEAS = 0xF4
REG_CONFIG    = 0xF5
REG_DATA      = 0xF7

BMP280_CHIP_IDS = [0x56, 0x57, 0x58]

def u16(lsb, msb):
    return (msb << 8) | lsb

def s16(lsb, msb):
    result = u16(lsb, msb)
    if result > 32767:
        result -= 65536
    return result


class BMP280:
    def __init__(self, address=DEFAULT_ADDRESS, bus=DEFAULT_BUS):
        self.bus = smbus.SMBus(bus)
        self.address = address

        self.check_chip_id()
        self.reset()
        self.setup()

    def check_chip_id(self):
        chip_id = self.bus.read_byte_data(self.address, REG_CHIP_ID)
        if chip_id not in BMP280_CHIP_IDS:
            raise ValueError(f"Invalid BMP280 chip ID: 0x{chip_id:02X}")
        return True

    def reset(self):
        self.bus.write_byte_data(self.address, REG_RESET, 0xB6)
        time.sleep(0.002)

    def setup(self):
        # Read calibration block (24 bytes for BMP280)
        calib = self.bus.read_i2c_block_data(self.address, REG_CALIB00, 24)

        # Temperature calibration
        self.dig_T1 = u16(calib[0], calib[1])
        self.dig_T2 = s16(calib[2], calib[3])
        self.dig_T3 = s16(calib[4], calib[5])

        # Pressure calibration
        self.dig_P1 = u16(calib[6], calib[7])
        self.dig_P2 = s16(calib[8], calib[9])
        self.dig_P3 = s16(calib[10], calib[11])
        self.dig_P4 = s16(calib[12], calib[13])
        self.dig_P5 = s16(calib[14], calib[15])
        self.dig_P6 = s16(calib[16], calib[17])
        self.dig_P7 = s16(calib[18], calib[19])
        self.dig_P8 = s16(calib[20], calib[21])
        self.dig_P9 = s16(calib[22], calib[23])

        # Configure sensor
        # Temp oversampling x1, Pressure oversampling x1, Normal mode
        self.bus.write_byte_data(self.address, REG_CTRL_MEAS, 0x27)

        # Standby 1000ms, filter off
        self.bus.write_byte_data(self.address, REG_CONFIG, 0xA0)

    def read_values(self):
        data = self.bus.read_i2c_block_data(self.address, REG_DATA, 6)

        adc_p = (data[0] << 12) | (data[1] << 4) | (data[2] >> 4)
        adc_t = (data[3] << 12) | (data[4] << 4) | (data[5] >> 4)

        # Temperature compensation
        var1 = (adc_t / 16384.0 - self.dig_T1 / 1024.0) * self.dig_T2
        var2 = ((adc_t / 131072.0 - self.dig_T1 / 8192.0) ** 2) * self.dig_T3
        self.t_fine = var1 + var2
        temperature = self.t_fine / 5120.0

        # Pressure compensation
        var1 = self.t_fine / 2.0 - 64000.0
        var2 = var1 * var1 * self.dig_P6 / 32768.0
        var2 = var2 + var1 * self.dig_P5 * 2.0
        var2 = var2 / 4.0 + self.dig_P4 * 65536.0
        var1 = (self.dig_P3 * var1 * var1 / 524288.0 + self.dig_P2 * var1) / 524288.0
        var1 = (1.0 + var1 / 32768.0) * self.dig_P1

        if var1 == 0:
            pressure = 0
        else:
            pressure = 1048576.0 - adc_p
            pressure = (pressure - var2 / 4096.0) * 6250.0 / var1
            var1 = self.dig_P9 * pressure * pressure / 2147483648.0
            var2 = pressure * self.dig_P8 / 32768.0
            pressure = pressure + (var1 + var2 + self.dig_P7) / 16.0

        pressure = pressure / 100.0  # Convert to hPa

        return temperature, pressure

    def close(self):
        self.bus.close()


def main():
    if len(sys.argv) > 1:
        try:
            address = int(sys.argv[1], 16)
        except ValueError:
            address = DEFAULT_ADDRESS
    else:
        address = DEFAULT_ADDRESS

    try:
        bmp = BMP280(address)

        print("| Temperature | Pressure    |")
        print("|-------------|-------------|")

        while True:
            temp, press = bmp.read_values()
            print(f"|    {temp:.2f} °C | {press:.2f} hPa |")
            time.sleep(2)

    except KeyboardInterrupt:
        print("")

    except Exception as e:
        print(f"Error: {e}")
        sys.exit(1)

    finally:
        try:
            bmp.close()
        except:
            pass


if __name__ == "__main__":
    main()
