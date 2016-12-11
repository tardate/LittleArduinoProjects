# #316 QSOPBreakout

All about soldering and the Boldport Club QSOP breakout board.

![Build](./assets/QSOPBreakout_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

The QSOPBreakout was a special (read: beautiful!) board produced for the [BoldportClub](../) to help members practice
QSOP-24 soldering techniques for the [Touchy](../Touchy) project.

QSOP: Quarter-size small-outline package, with pin spacing of 0.635mm.

This is not a project in its own right, but I thought might be worthwhile using this as an excuse to consolidate
everything I've learned so far regarding soldering techniques.

And secondly, perhaps there is something useful I can do with the QSOPBreakout board after all ..
other than use it as a breakout board of course. And it turns out there is .. see the [SolarPendulum](./SolarPendulum)!

## All about Soldering

It is worth acknowledging that there are two potentially conflicting perspectives on soldering:

* it's a purely functional manufacturing process
* it is an essential craft in the creative process

Most of the time, a good solder joint is all about mechanical and electrical conformity with the specification.
Repeatability, quality control and inspectability are paramount.

But for hobbyists, artists and small-batch manufacturing, other considerations such as aesthetics may be more important.

And if you've been around the Boldport Club, then perfect shiny solder domes may be the most important thing of all;-)

Some other projects that touch on soldering techniques:

* [LEAP#258 Electronics101/ClapSwitchKit2](../../Electronics101/ClapSwitchKit2) - kit build which I used to experiment with "perfect solder dome" technique
* [LEAP#171 Electronics101/SMDPracticeBoards](../../Electronics101/SMDPracticeBoards) - documenting a few other SMD practice boards that I've used


## Functional Soldering

What's the secret to good soldering?
It seems it is really just practice, and recognising that **everything** can make a difference:

* thermal mass of the iron
* thermal mass of the board/component/traces being soldered
* iron temperature control
* tinned, suitable iron tip
* flux
* solder quality
* solder composition
* soldering technique
* cleanliness/preparation of the board
* substrate composition

As long as you have an iron with good temperature control (or at least known temperature), then the factors I've found most significant are:

* the solder you use
* keeping the iron tip clean/tinned/usable

Regarding the solder:

* lead-free solder is well-known to produce "dull" but sound joints
* the addition of silver (say 2%) helps both leaded and unleaded solder produce shiny joints
* 63Sn/37Pb is eutectic and has almost immediate phase change from liquid to solid. This is great for manufacturing but appears to lead to dull joints as they crystalize.
* the quality of the solder and the flux can vary widely depending on the source

Bottom line: if you are not easily getting great solder joints, it is wise to first try another solder stock before blaming your iron our your technique.


## Soldering for a Higher Purpose

### Perfect Solder Domes

At first, I had real trouble making smooth symmetrical domes. I'd always end up with "meringue tips" when I drew the iron away.
The technique that seems to work best for me is:

* make sure the iron isn't overloaded with solder
* withdraw the iron by first pulling down and around the nearside of the solder joint, nudge in a little then withdraw smoothly

This sounds more like icing a cake!

### Making Shiny Domes

So now I'm getting decent domes (most of the time) that are electrically and mechanically sound. But they are rarely shiny.

"Shiny" is not usaully a QA issue for solder points (advice abounds on how it is not important).
This is not to be confused with dry joints, that will be both dull and flakey/crystaline.

Google delivers many opinions, for example:

* [Why aren't my solder connnections shiny and perfect?](http://www.strat-talk.com/threads/why-arent-my-solder-connnections-shiny-and-perfect.143458/)
* [lead free soldering - Why are some joints shiny?](http://www.eevblog.com/forum/projects/lead-free-soldering-why-are-some-joints-shiny/)

The main advice for why solder points are not shiny seems to boil down to one or more of the following:

* unleaded solder "rarely produces shiny solder joints"
* no Silver (Ag) in the solder - especially lead free
* iron is too hot
* iron is too cold (but may be confused with dry joint issues)
* cooling too fast/airconditioning/cold-board
* contamination
* not enough flux
* disturbed before cooled

In other words, lots of theories!

So I ran some tests:

* I'm using [WL-0510 B-1 0.5mm 63Sn/37Pb](http://www.dx.com/p/wlxy-wl-0510-b-1-0-5mm-tin-solid-solder-wire-reel-spool-silver-262916#.WAjGsZN97XE)
* I tested with a range of iron temperatures from 250˚C to 325˚C
* with A/C (24˚C) and without (probably heading to 27˚C)
* with and without additional flux

... and I get pretty much the same result all the time: a nice shiny ball when I remove the iron, then as it cools, it gets to a point when
the ball instantly frosts over and I end up with a "dull" solder point.

It seems pretty clear that it is oxidizing at the phase-change from liquid to solid. Not sure what to try next to control this...

... except elbow grease;-) Turns out that with a bit of polish (using solder-station copper wool), I get some of the shine back.

So after a bit more research, I am suspecting the dullness created during the phase change from liquid to solid
is due to the eutectic property of 63Sn/37Pb. As you can see in the phase diagram below, 63/37 is the alloy
with almost perfect eutectic properties (meaning it goes straight from liquid to solid without passing an intermediate plastic phase).

[![phasediagram](http://www.inlandcraft.com/uguides/ug_images/tip-care/phasediagram.jpg)](http://www.inlandcraft.com/uguides/tipfailure.htm)

### REALLY Shiny Domes

Since everything I tried so far hadn't made much difference (temperature, technique, aircon),
the only thing left to try is different solder.

So I got hold of some [Pro'sKit 9S002 Solder](https://www.aliexpress.com/item/Pro-sKit-9S002-Solder-Wire-W-2-AG-17G/32428346399.html) (62% Sn, 37% Pb, 2% Ag) ... and the difference is amazing:

* it creates "domes" with hardly any effort
* and they are all nice and shiny

Here's a side-by-side comparison using the same iron and tip, and both at 275˚C.

* on the left: 62Sn/37Pb/2Ag. Soldering is a breeze, and the results are perfectly formed and shiny
* on the right: 63Sn/37Pb. Making domes is "hard work" and they rarely turn out shiny

![solder_comparison2](../../Electronics101/ClapSwitchKit2/assets/solder_comparison2.jpg?raw=true)

I'll need to do some more tests to determine if the problems I was originally seeing are typical of
a 63Sn/37Pb formulation, or if perhaps I just have some very poorly manufactured 63Sn/37Pb.


## Construction

![Build](./assets/QSOPBreakout_front.jpg?raw=true)

![Build](./assets/QSOPBreakout_rear.jpg?raw=true)

## Credits and References
* [QSOP and 0805 breakout and soldering practice board](http://www.boldport.club/shop/product/437246682) - in the Boldport Shop
* [Surface-mount technology](https://en.wikipedia.org/wiki/Surface-mount_technology) - wikipedia
* [LEAP#258 Electronics101/ClapSwitchKit2](../../Electronics101/ClapSwitchKit2) - kit build which I used to experiment with "perfect solder dome" technique
* [LEAP#171 Electronics101/SMDPracticeBoards](../../Electronics101/SMDPracticeBoards) - a few more SMD practice boards
