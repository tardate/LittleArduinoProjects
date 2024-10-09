# #346 RF Connectors

Notes on miscellaneous RF connectors.

![Build](./assets/RF_build.jpg?raw=true)

## Notes

All about Radio Frequency connectors and cables, typical applications:

* between VCR and TV receiver (back in the day!)
* into cable TV, satellite dish
* cable modems
* ham radio
* test equipment

Typically use coaxial cable.

### "UHF" Connector

UHF Connector is dated terminology for RF connections using SO-239 (socket) and PL-259 (plug).

* most common type used on HF, also used for VHF, UHF
* scientific, test equipment
* see [UHF connector](https://en.wikipedia.org/wiki/UHF_connector) - wikipedia

![uhf_connector](./assets/uhf_connector.jpg?raw=true)

![SO-239](./assets/SO-239.jpg?raw=true)

[![uhf](https://upload.wikimedia.org/wikipedia/commons/2/26/UHF-Connector.png)](https://en.wikipedia.org/wiki/UHF_connector#/media/File:UHF-Connector.png)

### BNC Connectors

BNC - Bayonet Neill–Concelman.

* used on VHF, UHF, sometiems HF. Use in RF applications is gradually fading.
* widely used outside of RF e.g. test equipment etc

See also:

* [BNC Connector](https://en.wikipedia.org/wiki/BNC_connector) - wikipedia
* [BNC Connector Series](https://www.amphenolrf.com/connectors/bnc.html) - Amphenol. From 50 Ω to 75 Ω Impedance

![bnc_connector](./assets/bnc_connector.jpg?raw=true)

#### How to install a BNC connector on RG-58 coax

w2aew has a great video on crimping your own RG-58 connectors:

[![Build](https://img.youtube.com/vi/ktQVwfo-s9w/0.jpg)](https://www.youtube.com/watch?v=ktQVwfo-s9w)

A similar technique works for RG174, although with those I find extreme care is required not to destroy
the inner pin (I've destroyed a few with just a little extra force when crimping)

#### Crimping Tools

I have an [AN-02H1](https://www.aliexpress.com/item/AN-02H1-RG58-RG59-RG62-crimper-BNC-fiber-optic-Crimping-Tool-for-crimping-coaxial-cable-connectors/1537820281.html)
crimping tool, which conveniently handles RG58 and RG174, among many others.

![crimp_tool](./assets/crimp_tool.jpg?raw=true)



### SMA connector

* commonly used on VHF and above
* used in low-power, mobile

SMA (SubMiniature version A) connectors are semi-precision coaxial RF connectors.
SMA connectors can be visually confused with the standard household 75-ohm type F coax connector

[![sma](https://upload.wikimedia.org/wikipedia/commons/d/d5/Male_50_ohm_SMA_connector.jpg)](https://en.wikipedia.org/wiki/SMA_connector#/media/File:Male_50_ohm_SMA_connector.jpg)

### Type N

The N connector is a threaded, weatherproof, medium-size RF connector used to join coaxial cables.

* used for high power on VHF, UHF and above

[![type_n_connector](./assets/type_n_connector.jpg?raw=true)](https://en.wikipedia.org/wiki/N_connector)

### F Connector

* F Quick Connect - non-threaded, goes over thread
* used RF splitter
* RF adapter - F connect to RCA
* [F connector](https://en.wikipedia.org/wiki/F_connector) - wikipedia
* [F-Type connector series](https://www.amphenolrf.com/connectors/f-type.html) - Amphenol’s F-Type is a 75 Ω connector featuring 30 dB return loss at 1GHz.

[![f](https://upload.wikimedia.org/wikipedia/commons/thumb/5/5b/F_Connector_Side.jpg/500px-F_Connector_Side.jpg)](https://en.wikipedia.org/wiki/F_connector#/media/File:F_Connector_Side.jpg)


### Coaxial Cable

* [Coaxial cable](https://en.wikipedia.org/wiki/Coaxial_cable) - wikipedia
* RG-58/U - 50Ω Used for radiocommunication and amateur radio, thin Ethernet (10BASE2) and NIM electronics, Loss 1.056 dB/m @ 2.4 GHz. Common.[22]
* RG-59/U - 75Ω Used to carry baseband video in closed-circuit television, previously used for cable television. In general, it has poor shielding but will carry an HQ HD signal or video over short distances
* RG-174/U - 50Ω - Common for Wi-Fi pigtails: more flexible but higher loss than RG58; used with LEMO 00 connectors in NIM electronics.
* RG-213/U - 50Ω - For radiocommunication and amateur radio, EMC test antenna cables. Typically lower loss than RG58. Common.[30]


Typical Crimp Die sizes

| Cable  | Pin        | Ferrule      |
|--------|------------|--------------|
| RG-59  | 0.068/1.72 | .255/6.48    |
| RG-174 | 0.068/1.72 | .178/4.52    |

## Resources and Tutorials

[RF Connectors and what they're for: AD#35](https://youtu.be/ol36eqfEtlw)

[![clip](https://img.youtube.com/vi/ol36eqfEtlw/0.jpg)](https://www.youtube.com/watch?v=ol36eqfEtlw)


## Credits and References

* [Practical Electronics: Components and Techniques](https://www.goodreads.com/book/show/21483234-practical-electronics)
* [Tech Basics: Cables & Connectors](https://www.udemy.com/tech101-cables-and-connectors/) - udemy course
* [Coax Connectors - Peculiar Parts, the series](https://www.elektormagazine.com/magazine/elektor-201511/28193/) - elektor article
* [AN-02H1 RG58 RG59 RG62 crimper BNC fiber optic Crimping Tool for crimping coaxial cable connectors](https://www.aliexpress.com/item/AN-02H1-RG58-RG59-RG62-crimper-BNC-fiber-optic-Crimping-Tool-for-crimping-coaxial-cable-connectors/1537820281.html)
* [BNC Connector Series](https://www.amphenolrf.com/connectors/bnc.html) - Amphenol. From 50 Ω to 75 Ω Impedance
* [Coaxial cable](https://en.wikipedia.org/wiki/Coaxial_cable) - wikipedia
* [BNC Connector](https://en.wikipedia.org/wiki/BNC_connector) - wikipedia
* [F connector](https://en.wikipedia.org/wiki/F_connector) - wikipedia
* [F-Type connector series](https://www.amphenolrf.com/connectors/f-type.html) - Amphenol’s F-Type is a 75 Ω connector featuring 30 dB return loss at 1GHz.
* [..as mentioned on my blog](https://blog.tardate.com/2017/10/leap347-rf-connectors.html)

