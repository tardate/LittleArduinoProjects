def do_connect():
    import network

    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    if not wlan.isconnected():
        print('connecting to network...')
        wlan.connect('%{WIFI_SSID}%', '%{WIFI_PASSWORD}%')
        while not wlan.isconnected():
            pass
    print('network config:', wlan.ifconfig())

do_connect()
