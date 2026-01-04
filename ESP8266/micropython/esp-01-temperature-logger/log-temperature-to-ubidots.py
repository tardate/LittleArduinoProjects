import socket
import ujson
import time
import onewire
import ds18x20
from machine import Pin

HOST = "industrial.api.ubidots.com"
PORT = 80
DEVICES_PATH = "/api/v1.6/devices/"
TOKEN = "my-api-token"
ONEWIRE_PIN = 2


def post_temperature(api_host_address, device_name, temperature):
    payload = {
        "temperature": {
            "value": temperature, "units": "C"
        }
    }
    body = ujson.dumps(payload)

    s = socket.socket()
    s.connect(api_host_address)

    request = (
        "POST {}{} HTTP/1.1\r\n"
        "Host: {}\r\n"
        "X-Auth-Token: {}\r\n"
        "Content-Type: application/json\r\n"
        "Content-Length: {}\r\n"
        "Connection: close\r\n"
        "\r\n"
        "{}"
    ).format(DEVICES_PATH, device_name, HOST, TOKEN, len(body), body)

    s.send(request.encode())
    print(s.recv(1024))
    s.close()

def read_and_log_temps(ds, api_host_address):
    roms = ds.scan()
    while True:
        ds.convert_temp()
        time.sleep(1)
        for rom in roms:
            device_name = 'esp8266-' + ''.join('{:02x}'.format(b) for b in rom)
            temperature = ds.read_temp(rom)
            print('Device:', device_name, 'Latest reading:', temperature)
            post_temperature(api_host_address, device_name, temperature)
        time.sleep(9)

ubidots_addr = socket.getaddrinfo(HOST, PORT)[0][-1]
ds = ds18x20.DS18X20(onewire.OneWire( Pin(ONEWIRE_PIN)))

read_and_log_temps(ds, ubidots_addr)
