# #580 Digital Logic Families

My personal notebook on digital logic families, chip listings, and reference sources.

![Build](./assets/logic_families_build.jpg?raw=true)

## Notes

Digital logic families represent the various techniques and technologies that have been developed to implement digital circuits with the fundamentally analog medium of electronics.
Mostly we are concerned with logic families that have been used to create monolithic integrated circuits (i.e. packages rather than discrete components).

For practical hobbyist purposes, 74HC series chips should be preferred, but the older 4000  series are still useful if wider voltage ranges need to be supported.

### Brief History of Logic Families

* [Resistor–transistor logic (RTL)](https://en.wikipedia.org/wiki/Resistor%E2%80%93transistor_logic)
    * Several early transistorized computers (e.g., IBM 1620, 1959) used RTL
    * RTL circuits were first constructed with discrete components, but in 1961 it became the first digital logic family to be produced as a monolithic integrated circuit.
* [Diode–transistor logic (DTL)](https://en.wikipedia.org/wiki/Diode%E2%80%93transistor_logic)
    * Diode logic was used with vacuum tubes in the earliest electronic computers in the 1940s
    * In 1962, Signetics introduced the SE100-series family, the first high-volume DTL chips.
    * In 1964, Fairchild released the 930-series DTμL micrologic family that had a better noise immunity, smaller die, and lower cost
* [Emitter-coupled logic (ECL)](https://en.wikipedia.org/wiki/Emitter-coupled_logic)
    * high-speed integrated circuit bipolar transistor logic family invented in August 1956
    * Beginning in the early 1960s, ECL circuits were implemented on monolithic integrated circuits
* [PMOS](https://en.wikipedia.org/wiki/PMOS_logic) and [NMOS](https://en.wikipedia.org/wiki/NMOS_logic) logic
    * In the late 1960s and early 1970s, PMOS logic was the dominant semiconductor technology for large-scale integrated circuits before being superseded by NMOS and CMOS devices.
    * NMOS was initially faster than CMOS, thus NMOS was more widely used for computers in the 1970s
    * With advances in technology, CMOS logic displaced NMOS logic in the mid-1980s to become the preferred process for digital chips
* [Transistor–transistor logic (TTL)](https://en.wikipedia.org/wiki/Transistor%E2%80%93transistor_logic)
    * TTL was invented in 1961
    * TTL became popular after Texas Instruments introduced the 5400 series of ICs in 1964
    * The 7400 series, specified over a narrower range and with inexpensive plastic packages, was introduced in 1966
    * The term "TTL" is applied to many successive generations of bipolar logic
        * Low-power TTL (L), which traded switching speed (33ns) for a reduction in power consumption (1 mW) (now essentially replaced by CMOS logic)
        * High-speed TTL (H), with faster switching than standard TTL  but significantly higher power dissipation
        * Schottky TTL (S), introduced in 1969, which used Schottky diode clamps at gate inputs to prevent charge storage and improve switching time.
        * Low-power Schottky TTL (LS) – used the higher resistance values of low-power TTL and the Schottky diodes to provide a good combination of speed and reduced power consumption
        * Fast (F) and Advanced-Schottky (AS) variants of LS from Fairchild and TI, respectively, circa 1985
        * Low-voltage TTL (LVTTL) for 3.3-volt power supplies and memory interfacing
* [Complementary MOS (CMOS) logic](https://en.wikipedia.org/wiki/CMOS)
    * The first CMOS family of logic integrated circuits was introduced by RCA as CD4000 COS/MOS, the 4000 series, in 1968
    * CMOS chips often work with a broader range of power supply voltages than other logic families
    * Because of the incompatibility of the CD4000 series of chips with the previous TTL family, a new standard emerged which combined the best of the TTL family with the advantages of the CD4000 family.
        * 74HC used 5V power supplies and TTL logic levels.
* [Bipolar CMOS (BiCMOS) logic](https://en.wikipedia.org/wiki/BiCMOS)
    * combine CMOS inputs and TTL drivers
    * BiCMOS is aimed at mixed-signal ICs, such as ADCs and complete software radio systems on a chip that need amplifiers, analog power management circuits, and logic gates on chip
    * many new families, including:
        * LV logic (lower supply voltage)
        * LVT logic (lower supply voltage while retaining TTL logic levels)
        * ALVT logic (an 'advanced' version of LVT logic)
        * many others including AC/ACT logic
* [Integrated injection logic (IIL)](https://en.wikipedia.org/wiki/Integrated_injection_logic)
    * I2L was developed in 1971
    * It was used in some integrated circuits, but it is now considered obsolete.

### Key CMOS and TTL Families

For hobbyists, the CMOS (4000-series) and TTL (7400-series) integrated circuits are the most common:

| Family | Description     | Propagation delay | Toggle speed | Power per gate @1MHz | Typical supply voltage    | Introduced | Remarks |
|--------|-----------------|-------------------|--------------|----------------------|---------------------------|------------|---------|
| TTL    | Original 74xx   | 0 ns              |   25 MHz     |   10 mW              |  5 (4.75-5.25)            | 1964       | Several manufacturers |
| TTL    | 74L             | 3 ns              |    3 MHz     |    1 mW              |  5 (4.75-5.25)            | 1964       | Low power |
| TTL    | 74H             | 6 ns              |   43 MHz     |   22 mW              |  5 (4.75-5.25)            | 1964       | High speed |
| TTL    | 74S             | 3 ns              |  100 MHz     |   19 mW              |  5 (4.75-5.25)            | 1969       | Schottky high speed |
| TTL    | 74LS            | 0 ns              |   40 MHz     |    2 mW              |  5 (4.75-5.25)            | 1976       | Low power Schottky high speed |
| TTL    | 74ALS           | 4 ns              |   50 MHz     |  1.3 mW              |  5 (4.5-5.5)              | 1976       | Advanced Low power Schottky |
| TTL    | 74F             | 3.5 ns            |  100 MHz     |  5.4 mW              |  5 (4.75-5.25)            | 1979       | Fast |
| TTL    | 74AS            | 2 ns              |  105 MHz     |    8 mW              |  5 (4.5-5.5)              | 1980       | Advanced Schottky |
| TTL    | 74G             | 1.5 ns            | 1125 MHz     |                      |  1.65 - 3.6               | 2004       | First GHz 7400 series logic |
| CMOS   | 4000B/74C       | 3 ns              |    5 MHz     |  1.2 mW              |  10 (3-18)                | 1970       | Approximately half speed and power at 5 volts |
| CMOS   | 74HC/HCT        | 9 ns              |   50 MHz     |  0.5 mW              |  5 (2-6 or 4.5-5.5)       | 1982       | HCT has TTL compatible levels |
| CMOS   | 74AC/ACT        | 3 ns              |  125 MHz     |  0.5 mW              |  3.3 (2-6) or 5 (4.5-5.5) | 1985       | ACT has TTL compatible levels |

In general, 74HC is the best first choice: combines the high speed and low power of previous CMOS/TTL families with a wide supply-voltage range.

* alternatively 74HCT can be used where TTL compatible levels are required
* original 4000-Series CMOS are still available and can be useful where you need a greater power-supply range than high-speed CMOS.

The older 74xx-series TTL chips can still be found, especially new-old and refurbished stock. These can be useful for reproducing old circuit designs.

### 4000-Series Logic Gate Selections

One input voltage translation gates:

* 40109 = Quad Buffer (dual power rails)
* 4504 = Hex Buffer (dual power rails)

One input logic gates:

* 4041 = Quad Buffer/Inverter, each input has 2 outputs Q and Q (outputs can drive one TTL / two 74LS / four CMOS loads)
* 4050 = Hex Buffer (outputs can drive two TTL / four 74LS / eight CMOS loads) (note: VDD power rail pin at non-typical location)
* 4049 = Hex Inverter (outputs can drive two TTL / four 74LS / eight CMOS loads) (note: VDD power rail pin at non-typical location)
* 4069 = Hex Inverter
* 40106 = Hex Inverter with schmitt trigger inputs (pinout compatible with 4069)
* 4572 = Quad Inverter, plus a 2-Input NOR gate and a 2-Input NAND gate

Two to eight input logic gates:

| Configuration                | AND  | NAND | OR   | NOR  |  XOR  | XNOR |
|------------------------------|------|------|------|------|-------|------|
| Dual 2-Input                 |      | 40107|      |      |       |      |
| Quad 2-Input                 | 4081 | 4011 | 4071 | 4001 |  4070 | 4077 |
| Quad 2-Input schmitt trigger |      | 4093 |      |      |       |      |
| Triple 3-Input               | 4073 | 4023 | 4075 | 4025 |  n/a  | n/a |
| Dual 4-Input                 | 4082 | 4012 | 4072 | 4002 |  n/a  | n/a |
| Single 8-Input               | 4068 | 4068 | 4078 | 4078 |  n/a  | n/a |

### 7000-Series Logic Gate Selections

#### Normal inputs / push–pull outputs

| Configuration | Buffer | Inverter |
|---------------|--------|----------|
| Hex 1-input   | 74x34  | 74x04    |

| Configuration  | AND   | NAND  | OR      | NOR     | XOR   | XNOR    |
|----------------|-------|-------|---------|---------|-------|---------|
| Quad 2-input   | 74x08 | 74x00 | 74x32   | 74x02   | 74x86 | 74x7266 |
| Triple 3-Input | 74x11 | 74x10 | 74x4075 | 74x27   | n/a   | n/a     |
| Dual 4-input   | 74x21 | 74x20 | 74x4072 | 74x29   | n/a   | n/a     |
| Single 8-input |  n/a  | 74x30 | 74x4078 | 74x4078 | n/a   | n/a     |

#### Schmitt-trigger inputs / push–pull outputs

| Configuration | Buffer  | Inverter |
|---------------|---------|----------|
| Hex 1-input   | 74x7014 | 74x14    |

| Configuration | AND     | NAND   | OR      | NOR     |
|---------------|---------|--------|---------|---------|
| Quad 2-input  | 74x7001 | 74x132 | 74x7032 | 74x7002 |
| Dual 4-input  | n/a     | 74x13  | n/a     | n/a     |

#### Normal inputs / open-collector outputs

| Configuration  | Buffer | Inverter |
|----------------|--------|----------|
| Hex 1-input    | 74x07  | 74x05 |

| Configuration  | AND   | NAND  | OR  | NOR   | XOR    | XNOR   |
|----------------|-------|-------|-----|-------|--------|--------|
| Quad 2-input   | 74x09 | 74x03 | n/a | 74x33 | 74x136 | 74x266 |
| Triple 3-input | 74x15 | 74x12 | n/a | n/a   | n/a    | n/a    |
| Dual 4-input   | n/a   | 74x22 | n/a | n/a   | n/a    | n/a    |

## Credits and References

* [Electronics cookbook by Simon Monk](https://www.goodreads.com/book/show/30796739-electronics-cookbook)
* [Logic family](https://en.wikipedia.org/wiki/Logic_family) - wikipedia
* [Digital Electronics - Families](https://www.tutorialspoint.com/digital-electronics/digital-electronics-families.htm)
* [An Overview of Digital Logic Families](https://www.youtube.com/watch?v=TICSYYKFhys) - youtube
* [4000-series logic](https://en.wikipedia.org/wiki/4000_series) - wikipedia
    * [List of 4000-series integrated circuits](https://en.wikipedia.org/wiki/List_of_4000-series_integrated_circuits)
* [7400-series logic](https://en.wikipedia.org/wiki/7400_series) - wikipedia
    * [List of 7400-series integrated circuits](https://en.wikipedia.org/wiki/List_of_7400-series_integrated_circuits)
* [7400 series CMOS vs 4000 series logic IC](https://electronics.stackexchange.com/questions/223063/7400-series-cmos-vs-4000-series-logic-ic) - stackexchange
