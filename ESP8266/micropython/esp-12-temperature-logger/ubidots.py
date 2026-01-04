import urequests
import ujson

UBIDOTS_API_KEY="%{UBIDOTS_API_KEY}%"

def get_new_token():
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

def post_temperature(token, temperature):
    url = "https://industrial.api.ubidots.com/api/v1.6/devices/test-device"
    payload = {"temperature":{"value": temperature, "units": "C"}}

    headers = {
        "X-Auth-Token": token,
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
    return resp.status_code

token = get_new_token()
if token:
    post_temperature(token, 23.4)
