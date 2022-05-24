# #637 CD4069 Logic Probe

A simple logic probe using inverter gates.

![Build](./assets/LogicProbe_build.jpg?raw=true)

## Notes

This is a variation of the [LEAP#636 CD4001 Logic Probe](../../CD4001/LogicProbe) circuit
but using inverter gates instead of NOR gates.
It was
[suggested by Steve Schnepp](https://github.com/tardate/LittleArduinoProjects/issues/29) as he noted that in the original circuit,
most NOR gates were being used as inverters anyway.

This logic probe design can detect and indicate:

* logic high (red LED on)
* logic low (green LED on)
* oscillating signal (yellow LED on)

### About the CD4069

The CD4069UBC is a pack of 6 inverter circuits. Key features:

* operating range (VDD): 3-15V
* monolithic CMOS
* low power TTL compatibility
* all inputs protected by standard CMOS protection circuit; voltage at any pin −0.5V to VDD+0.5V

See the [CD4069 datasheet](https://www.futurlec.com/4000Series/CD4069.shtml) for more.

### Construction

The first inverter is used as a buffer of the input signal.

When LOW input:

* first inverter output will be high
* with high output, D2 (green) on, D1 (red) off
* a fixed high signal will stall the oscillator on the 5th and 6th inverter gates
* R4 pulls the 5th inverter input high, thus final inverter output will also be high, and D3 (yellow) off

When HIGH input:

* first inverter output will be low
* with low output, D2 (green) off, D1 (red) on
* a fixed low signal will stall the oscillator on the 2nd and 3rd NOR gates
* R4 pulls the 5th inverter input high, thus final inverter output will also be high, and D3 (yellow) off

When input is oscillating:

* D2 (green), D1 (red) will flicker based on instantaneous input state
* oscillating input to the 5th inverter will enable the oscillator on 5th and 6th inverter gates
* final inverter output will oscillate, causing D3 (yellow) to light up

![bb](./assets/LogicProbe_bb.jpg?raw=true)

![schematic](./assets/LogicProbe_schematic.jpg?raw=true)

Breadboard test, with logic high input:

![LogicProbe_bb_build_high](./assets/LogicProbe_bb_build_high.jpg?raw=true)

Breadboard test, with logic low input:

![LogicProbe_bb_build_low](./assets/LogicProbe_bb_build_low.jpg?raw=true)

Breadboard test, with oscillating input (10kHz square wave from FY3200S signal generator):

![LogicProbe_bb_build_osc](./assets/LogicProbe_bb_build_osc.jpg?raw=true)

### Circuit Simulation

Follow
[![simulation](./assets/simulation.jpg?raw=true)](https://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l5AWAnC1b0DZzQExgBw7IDMSGkA7JMQhcSAlgKwhOSsCmAtGGAFAB3VhSw4KOEBiIgxEyHzBTJ0sEglSEM8TJAATDgDMAhgFcANgBcuZjrvBQHMSP0Xrps5ZuI52E-cfMrGzt2CHYnfgAnT3A1GLAcfAcweD5ojRBvdgzifE1Q1KEMhKSEb3BEqD4AcxjczQyEOEc+ACUGcpKOiXxwhybWRyhoJjaGMi0JBAQkj18ZXxGZJfCRwRAqLwwklMgk4m2qgGMQXt9tPNntUNh4O-u4MG4KbEVGJCYEHCZ8DGICGjDe5RU4zSagnaVAr3BRKXg+GQqBLnCR+QymSzWWz2MJA-hCXZXCSEzKHeRFFSVcShKHrakVJKXBlVIRMcgyNmsdlzdZslFc3z4JLkgXgpgicEipgJGQDaWo668mUeeWZRAs1jK7TIUSK9p8xGaA2qOT9dgsPowUa1A1ZUXEA4tAya1Fy7kDB3YC2wHB8Z2q4jq23qzorH1+jaOwOaCh5NVeYlhyC+510UQDWOaIjsT1gJO+2qZzIIosOrDhMZFnDSIsmoZyoZWumOjybSXN9PsNPtoRVi7NHm9uOt4dCjVVzl9uQRpDTeMgFASaPFr1AlMLufZhdxLe5-M1bdLhGLzKOivtE-VzQnut9BuWtZCWdZi4TQcbl8SZ-zkXfrd-xUnx3bQSXfS9tEvMdfx3TlwOnZ0UmkZcUm0ZdQ29ZMI0QrMBhQ10c3oPMMILcBKCPApULPKp2jww1SJAuI73NRtH1I9wQLgIkNWw8EeOXEUeK3QTAPohViT2LiBLI3jpMSYV1lo74sEUxU7DbA4kjbDxiQAOQQMAZj4OwMlbdVtPAPSDPwDtwW7fiFIk3jkXbaJ4V8JEES6aEBOcromS8g98AmO0gqwMsWjsULi3YKLzP8DELHWWKLjBHlIrfV9RHcPR0UCMZYukKLbzNQYH1GAAjU4JWIJgvzAQj8HoeQAA9TgwZSMCQUjnHAbUKhAABJABhAAdABnAaADsAAcTAscaABEAEsAHt9HGoazCMABbaalsm6o+BW-rFEyCocCQZinEeBx6GFU5MiOk7y3AMpiDoIEbuu7wRDKb53tUGYKA++YZWIPhcgegAxCAmoWdgeBAKHIg4ABHEwOEmo4AE8+CAA)

## Credits and References

* [CD4069 datasheet](https://www.futurlec.com/4000Series/CD4069.shtml)
* [LEAP#636 CD4001 Logic Probe](../../CD4001/LogicProbe)
* [CD4001/LogicProbe Improvement using CD4069UB](https://github.com/tardate/LittleArduinoProjects/issues/29) - suggestion from [Steve Schnepp](https://github.com/steveschnepp)
* [circuit simulation](https://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l5AWAnC1b0DZzQExgBw7IDMSGkA7JMQhcSAlgKwhOSsCmAtGGAFAB3VhSw4KOEBiIgxEyHzBTJ0sEglSEM8TJAATDgDMAhgFcANgBcuZjrvBQHMSP0Xrps5ZuI52E-cfMrGzt2CHYnfgAnT3A1GLAcfAcweD5ojRBvdgzifE1Q1KEMhKSEb3BEqD4AcxjczQyEOEc+ACUGcpKOiXxwhybWRyhoJjaGMi0JBAQkj18ZXxGZJfCRwRAqLwwklMgk4m2qgGMQXt9tPNntUNh4O-u4MG4KbEVGJCYEHCZ8DGICGjDe5RU4zSagnaVAr3BRKXg+GQqBLnCR+QymSzWWz2MJA-hCXZXCSEzKHeRFFSVcShKHrakVJKXBlVIRMcgyNmsdlzdZslFc3z4JLkgXgpgicEipgJGQDaWo668mUeeWZRAs1jK7TIUSK9p8xGaA2qOT9dgsPowUa1A1ZUXEA4tAya1Fy7kDB3YC2wHB8Z2q4jq23qzorH1+jaOwOaCh5NVeYlhyC+510UQDWOaIjsT1gJO+2qZzIIosOrDhMZFnDSIsmoZyoZWumOjybSXN9PsNPtoRVi7NHm9uOt4dCjVVzl9uQRpDTeMgFASaPFr1AlMLufZhdxLe5-M1bdLhGLzKOivtE-VzQnut9BuWtZCWdZi4TQcbl8SZ-zkXfrd-xUnx3bQSXfS9tEvMdfx3TlwOnZ0UmkZcUm0ZdQ29ZMI0QrMBhQ10c3oPMMILcBKCPApULPKp2jww1SJAuI73NRtH1I9wQLgIkNWw8EeOXEUeK3QTAPohViT2LiBLI3jpMSYV1lo74sEUxU7DbA4kjbDxiQAOQQMAZj4OwMlbdVtPAPSDPwDtwW7fiFIk3jkXbaJ4V8JEES6aEBOcromS8g98AmO0gqwMsWjsULi3YKLzP8DELHWWKLjBHlIrfV9RHcPR0UCMZYukKLbzNQYH1GAAjU4JWIJgvzAQj8HoeQAA9TgwZSMCQUjnHAbUKhAABJABhAAdABnAaADsAAcTAscaABEAEsAHt9HGoazCMABbaalsm6o+BW-rFEyCocCQZinEeBx6GFU5MiOk7y3AMpiDoIEbuu7wRDKb53tUGYKA++YZWIPhcgegAxCAmoWdgeBAKHIg4ABHEwOEmo4AE8+CAA)
