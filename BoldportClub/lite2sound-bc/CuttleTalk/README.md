# #420 CuttleTalk

Playing audio from a Boldport Cuttle (Arduino) over LiFi with lite2sound

![Build](./assets/CuttleTalk_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/D7n0T0xKA2Y/0.jpg)](https://www.youtube.com/watch?v=D7n0T0xKA2Y)

NB: or just a short [CuttleTalk clip](https://youtu.be/jYx-Odu2f3g)

## Notes

Now I've built the Boldport lite2sound, time to test it out.
I'm inspired by
[LEAP#417 SimpleSamplePlayer](../../../playground/Audio/SimpleSamplePlayer)
to attempt some LiFi audio transmission by light.

I'm using the Boldport Cuttle (an AVR/Arduino clone) to transmit an audio sample with an LED,
and the Boldport lite2sound as a receiver. The audio out from lite2sound is amplified with
[LEAP#210 TDA7297 Kit](../../../Audio/AudioAmps/TDA7297Kit)

W00t, and it works;-)

## Sampling Some Sound

I've cheekily snaffled a sample from Boldport's [Intro to the Boldport Variety Show!](https://youtu.be/VBJBxnPkQbE)
using [node-ytdl](https://www.npmjs.com/package/ytdl) and [ffmpeg](https://www.ffmpeg.org/) to
capture MP3 audio from the video:


    ytdl https://youtu.be/VBJBxnPkQbE --filter audioonly -o intro.mp4
    ffmpeg -i intro.mp4 -acodec mp3 intro.mp3

I used [audacity](https://www.audacityteam.org/) to clip and clean up a sample,
including re-sampling it at 8kHz and exporting as a WAAV file [saar_from_boldport.wav](./sounds/saar_from_boldport.wav).

Finally, I used the [sample_encoder.rb](../../../playground/Audio/SimpleSamplePlayer/encoder/sample_encoder.rb) Ruby script
to convert the WAV file into the
[sample_saar_from_boldport.h](./sample_saar_from_boldport.h) header file
which is used by the [CuttleTalk.ino](./CuttleTalk.ino) sketch loaded on the Cuttle.

    ruby sample_encoder.rb sounds/saar_from_boldport.wav > sample_saar_from_boldport.h


## Construction

The LiFi broadcast is simply a Cuttle with a high-intensity white LED on pin 11/PB3 and a 220Ω current limiting resistor:

![Breadboard](./assets/CuttleTalk_bb.jpg?raw=true)

![Schematic](./assets/CuttleTalk_schematic.jpg?raw=true)

## Credits and References

* [LEAP#419 lite2sound-bc](../) - main lite2sound-bc project
* [LEAP#210 TDA7297 Kit](../../../Audio/AudioAmps/TDA7297Kit)
* [LEAP#417 SimpleSamplePlayer](../../../playground/Audio/SimpleSamplePlayer)
* [node-ytdl](https://www.npmjs.com/package/ytdl) - A youtube downloader written in Javascript
* [ffmpeg](https://www.ffmpeg.org/)
* [audacity](https://www.audacityteam.org/)
* [..as mentioned on my blog](https://blog.tardate.com/2018/10/leap420-cuttletalk-audio-over-lifi.html)
