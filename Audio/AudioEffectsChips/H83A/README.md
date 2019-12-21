# #362 H83A Audio Effects Chip

Figuring out how to use the H-83A "12 songs" music chip.

![Build](./assets/H83A_build.jpg?raw=true)

## Notes

The H-83A is yet another music chip, this time programmed with 12 tunes - a selection of Chinese poo and folk tunes.
I owe big thanks to [Ian Wang](https://github.com/whc2001) who provided the list of song titles.
I've linked up some examples on YouTube:

| No | Title |
|----|-------|
| 1  | [常回家看看](https://youtu.be/yxcu3cjk27E) |
| 2  | [有一个姑娘](https://youtu.be/jcLIhYfXrs8) |
| 3  | [心太软](https://youtu.be/ZSWeurc1yMw) (Richie Ren!) |
| 4  | [妈妈的吻](https://youtu.be/AmDgzz-_0Ak) |
| 5  | [爱拼才会赢](https://youtu.be/Lrf20rQzhp0) |
| 6  | [月亮惹的祸](https://youtu.be/1YJ8wSH6HBU) |
| 7  | [健康歌](https://youtu.be/21u1_SRIkyI) (purple people eater;-)
| 8  | [涛声依旧](https://youtu.be/S8XyCNtqucg) |
| 9  | [拨浪鼓](https://youtu.be/Gc2DBbQkKz0) |
| 10 | [好日子](https://youtu.be/H74aVKUJmrc) |
| 11 | [读书郎](https://youtu.be/eAjudMl7dqk) |
| 12 | [懂你](https://youtu.be/53JidyqBQWY) |

Ian also has a demo on YouTube (a better recording than mine):

[![clip](https://img.youtube.com/vi/CIWCA4LYstM/0.jpg)](https://www.youtube.com/watch?v=CIWCA4LYstM)

![H83A_chip](./assets/H83A_chip.jpg?raw=true)

## Usage and Schematic

This chip requires very minimal external components:

* push-button switch
* 180kΩ resistor
* speaker (e.g. 8Ω)
* 3-4.5V power

Songs start playing when the switch is pressed. Pressing the switch again will switch tunes.
The song ends after one cycle (i.e. not infinite repeat!)

Volume is very decent without any amplification.

![Schematic](./assets/H83A_schematic.jpg?raw=true)

![Build](./assets/H83A_build.jpg?raw=true)

Here's a demo FWIW. There is a bit of warbling, I think mainly due to imperfect breadboard connections.

[![clip](https://img.youtube.com/vi/mdSMwFA3bzw/0.jpg)](https://www.youtube.com/watch?v=mdSMwFA3bzw)


## Credits and References

* [5PCS 12 Kind of Songs Sound Music IC Voice Chip Module for DIY/Toy Integrated Circuit 3-4.5V](https://www.aliexpress.com/item/5PCS-12-Kind-of-Sound-Music-IC-Voice-Chip-Module-for-DIY-Toy-Integrated-Circuit-3/32658454214.html) - from aliexpress seller
* [..as mentioned on my blog](https://blog.tardate.com/2017/12/leap362-h-83a-12-song-music-chip.html)
