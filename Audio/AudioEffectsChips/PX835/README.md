# #372 PX835 Audio Effects Chip

Figuring out how to use the PX835 "16 Kind of Sound Doorbell Chip" music chip.

![Build](./assets/PX835_build.jpg?raw=true)

Here's a quick demo (if you really want one!)..

[![clip](https://img.youtube.com/vi/57C38rkTg_A/0.jpg)](https://www.youtube.com/watch?v=57C38rkTg_A)

## Notes

The PX835 music chip is usually listed as something like
"16 Kind of Sound Doorbell Chip Music Voice Module For DIY/Toy".

I obtained it from a seller on aliexpress, but I can't find any current listings for the chip on aliexpress.
This chip appears to be identical to one labeled "YSJ-M16" manufactured by
[宇思捷电子 YuSiJie Electronics](https://shop58187273.taobao.com/) and available from their taobao store.
They have around 80 music chip products listed, so I've only just started to scratch the surface with the few chips I've played with so far!

The chip runs on 3V, and is silent at power-on, and supports two input push-buttons (pull-up to V+):

* play next/change song
* repeat last song

It apparently supports a "0.5W to 2W" output. With an 8Ω 0.5W speaker, I got best results with a 47Ω resistor in series.

I owe big thanks to [Ian Wang](https://github.com/whc2001) who found the YSJ-M16 on taobao and provided the list of song titles:

| No |   Title                              |
|----|--------------------------------------|
| 1  | Fur Elise                            |
| 2  | 虹彩妹妹                              |
| 3  | [Ding Dong * 2]                      |
| 4  | Rhythm of the Rain                   |
| 5  | Jingle Bells                         |
| 6  | Romeo and Juliet                     |
| 7  | Love Story                           |
| 8  | 太湖船                                |
| 9  | [Westminster Chime]                  |
| 10 | Oh My Darling Clementine             |
| 11 | We Wish You a Merry Christmas        |
| 12 | Oh Susanna                           |
| 13 | Wiegenlied                           |
| 14 | Silent Night                         |
| 15 | Turkish March                        |
| 16 | [Cuckoo * 3]                         |

![Schematic](./assets/PX835_schematic.jpg?raw=true)

A "found-schematic" for the YSJ-M16 version:

![YSJ-M16](./assets/YSJ-M16.png?raw=true)

The sound generated appears to be a PWM tone:

![scope](./assets/scope.gif?raw=true)

## Credits and References

* [YSJ-M16](https://item.taobao.com/item.htm?id=554080601854) - taobao listing
* [宇思捷电子 YuSiJie Electronics](https://shop58187273.taobao.com/) - taobao store
