# #634 Audio IC Users Handbook

Book notes: Audio IC Users Handbook, by R.M. Marston. First published January 1, 1997.

[![Build](./assets/audio-ic-users-handbook_build.jpg?raw=true)](https://amzn.to/421guOs)

## Notes

See also:

* [amazon](https://amzn.to/421guOs)
* [goodreads](https://www.goodreads.com/book/show/882813.Audio_IC_Users_Handbook)

## Contents

| Chapter                                    | LEAP? |
|--------------------------------------------|-------|
| 1. Audio Basics                            |  |
| 2. Op-amp audio processing circuits        |  |
| 3. Dedicated audio processing IC circuits  |  |
| 4. Audio Pre-amplifier circuits            |  |
| 5. Audio power-amplifier circuits          |  |
| 6. High-power audio amplifiers             |  |
| 7. LED bar graph displays                  |  |
| 8. Audio delay-line systems and circuits   |  |
| 9. Power supply circuits                   |  |
| 10 End notes                               |  |

## 3. Dedicated audio processing IC circuits

| chip            | description                       |
|-----------------|-----------------------------------|
| MC3340P         | electronic attenuator             |
| NE570/571       | dual compandor                    |
| LM1398          | stereo dynamic noise reduction    |
| LM1037          | dual 4-channel analogue switch    |
| CMOS 4016/4066  | high speed digital switch         |
| 74HC4052        | dual 4-channel anaog multiplexer  |
| LM1036          | stereo dc-controlled tone/vol/balance |
| LMC1983         | digital control 3-channel stereo selector and tone/volume control |
| MF10C           | dual switched-capacitor filter    |

## 4. Audio Pre-amplifier circuits

* LM387 dual pre-amp IC
* LM833 dual audio op-amp

## 5. Audio power-amplifier circuits

ideal power amp can deliver power to external load (speaker) without
significant distortion and without overheating or consuming excessive quiescent current.

### Class A

* single BJT
* input heavily forward biased
* simple
* good low-distortion
* high quiescent current

### Class B

* pair unbiased transistors
* near zero quiescent current
* very high levels of signal distortion

### Class AB

* eliminate class B cross over distortion with slight forward bias
* modest quiescent current

### Practical Op-Amp Circuits

* LM386
* LM381
* TDA7052
* LM388
* TDA2822
* LM1877
* LM380/384
