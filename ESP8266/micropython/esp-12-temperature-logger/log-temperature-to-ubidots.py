import urequests
import ujson
import time
import onewire
import ds18x20
from machine import Pin

UBIDOTS_API_KEY="%{UBIDOTS_API_KEY}%"
ONEWIRE_PIN = 2

class UbidotsApi():

    @property
    def token(self):
        if not hasattr(self, '_token'):
            self._token = self.get_token()
        return self._token

    def get_token(self):
        url = "https://industrial.api.ubidots.com/api/v1.6/auth/token"
        headers = {
            "x-ubidots-apikey": UBIDOTS_API_KEY,
            "Content-Type": "application/json"
        }
        resp = urequests.post(
            url,
            headers=headers
        )
        print(resp.status_code)
        print(resp.text)
        try:
            token = ujson.loads(resp.text).get("token")
        except Exception:
            token = None
        resp.close()
        return token

    def _post_request(self, url, payload):
        headers = {
            "X-Auth-Token": self.token,
            "Content-Type": "application/json"
        }
        resp = urequests.post(
            url,
            data=ujson.dumps(payload),
            headers=headers
        )
        print(resp.status_code)
        print(resp.text)
        resp.close()
        if resp.status_code == 401:
            print("Unauthorized - token may have expired")
            self._token = None
        return resp.status_code

    def post_request(self, url, payload):
        status_code = self._post_request(url, payload)
        if status_code == 401:
            # retry once with new token
            print("Retrying with new token...")
            status_code = self._post_request(url, payload)
        return status_code

    def post_temperature(self, device_name, temperature):
        url = "https://industrial.api.ubidots.com/api/v1.6/devices/{}".format(device_name)
        payload = {
            "temperature": {
                "value": temperature, "units": "C"
            }
        }
        self.post_request(url, payload)

def read_and_log_temps():
    ds = ds18x20.DS18X20(onewire.OneWire( Pin(ONEWIRE_PIN)))
    roms = ds.scan()
    api = UbidotsApi()
    while True:
        ds.convert_temp()
        time.sleep(1)
        for rom in roms:
            device_name = 'esp8266-' + ''.join('{:02x}'.format(b) for b in rom)
            temperature = ds.read_temp(rom)
            print('Device:', device_name, 'Latest reading:', temperature)
            api.post_temperature(device_name, temperature)
        time.sleep(9)

def demo_read_and_log_temps():
    import random

    roms = [b'\xff\xff\xff\xff\x12\x34\x56\x78']
    api = UbidotsApi()
    while True:
        time.sleep(1)
        for rom in roms:
            device_name = 'demo-' + ''.join('{:02x}'.format(b) for b in rom)
            temperature = 20.0 + random.getrandbits(5) / 10.0
            print('Device:', device_name, 'Latest reading:', temperature)
            api.post_temperature(device_name, temperature)
        time.sleep(9)

read_and_log_temps()
