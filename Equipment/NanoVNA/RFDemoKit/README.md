# #776 RF Demo Kit

Using the NWDZ Rev-01-10 RF Test Board with the NanoVNA.

![Build](./assets/RFDemoKit_build.jpg?raw=true)

## Notes

The NWDZ Rev-01-10 RF Test Board is widely available from many sellers; I got mine from
[aliexpress](https://www.aliexpress.com/item/1005005622482238.html) for SGD$7.64 (April 2025).

It is designed for primarily for testing  and learning how to use a vector network analyzer,
such as the NanoVNA - see [LEAP#767](../) for more on the NanoVNA.

### RF Demo Kit Product Description

Package List:

* 1 x RF Demo Kit Board
* 2 x UFL Patch Cord

Test circuits:

* Pad 1: 30MHz low-pass filter
* Pad 2: 100MHz high-pass filter
* Pad 3: 433MHz band-pass filter (BPF)
* Pad 4: 6.5MHz notch/band-stop filter (BSF)
* Pad 5: 33Ω load SWR=1.5
* Pad 6: 75Ω load SWR=1.5
* Pad 7: Capacitor (C) circuit
* Pad 8: Inductor (L) circuit
* Pad 9: resistor-capacitor (RC) series circuit
* Pad 10: inductor-capacitor (LC) series circuit
* Pad 11: capacitor in series with parallel resistor-inductor (RLC) circuit
* Pad 12: resistor in parallel with series capacitor-inductor (RLC) circuit
* Pad 13: short
* Pad 14: open
* Pad 15: load (50Ω)
* Pad 16: through connection
* Pad 17: -5dB attenuation circuit
* Pad 18: -10dB attenuation circuit

Board front and rear:

![board](./assets/board.jpg)

### Calibration

To calibrate the NanoVNA with the RF Board and connectors,
I used the following procedure:

* set `START` to 10kHz, `END` to 500MHz
* choose `CAL` from the main menu
* choose `RESET`
* choose `CALIBRATE`
* connect S11 to the "14: Open" pad, press `OPEN`
* connect S11 to the "13: Short" pad, press `SHORT`
* connect S11 to the "15: Load" pad, press `LOAD`
* connect S21 to the "15: Load" pad, press `ISOLN`
* connect S11 and S21 via the "16: Thru" pad, press `THRU`
* press `DONE`

## Tests

For the following tests, I am capturing the result with [NanoVNASaver](https://github.com/NanoVNA-Saver/nanovna-saver)

![board-test](./assets/board-test.jpg)

### Testing Pad 1: 30MHz low-pass filter

![1-lpf-app](./assets/1-lpf-app.png)
![1-lpf-chart](./assets/1-lpf-chart.png)
![1-lpf-analysis](./assets/1-lpf-analysis.png)

### Testing Pad 2: 100MHz high-pass filter

![2-hpf-app](./assets/2-hpf-app.png)
![2-hpf-chart](./assets/2-hpf-chart.png)
![2-hpf-analysis](./assets/2-hpf-analysis.png)

### Testing Pad 3: 433MHz band-pass filter (BPF)

![3-bpf-app](./assets/3-bpf-app.png)
![3-bpf-chart](./assets/3-bpf-chart.png)
![3-bpf-analysis](./assets/3-bpf-analysis.png)

### Testing Pad 4: 6.5MHz notch/band-stop filter (BSF)

![4-bsf-app](./assets/4-bsf-app.png)
![4-bsf-chart](./assets/4-bsf-chart.png)
![4-bsf-analysis](./assets/4-bsf-analysis.png)

### Testing Pad 5: 33Ω load SWR=1.5

![5-33-app](./assets/5-33-app.png)
![5-33-chart](./assets/5-33-chart.png)

### Testing Pad 6: 75Ω load SWR=1.5

![6-75-app](./assets/6-75-app.png)
![6-75-chart](./assets/6-75-chart.png)

### Testing Pad 7: Capacitor (C) circuit

![7-C-app](./assets/7-C-app.png)
![7-C-chart](./assets/7-C-chart.png)

### Testing Pad 8: Inductor (L) circuit

![8-L-app](./assets/8-L-app.png)
![8-L-chart](./assets/8-L-chart.png)

### Testing Pad 9: resistor-capacitor (RC) series circuit

![9-RC-app](./assets/9-RC-app.png)
![9-RC-chart](./assets/9-RC-chart.png)

### Testing Pad 10: inductor-capacitor (LC) series circuit

![10-LC-app](./assets/10-LC-app.png)
![10-LC-chart](./assets/10-LC-chart.png)

### Testing Pad 11: capacitor in series with parallel resistor-inductor (RLC) circuit

![11-RLC-app](./assets/11-RLC-app.png)
![11-RLC-chart](./assets/11-RLC-chart.png)

### Testing Pad 12: resistor in parallel with series capacitor-inductor (RLC) circuit

![12-RLC-app](./assets/12-RLC-app.png)
![12-RLC-chart](./assets/12-RLC-chart.png)

### Testing Pad 17: -5dB attenuation circuit

![17-5dB-ATT-app](./assets/17-5dB-ATT-app.png)
![17-5dB-ATT-chart](./assets/17-5dB-ATT-chart.png)

### Testing Pad 18: -10dB attenuation circuit

![18-10dB-ATT-app](./assets/18-10dB-ATT-app.png)
![18-10dB-ATT-chart](./assets/18-10dB-ATT-chart.png)

## Credits and References

* [NanoVNA Filter Attenuator VNA RF Test Board Tester Demo Kit Module Breadboard Network Analyzer Universal Tool](https://www.aliexpress.com/item/1005005622482238.html) - aliexpress
* [LEAP#767 NanoVNA](../)
* [NanoVNASaver](https://github.com/NanoVNA-Saver/nanovna-saver)

## Video References

### #517 NANOVNA RF Demo Board - IMSAI Guy

[![clip](https://img.youtube.com/vi/SneOI7l5Kw4/0.jpg)](https://www.youtube.com/watch?v=SneOI7l5Kw4)

### NanoVNA RF Test Board - RF Demos Kit - HAMTech RADIO SCANNER M0FXB CB DRONE HOBBY Diary

[![clip](https://img.youtube.com/vi/4clpEKJrBWY/0.jpg)](https://www.youtube.com/watch?v=4clpEKJrBWY)
