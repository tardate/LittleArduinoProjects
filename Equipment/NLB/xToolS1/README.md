# #779 xTool S1 Laser Cutter

Using the laser cutting services available in Singapore's National Libraries - xTool S1.

![Build](./assets/xToolS1_build.jpg?raw=true)

## Notes

Last year I accidentally discovered that Singapore's library service - the [National Library Board (NLB)](https://www.nlb.gov.sg/main/home) - has been running ["MakeIt" centres](https://www.nlb.gov.sg/main/services/MakeIT-at-Libraries) in their libraries where a range of tools are available to citizens to use (including 3D printers, laster cutters, digital cutters, and sewing machines). This is an amazing service. They don't (yet) have 3D resin printers, but these tools make rapid prototyping readily available to all residents at no cost.

For most of these services, they do require users to first complete a free [starter course](https://go.gov.sg/nlb-makeit-events). These help make sure you can keep yourself safe, and save the machines from damage.

I've completed the training for the laser cutting facilities, so I can now [book](https://makeitsg.simplybook.asia/v2/) and use the devices available at currently 4 of the libraries (Jurong, Punggol, Tampines, Woodlands).

Note: as of July 2025, the xTool S1 units have replaced the [Lionsforge Craftlaser](../LionsforgeCraftlaser/) devices previously available.

### About the xTool S1

The library provides [xTool S1 40W Enclosed Diode Laser Cutter](https://www.xtool.com/products/xtool-s1-laser-cutter) devices.
See the [xTool S1 User Guide](https://support.xtool.com/article/1106),
the English [PDF available here](./assets/xTool-S1-Quick-Start-Guide-en.pdf)
Note: laptops are provided all the required software pre-installed.

Features:

* Switchable laser modules satisfy the processing of almost any material.
* Pin-point™ positioning: 10 times more accurate than single-camera systems.
* Larger bed size than others: 23.93'' x 15.16'' for efficient batch processing.
* AutoPassthrough™ and 3D Curve™ Engraving.
* Class 1 Safety: 5-direction flame detection, emergency stop, lid-open safety stop and laser key lock.
* Available in 40W, 20W, 10W, 2W versions

In practice, the xTool S1 is a huge advance over the previous cutters:

* finely controlled engraving, making it possible to render greyscale images quite accurately
* easy setup
* very quiet and clean
* modern software that can combine engraving, cutting and scoring tasks in a single job

### Specifications (40W)

* Laser Power : 40W
* Spot Size   : 0.08 x 0.10 mm
* Working Speed : 600 mm/s
* Working Area : 19.6" x 12.5" (498 x 319 mm)
* Working Area with Automatic Conveyor Feeder : 18.5" x 118" (470 x 3000 mm) Additional transmission rail is required
* Output Voltage : 25V 11A
* Connection Way : USB/Wi-Fi
* Support XCS System :
    * Phone: Android & iOS
    * Tablet: iPad
    * Computer: Windows 10 or above & macOS
* Software : XCS/Lightburn
* Support File : SVG/DXF/JPG/JPEG/PNG/BMP/TIF
* Product Weight : 20KG
* Product Size :
    * 30.12" x 22.09" x 7.2" (765 x 561 x 183 mm) Excluding riser base
    * 30.12" x 22.09" x 10.55" (765 x 561 x 268 mm) Including riser base

### Software

The [xTool Creative Space software](https://www.xtool.com/pages/software) is a huge improvement over the old Inkscape extensions used to generate separate engraving and cutting [CNC G-code](https://en.wikipedia.org/wiki/G-code).

* Integrated vector editing support
* Integrated laser cutter control
* Runs on Android & iOS, iPad, Windows 10+, MacOS (Intel and Apple M)
* optional Cloud Storage account
* DesignFind: A curated collection of ready-to-edit designs and tutorials
* Material EasySet Library: library covers all xTool machines and materials, tested in our labs to ensure the best result.
* Software Learning Center

Note:

* when importing from SVG, set the source document resolution to 72 DPI. This will ensure that objects remain at the same scale after import.

## Credits and References

* [NLB MakeIT At Libraries](https://www.nlb.gov.sg/main/services/MakeIT-at-Libraries)
    * [NLB MakeIT booking](https://makeitsg.simplybook.asia/v2/)
* [xTool S1 40W Enclosed Diode Laser Cutter](https://www.xtool.com/products/xtool-s1-laser-cutter)
* [xTool Creative Space software](https://www.xtool.com/pages/software)
