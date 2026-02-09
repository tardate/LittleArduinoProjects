#!/usr/bin/env python3
import sys
import smbus
import time

# I2C setup
DEFAULT_BUS = 1
DEFAULT_ADDRESS = 0x76

# Registers
REG_CHIP_ID = 0xD0
REG_CALIB00 = 0x88
REG_CALIB26 = 0xE1
REG_CTRL_HUM = 0xF2
REG_CTRL_MEAS = 0xF4
REG_CONFIG = 0xF5
REG_DATA = 0xF7

BME280_CHIP_ID = 0x60

# Helper functions
def u16(lsb, msb):
    return (msb << 8) | lsb

def s16(lsb, msb):
    result = u16(lsb, msb)
    if result > 32767:
        result -= 65536
    return result


class BME280:
    def __init__(self, address=DEFAULT_ADDRESS, bus=DEFAULT_BUS):
        self.bus = smbus.SMBus(bus)
        self.address = address
        self.check_chip_id()
        self.setup()

    def close(self):
        self.bus.close()

    def check_chip_id(self):
        """Load chip ID and verify"""
        chip_id = self.bus.read_byte_data(self.address, REG_CHIP_ID)
        if chip_id != BME280_CHIP_ID:
            raise ValueError(f"Invalid BME280 chip ID: 0x{chip_id:02X}")
        return True

    def setup(self):
        """Initialise the device"""
        # Read calibration data
        calib1 = self.bus.read_i2c_block_data(self.address, REG_CALIB00, 26)
        calib2 = self.bus.read_i2c_block_data(self.address, REG_CALIB26, 7)

        # Temperature calibration
        self.dig_T1 = u16(calib1[0], calib1[1])
        self.dig_T2 = s16(calib1[2], calib1[3])
        self.dig_T3 = s16(calib1[4], calib1[5])

        # Pressure calibration
        self.dig_P1 = u16(calib1[6], calib1[7])
        self.dig_P2 = s16(calib1[8], calib1[9])
        self.dig_P3 = s16(calib1[10], calib1[11])
        self.dig_P4 = s16(calib1[12], calib1[13])
        self.dig_P5 = s16(calib1[14], calib1[15])
        self.dig_P6 = s16(calib1[16], calib1[17])
        self.dig_P7 = s16(calib1[18], calib1[19])
        self.dig_P8 = s16(calib1[20], calib1[21])
        self.dig_P9 = s16(calib1[22], calib1[23])

        # Humidity calibration
        self.dig_H1 = calib1[25]
        self.dig_H2 = s16(calib2[0], calib2[1])
        self.dig_H3 = calib2[2]
        self.dig_H4 = (calib2[3] << 4) | (calib2[4] & 0x0F)
        self.dig_H5 = (calib2[5] << 4) | (calib2[4] >> 4)
        self.dig_H6 = calib2[6]
        if self.dig_H6 > 127:
            self.dig_H6 -= 256

        # Configure sensor
        self.bus.write_byte_data(self.address, REG_CTRL_HUM, 0x01)   # Humidity oversampling x1
        self.bus.write_byte_data(self.address, REG_CTRL_MEAS, 0x27)  # Temp & Pressure oversampling x1, normal mode
        self.bus.write_byte_data(self.address, REG_CONFIG, 0xA0)     # Standby 1000ms

    def read_values(self):
        data = self.bus.read_i2c_block_data(self.address, REG_DATA, 8)

        adc_p = (data[0] << 12) | (data[1] << 4) | (data[2] >> 4)
        adc_t = (data[3] << 12) | (data[4] << 4) | (data[5] >> 4)
        adc_h = (data[6] << 8) | data[7]

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

        pressure = pressure / 100.0  # hPa

        # Humidity compensation
        var_h = self.t_fine - 76800.0
        var_h = (adc_h - (self.dig_H4 * 64.0 + self.dig_H5 / 16384.0 * var_h)) * (
            self.dig_H2
            / 65536.0
            * (1.0 + self.dig_H6 / 67108864.0 * var_h
            * (1.0 + self.dig_H3 / 67108864.0 * var_h))
        )
        var_h = var_h * (1.0 - self.dig_H1 * var_h / 524288.0)

        if var_h > 100:
            var_h = 100
        elif var_h < 0:
            var_h = 0

        humidity = var_h

        return temperature, pressure, humidity

def main():
    if len(sys.argv) > 1:
        try:
            address = int(sys.argv[1], 16)
        except ValueError:
            address = DEFAULT_ADDRESS
    else:
        address = DEFAULT_ADDRESS

    try:
        bme = BME280(address)

        print("| Temperature | Pressure    | Humidity |")
        print("|-------------|-------------|----------|")

        while True:
            temp, press, hum = bme.read_values()
            print(f"|    {temp:.2f} °C | {press:.2f} hPa |  {hum:.2f} % |")
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
