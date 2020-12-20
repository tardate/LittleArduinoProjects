# #576 Spray Booth

Building a $10 spray booth for light airbrush spray painting and soldering.

![Build](./assets/SprayBooth_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/KVj_xVcu82s/0.jpg)](https://www.youtube.com/watch?v=KVj_xVcu82s)

## Notes

Quality commercial spray booths can be quite expensive (starting from over $125 locally),
but they can be value for money, offering strong airflow and quality construction.

But perhaps a more modest solution will suit my more modest needs - basically for fume extraction for soldering
and light, small scale airbrush spray painting.

## Inspiration

There are many examples of DIY spray booth construction just an internet search away.
Here are a few I checked out.

DIY Airbrush Spray Booth Setup & Build (frostedsnow)

[![clip](https://img.youtube.com/vi/yqqo4WGslcM/0.jpg)](https://www.youtube.com/watch?v=yqqo4WGslcM)

I Finally Built Myself an Airbrush Spray Booth!

[![clip](https://img.youtube.com/vi/Tys4N1h5BmE/0.jpg)](https://www.youtube.com/watch?v=Tys4N1h5BmE)

Airbrush Spray Booth Build

[![clip](https://img.youtube.com/vi/8icaEXJeAQw/0.jpg)](https://www.youtube.com/watch?v=8icaEXJeAQw)

Make a foldable painting booth!

[![clip](https://img.youtube.com/vi/3J6s1o6RNNk/0.jpg)](https://www.youtube.com/watch?v=3J6s1o6RNNk)

## Construction

OK, I'm going super cheap. My only new purchase was the fan (~$3) and filter ($2), the rest scavenged from parts bins and the trash:

* an old cardboard box 20cm (H) x 27cm (W) x 43cm (L)
* 120x25mm 12V DC brushless fan (1800rpm, probably only about 60cfm)
* Daiso 20cm x 20cm ventilation port adhesive filter
* 36 LEDs - cool white 12V LED strip
* 18 LEDs - warm white 12V LED strip
* 12V 1A+ power adapter
* 2 panel-mount SPST switches
* 5.5mm x 2.1mm panel-mount DC jack
* some wire
* some masking tape
* a small plastic project case for the junction box

Testing the components:

* the LEDs draw about 260mA at 12V. The mix of cool and warm white produces a very clear and comfortable light.
* the fan draws about 290mA at 12V. It isvery quiet - acoustically and electrically. No voltage spikes at startup or stop, so no need for additional smoothing and supression components.

Thus a very simple circuit:

![Breadboard](./assets/SprayBooth_bb.jpg?raw=true)

![Schematic](./assets/SprayBooth_schematic.jpg?raw=true)

Inside the junction box:

![build_1_control_box](./assets/build_1_control_box.jpg?raw=true)

Rear view with fan and junction box attached:

![build_2_rear](./assets/build_2_rear.jpg?raw=true)

## Exhaust/Ventilation Considerations

There are three main factors to consider:

* airflow (volume/time)
* filtering requirements
* where and how to vent the exhaust

Actual requirements will depend on the the toxicity and volume of aerosols being released.

Since I am only dealing with low volumes of solder flux fumes and generally non-toxic water-based acrylic paint, I'm keeping this simple and probably under-engineered:

* airflow: I've seen 200cfm+ being mentioned as ideal for airbrush work. For now I'm using a very quiet 120x25mm DC brushless fan that only moves about 60cfm)
* filtering: since I'm not dealing with high volumes of toxic material, my main concern is supressing dust and paint so I'm using a cheap household grade filter
* vent: I don't live in a house or climate that allows easy direct venting to the outside, so this is strictly for indoor use and only to move fumes from the immediate vicinity

If I needed to upgrade this to deal with larger volumes of fumes or more toxic materials, I would probably (a) find another place to do this other than in the home and/or (b) replace the exhaust system with an industrial [inline fan](https://shopee.sg/4-Inch-Silent-Extractor-Duct-Hydroponic-Inline-Exhaust-Industrial-Vent-loganberries-i.152911194.6368162245) with ducting to extract and vent to the outdoors.

Some typical DC brushless fan specs:

| size     | Speed   | Air Flow           | Noise (dBa) |
|----------|---------|--------------------|-------------|
| 40x10mm  | 5000RPM | 5CFM , 0.14m3/min  | 33dBa |
| 50x10mm  | 4500RPM | 7CFM , 0.23m3/min  | 32dBa |
| 60x25mm  | 3600RPM | 22CFM , 0.62m3/min | 31dBa |
| 80x25mm  | 3000RPM | 43CFM , 1.22m3/min | 31dBa |
| 120x25mm | 2000RPM | 70CFM , 2.00m3/min | 33dBa |


## Credits and References
