import socket
import ujson

HOST = "industrial.api.ubidots.com"
PORT = 80
PATH = "/api/v1.6/devices/test-device"
TOKEN = "my-api-token"

payload = {
    "temperature": {
        "value": 22.1, "units": "C"
    }
}

body = ujson.dumps(payload)

addr = socket.getaddrinfo(HOST, PORT)[0][-1]
s = socket.socket()
s.connect(addr)

request = (
    "POST {} HTTP/1.1\r\n"
    "Host: {}\r\n"
    "X-Auth-Token: {}\r\n"
    "Content-Type: application/json\r\n"
    "Content-Length: {}\r\n"
    "Connection: close\r\n"
    "\r\n"
    "{}"
).format(PATH, HOST, TOKEN, len(body), body)

s.send(request.encode())
print(s.recv(1024))
s.close()
