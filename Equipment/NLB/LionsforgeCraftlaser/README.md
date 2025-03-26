# #754 NLB Lionsforge Craftlaser

Using the laser cutting services available in Singapore's National Libraries - Lionsforge Craftlaser.

![Build](./assets/LionsforgeCraftlaser_build.jpg?raw=true)

## Notes

Last year I accidentally discovered that Singapore's library service - the [National Library Board (NLB)](https://www.nlb.gov.sg/main/home) - has been running ["MakeIt" centres](https://www.nlb.gov.sg/main/services/MakeIT-at-Libraries) in their libraries where a range of tools are available to citizens to use (including 3D printers, laster cutters, digital cutters, and sewing machines). This is an amazing service. They don't (yet) have 3D resin printers, but these tools make rapid prototyping readily available to all residents at no cost.

For most of these services, they do require users to first complete a free [starter course](https://www.nlb.gov.sg/main/services/MakeIT-at-Libraries). These help make sure you can keep yourself safe, and save the machines from damage.

I've completed the training for the 3D printing facilities, so I can now [book](https://makeitsg.simplybook.asia/v2/) and use the PLA printers available at currently 4 of the libraries (Jurong, Punggol, Tampines, Woodlands).

### About the Lionsforge Craftlaser

The library provides [Lionsforge Craftlaser](https://lionsforge.com.sg/craftlaser-laser-cutter/) devices.
See the [Craftlaser-Product-Info-New-Dec21.pdf](./assets/Craftlaser-Product-Info-New-Dec21.pdf).
Note: laptops are provided all the required software pre-installed.

### Workflow

The [starter training](./assets/makeit-digital-cutting-laser-crafting-starter-session-2024-09-01.pdf) introduced the basic process:

* using [TinkerCAD](https://www.tinkercad.com/) to make a 3D model
* export to SVG
* use [Inkscape](https://inkscape.org/) as the laser G-code generating tool, but can also be used to edit objects.
    * import SVG file
    * adjust stroke width to 1px
    * add text to the object (this will be treated as an engraving)
* export to [CNC G-code](https://en.wikipedia.org/wiki/G-code) for engraving
    * use the "305 Engineering > Raster 2 Laser GCode generator" extension
    * resolution: at least 10px/mm
    * engraving speed: 4000
* export to [CNC G-code](https://en.wikipedia.org/wiki/G-code) for cutting:
    * with object selected, choose "Object to Path"
    * use the "Generate Laser G-code > J Tech PhotonicsLaser Tool.."  extension
* save the engraving and cutting codes to an SD card

Operating the Cutter:

* Adjust Focus Height to 4mm above material
* Engraving Phase:
    * For engraving, adjust the laser intensity knob to 2/9 power
    * Set "Speed mul." to 200%
    * Open the material loading tray when the display reads "Idle"
    * Align your material to the bottom-left corner of the materials tray. Tape down.
    * load the engraving file and execute
* Cutting Phase:
    * For cutting, adjust the laser intensity knob to 2/3 power
    * Set "Speed mul." to 130%
    * load the cutting file and execute

G-code files can be previewed/validated with <https://ncviewer.com/>.

### My Sample Project

The starter course has everyone design and cut a simple name tag.
My project sources:

* [keychain-initial.svg](./assets/keychain-initial.svg) - export from TinkerCAD
* [keychain-final.svg](./assets/keychain-final.svg) - inkscape project
* Engraving code: [E_pg_kc_0001_BWfix_128_gcode.txt](./assets/E_pg_kc_0001_BWfix_128_gcode.txt)
* Cutting code: [C_pg_kc_0001](./assets/C_pg_kc_0001)

### Laser Cutting Design Sources

* <https://www.ponoko.com/free-laser-cutting-files-templates>
* <https://designbundles.net/free-design-resources/free-laser-cutting-files>
* <https://www.creativefabrica.com/subscriptions/graphics/laser-cut-files/>
* <https://www.designfind.com/>
* <https://www.vecteezy.com/>
* <https://crafthousesvg.com/>
* <https://www.printablecuttablecreatables.com/>
* <https://makerflocrafts.com/blogs/craft-library/free-laser-engraving-cutting-files> - listing

## Credits and References

* [NLB MakeIT At Libraries](https://www.nlb.gov.sg/main/services/MakeIT-at-Libraries)
    * [NLB MakeIT booking](https://makeitsg.simplybook.asia/v2/)
* <https://lionsforge.com.sg/craftlaser-laser-cutter/>
* <https://ncviewer.com/>
* <https://en.makercase.com/#/>
