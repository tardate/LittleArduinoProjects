# #508 Using mDNS

Delving into multicast DNS and how it can be used to find and connect to ESP32 devices on the network.

![Build](./assets/UsingMDNS_build.jpg?raw=true)

## Notes

When an ESP32 is used to offer some kind of network service (e.g. a web interface or API),
it necessary to figure out how a client can locate and connect to the service,
especially of the ESP is getting an address from a DHCP pool instead of being statically assigned.

It is not very convenient to use IP address, as these can change over time and one has to find out the address it is using in the first place.
What we want to do is connect by hostname, and have the network perform the name resolution for us.

The ESP32 supports [Multicast DNS (mDNS)](https://en.wikipedia.org/wiki/Multicast_DNS) for this purpose.
The mDNS protocol resolves hostnames to IP addresses within small networks that do not include a local name server.

For the ESP32, support for mDNS is included in both
[ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/api-reference/protocols/mdns.html) and
[Arduino ESPmDNS library](https://github.com/espressif/arduino-esp32/tree/master/libraries/ESPmDNS).

I'm using the ESPmDNS library for this investigation.

### Building and Running the Example

The [UsingMDNS.ino](./UsingMDNS.ino) is a simple web server example that demonstrates registration with mDNS.

Copy `settings.h.template` to `settings.h` and fill in the WiFi access credentials before compiling and uploading the program to the ESP32.

The console will confirm the DHCP IP address and name that the device registers on the network:

![console_startup](./assets/console_startup.png?raw=true)

### Minimum Registration Details

The minimum required to regster the ESP32 is to begin the mDNS service with a hostname:

    #include <ESPmDNS.h>
    char hostname[] = "esp32-using-mdns";
    MDNS.begin(hostname)

### Querying the Device

The [dns-sd](https://docs.oracle.com/cd/E36784_01/html/E36871/dns-sd-1m.html) utility is available on MacOS for managing and querying mDNS registrations.
With dns-sd, I can find the ESP32 on the network, and confirm the IP address it is using.

    $ dns-sd -q esp32-using-mdns.local
    DATE: ---Sun 10 Nov 2019---
    14:55:54.837  ...STARTING...
    Timestamp     A/R Flags if Name                          Type  Class   Rdata
    14:55:54.838  Add     2  7 esp32-using-mdns.local.       Addr   IN     192.168.1.181

![console_lookup](./assets/console_lookup.png?raw=true)

The ESP32 web service can be loaded by domain name:

    $ curl -vv http://esp32-using-mdns.local/
    *   Trying 192.168.1.181...
    * TCP_NODELAY set
    * Connected to esp32-using-mdns.local (192.168.1.181) port 80 (#0)
    > GET / HTTP/1.1
    > Host: esp32-using-mdns.local
    > User-Agent: curl/7.54.0
    > Accept: */*
    >
    < HTTP/1.1 200 OK
    < Content-Type: text/html
    < Content-Length: 261
    < Connection: close
    <
    * Closing connection 0
    <!doctype html><html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no"></head><body><h1>UsingMDNS</h1><p>Hostname: esp32-using-mdns.local</p><p>IP address: 192.168.1.181</p></body></html>$
    $

![web_result](./assets/web_result.png?raw=true)

### Additional Registration Details

Additional details can be registered with the `addService` method:

    // (optional) Register standard HTTP service
    MDNS.addService("http", "tcp", 80);
    // (optional) Register an arbitrary service name
    MDNS.addService("leap", "tcp", 80);

Browsing HTTP services:

    $ dns-sd -B _http
    Browsing for _http._tcp
    DATE: ---Sun 10 Nov 2019---
    14:21:51.641  ...STARTING...
    Timestamp     A/R    Flags  if Domain               Service Type         Instance Name
    14:21:51.642  Add        2   7 local.               _http._tcp.          esp32-using-mdns
    ...

Browsing HTTP services and listing in zone file format:

    $ dns-sd -Z _http
    Browsing for _http._tcp
    DATE: ---Sun 10 Nov 2019---
    16:56:08.001  ...STARTING...

    ; To direct clients to browse a different domain, substitute that domain in place of '@'
    lb._dns-sd._udp                                 PTR     @

    ; In the list of services below, the SRV records will typically reference dot-local Multicast DNS names.
    ; When transferring this zone file data to your unicast DNS server, you'll need to replace those dot-local
    ; names with the correct fully-qualified (unicast) domain name of the target host offering the service.

    _http._tcp                                      PTR     esp32-using-mdns._http._tcp
    esp32-using-mdns._http._tcp                     SRV     0 0 80 esp32-using-mdns.local. ; Replace with unicast FQDN of target host
    esp32-using-mdns._http._tcp                     TXT     ""
    ...

    $ dns-sd -Z _leap
    Browsing for _leap._tcp
    DATE: ---Sun 10 Nov 2019---
    14:53:40.540  ...STARTING...

    ; To direct clients to browse a different domain, substitute that domain in place of '@'
    lb._dns-sd._udp                                 PTR     @

    ; In the list of services below, the SRV records will typically reference dot-local Multicast DNS names.
    ; When transferring this zone file data to your unicast DNS server, you'll need to replace those dot-local
    ; names with the correct fully-qualified (unicast) domain name of the target host offering the service.

    _leap._tcp                                      PTR     esp32-using-mdns._leap._tcp
    esp32-using-mdns._leap._tcp                     SRV     0 0 80 esp32-using-mdns.local. ; Replace with unicast FQDN of target host
    esp32-using-mdns._leap._tcp                     TXT     ""


The ESPmDNS library has an `enableArduino` method that registers Arduino details in a TXT record

    // (optional) Register arduino details
    MDNS.enableArduino(80, false);

Listing the registered details:

    $ dns-sd -Z _arduino
    Browsing for _arduino._tcp
    DATE: ---Sun 10 Nov 2019---
    14:52:30.093  ...STARTING...

    ; To direct clients to browse a different domain, substitute that domain in place of '@'
    lb._dns-sd._udp                                 PTR     @

    ; In the list of services below, the SRV records will typically reference dot-local Multicast DNS names.
    ; When transferring this zone file data to your unicast DNS server, you'll need to replace those dot-local
    ; names with the correct fully-qualified (unicast) domain name of the target host offering the service.

    _arduino._tcp                                   PTR     esp32-using-mdns._arduino._tcp
    esp32-using-mdns._arduino._tcp                  SRV     0 0 80 esp32-using-mdns.local. ; Replace with unicast FQDN of target host
    esp32-using-mdns._arduino._tcp                  TXT     "auth_upload=no" "ssh_upload=no" "tcp_check=no" "board=esp32"

## Construction

There is no "circuit" to construct per se - simply powering the ESP32 from the USB port.

![Breadboard](./assets/UsingMDNS_bb.jpg?raw=true)

![Schematic](./assets/UsingMDNS_schematic.jpg?raw=true)

## Credits and References

* [Multicast DNS](https://en.wikipedia.org/wiki/Multicast_DNS) - wikipedia
* [mDNS Service](https://docs.espressif.com/projects/esp-idf/en/latest/api-reference/protocols/mdns.html) - ESP-IDF Programming Guide
* [ESPmDNS](https://github.com/espressif/arduino-esp32/tree/master/libraries/ESPmDNS) - Arduino library for ESP32
* [dns-sd.org](http://www.dns-sd.org/) - very good starting point for information sources
* [dns-sd](https://www.unix.com/man-page/osx/1/dns-sd/) - MacOS man page
* [dns-sd](https://docs.oracle.com/cd/E36784_01/html/E36871/dns-sd-1m.html) - Solaris man page
