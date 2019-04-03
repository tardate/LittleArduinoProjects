# #327 Mixers/RFDiodeRing

A diode ring double-balanced frequency mixer.

![Build](./assets/RFDiodeRing_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

My build here is inspired by another great tutorial form w2aew -
[#167: How a Diode Ring Mixer works | Mixer operation theory and measurement](https://www.youtube.com/watch?v=junuEwmQVQ8).

Section 5.2 of [Experimental Methods in RF Design](https://www.goodreads.com/book/show/2386153.Experimental_Methods_in_RF_Design)
includes a complete evolution of the diode ring mixer and a very clear explanation of how it works.

See [LEAP#326](../) for my notes on mixer theory and types.

### How it works

* the RF input is connected to the IF via a transformer
* the transformer-isolated LO switches the conducting diode pairs on each each half of the cycle, thus the polarity of the RF signal to IF
* classic example of a commutation mixer

## Performance

### Test 1: 7MHz LO + 10MHz RF

This works pretty well, alough my signals are quite noisy.

| Scope Channel | Signal | Detail         |
|---------------|--------|----------------|
| CH1           | LO     | 7MHz 0.8V p-p  |
| CH2           | RF     | 10MHz 0.4V p-p |
| CH3           | IF     |                |

![scope_test_1_td](./assets/scope_test_1_td.gif?raw=true)

![scope_test_1_fft](./assets/scope_test_1_fft.gif?raw=true)


### Test 2: 5MHz LO + 10MHz RF

With the LO as an even factor of the RF signal, I'm seeing what I'd expect here: very strong sum and difference signals and no other products

![scope_test_2_td](./assets/scope_test_2_td.gif?raw=true)

![scope_test_2_fft](./assets/scope_test_2_fft.gif?raw=true)


### Test 2: 18MHz LO + 2MHz RF

With the LO and RF frequencies separated significantly, sum and difference are strong over other products.

![scope_test_3_td](./assets/scope_test_3_td.gif?raw=true)

![scope_test_3_fft](./assets/scope_test_3_fft.gif?raw=true)


## Construction

I'm using 1N5711 small signal schottky diodes (as did w2aew), which are well suited to this application:

* high breakdown, low turn-on voltage and ultrafast switching
* primarly intended for high level UHF/VHF detection and pulse application with broad dynamic range

For the transformers, I'm using 68-26 iron ferrite toroids with 30AWG solid wire (10 turns per winding).

![Schematic](./assets/RFDiodeRing_schematic.jpg?raw=true)

![RFDiodeRing_layout](./assets/RFDiodeRing_layout.jpg?raw=true)

![Build](./assets/RFDiodeRing_build.jpg?raw=true)

## Credits and References
* [LEAP#326 Mixers](../) - my notes on mixer theory and types
* [Experimental Methods in RF Design](https://www.goodreads.com/book/show/2386153.Experimental_Methods_in_RF_Design) - chapter 5.2
* [#167: How a Diode Ring Mixer works | Mixer operation theory and measurement](https://www.youtube.com/watch?v=junuEwmQVQ8) - w2aew
* [#166: How to wind a trifilar toroid transformer for a diode ring mixer](https://www.youtube.com/watch?v=a8ViWS61hsU) - w2aew
* [1N5711 datasheet](https://www.futurlec.com/Diodes/1N5711.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2017/07/leap327-diode-ring-mixer.html)
