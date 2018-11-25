# #435 BEAM

A quick survey of the BEAM (Biology, Electronics, Aesthetics and Mechanics) field.

![Build](./assets/BEAM_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

[BEAM (Biology, Electronics, Aesthetics and Mechanics) Robotics](https://en.wikipedia.org/wiki/BEAM_robotics) primarily use simple analogue circuits in their design.
The term dates back to the 1990's, and introduced an era of great creativity in adapting simple circuits to similate emergent behaviour.

The fad for BEAM had largely come to pass by the time I discovered it in the past few years, overtaken by advances in low-power processing and machine learning that make
BEAM-style mechanisms a little quaint. That's a bit sad, hence my ambition to re-create some BEAM classics here.

The [BEAM wikipedia](https://en.wikipedia.org/wiki/BEAM_robotics) page is a goo jumping off point for learning more.
Unfortunately, much of the work that has been done in this field is lost to the internet `/dev/null`, bar a few examples snaffled by archive.org.
The key surviving resources appear to be:

* [solarbotics.net](http://solarbotics.net/) - principal reference site for BEAM-related information
* [solarbotics.com](https://solarbotics.com/) - online retailer for BEAM-related components and kits


### Types

BEAM circuits may be classified by what they react to;

* Audiotropes - react to sound sources.
* Phototropes ("light-seekers") - react to light sources.
* Radiotropes - react to radio frequency sources.
* Thermotropes - react to heat sources.


## Mechanisms

The taxonomy of BEAM circuits is generally organised as follows:

* Sitters: Unmoving robots that have a physically passive purpose.
    * Beacons: Transmit a signal (usually a navigational blip)
    * Pummers: Display a "light show".
    * Ornaments: A catch-all name for sitters that are not beacons or pummers.
* Squirmers: Stationary robots that perform an interesting action (usually by moving some sort of limbs or appendages).
    * Magbots: use magnetic fields for their mode of animation.
    * Flagwavers: Move a display (or "flag") around at a certain frequency.
    * Heads: Pivot and follow some detectable phenomena, such as a light (These are popular in the BEAM community. They can be stand-alone robots, but are more often incorporated into a larger robot.).
    * Vibrators: Use a small pager motor with an off-centre weight to shake themselves about.
* Sliders: Robots that move by sliding body parts smoothly along a surface while remaining in contact with it.
    * Snakes: Move using a horizontal wave motion.
    * Earthworms: Move using a longitudinal wave motion.
* Crawlers: Robots that move using tracks or by rolling the robot's body with some sort of appendage. The body of the robot is not dragged on the ground.
    * Turbots: Roll their entire bodies using their arm(s) or flagella.
    * Inchworms: Move part of their bodies ahead, while the rest of the chassis is on the ground.
    * Tracked robots: Use tracked wheels, like a tank.
* Jumpers: Robots which propel themselves off the ground as a means of locomotion.
    * Vibrobots: Produce an irregular shaking motion moving themselves around a surface.
    * Springbots: Move forward by bouncing in one particular direction.
* Rollers: Robots that move by rolling all or part of their body.
    * Symets: Driven using a single motor with its shaft touching the ground, and moves in different directions depending on which of several symmetric contact points around the shaft are touching the ground.
    * Solarrollers: Solar-powered cars that use a single motor driving one or more wheels; often designed to complete a fairly short, straight and level course in the shortest amount of time.
    * Poppers: Use two motors with separate solar engines; rely on differential sensors to achieve a goal.
    * Miniballs: Shift their centre of mass, causing their spherical bodies to roll.
* Walkers: Robots that move using legs with differential ground contact.
    * Motor Driven: Use motors to move their legs (typically 3 motors or less).
    * Muscle Wire Driven: use Nitinol (nickel - titanium alloy) wires for their leg actuators.
* Swimmers: Robots that move on or below the surface of a liquid (typically water).
  * Boatbots: Operate on the surface of a liquid.
  * Subbots: Operate under the surface of a liquid.
* Fliers: Robots that move through the air for sustained periods.
  * Helicopters: Use a powered rotor to provide both lift and propulsion.
  * Planes: Use fixed or flapping wings to generate lift.
  * Blimps: Use a neutrally-buoyant balloon for lift.
* Climbers: Robot that moves up or down a vertical surface, usually on a track such as a rope or wire.

There are quite a few categories that perhaps should be added to this list, for example:

* Squawkers: robots that respond audibly to a particular stimulus
* Flashers: robots that respond visualy to a particular stimulus


## Examples

Now that I have the BEAM terminology in mind, I realise that quite a few [Boldport](https://github.com/tardate/LittleArduinoProjects/tree/master/BoldportClub) projects
probably belong in the taxonomy, for example:

* [LEAP#409 conehead](https://github.com/tardate/LittleArduinoProjects/tree/master/BoldportClub/conehead) - a Phototrope sitter (better yet: a squawker); chirps in response to light
* [LEAP#284 TheGent](https://github.com/tardate/LittleArduinoProjects/tree/master/BoldportClub/TheGent) - a Phototrope sitter (better yet: a flasher); flashes it's LEDs in response to light

And now for some new BEAM builds:

* [LEAP#436 Vivian](./Vivian) - a vibrobot using a classic solar-powered FLED circuit enhanced with a QX5252/YX805 solar LED driver.

## Credits and References
* [BEAM Robotics](https://en.wikipedia.org/wiki/BEAM_robotics) - wikipedia
* [BEAM Reference Library](http://solarbotics.net/library.html)
* [solarbotics.net](http://solarbotics.net/) - principal reference site for BEAM-related information
* [solarbotics.com](https://solarbotics.com/) - online retailer for BEAM-related components and kits
