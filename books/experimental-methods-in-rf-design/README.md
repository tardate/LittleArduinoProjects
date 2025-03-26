# #651 Experimental Methods in RF Design

Book notes: Experimental Methods in RF Design, by Wes H. Hayward, Rick Campbell, Bob Larkin. First published February 1, 2003.

[![Build](./assets/experimental-methods-in-rf-design_build.jpg?raw=true)](https://amzn.to/3FkKj3Z)

## Notes

See also:

* [amazon](https://amzn.to/3FkKj3Z)
* [goodreads](https://www.goodreads.com/book/show/2386153.Experimental_Methods_in_Rf_Design)

## Contents

### Chapter 1, Getting Started

1.1—Experimentation, “Homebrewing,” and the Pursuit of the New: This is a brief philosophical comment regarding our views on the subject at hand.

1.2- Getting Started-Routes for the Beginning Experimenter: We begin with a discussion of construction methods, which emphasize breadboarding, or one-of-a-kind building.

1.3—Some Guidelines for the Experimenter: A collection of hints and pitfalls related to success in experimenting is presented, observations that we have (sometimes painfully) made.

1.4-Block Diagrams: This section briefly describes the block diagrams used through the book for the systems we build

1.5— An IC Based Direct Conversion Receiver: This simple receiver is a wonderful first project, offering good performance on any of several bands.

1.6- A Regenerative Receiver: Many readers will certainly ask "why would anyone ever build a "regen" receiver in this modern age. There are many answers, but the strongest is that the mere act of using such equipment is an experimental experience. The philosophy of adapting the design to fit available parts is in keeping with the rest of the book.

1.7-An Audio Amplifier with Discrete Transistors: This is a simple design that folks can build to drive a small speaker when they don't have an audio IC available.

1.8 A Direct Conversion Receiver Using a Discrete Component Product Detector: This design shows a simple DC receiver using a differential amplifier as the detector. The local oscillator is varactor diode tuned and the model shown uses surface mount technology (SMT.)

1.9—Power Supplies: This section address the need of powering the equipment and test equipment used by the beginning experimenter. Some simple supply designs are offered that use readily available regulators.

1.10-RF Power Measurements: We will shortly be presenting a transmitter, so we need a way to measure radio frequency power. Power meters using a termination and a diode peak detector are offered. Some dual designs are suggested, allowing measurement over a wider range. An RF probe is also presented that can be used with a traditional VTVM or FET equivalent.

1.11-A First Transmitter: This section follows the design of a simple transmitter, here operating on the 40 meter band. The design starts with a crystal oscillator. After building and testing this, we add a buffer amplifier. The output of this stage is studied and measured. Then a 200 milliwatt output amplifier is added to realize a low power transmitter that is still suitable for use on the air.

1.12—A Bipolar Transistor Power Amplifier: A simple "brick" is built to bring the output up to a much more practical level of 2 watts. An inexpensive transistor is used

1.13—An Output Low Pass Filter: The transmitter just described may not be useable on the air owing to excessive harmonic output. So, we built a filter that can be added at the output. This filter is built as an isolated module so it can be used with other designs. This section concludes the transmitter by adding shaped keying, transmit/receive switching, a power output control, a sidetone oscillator, a spot switch, and some tuning in the oscillator to achieve some VXO action. This transmitter has been used with the IC Based Direct Conversion Receiver described above for contacts on the 40 meter band.

1.14—About the Schematics in this Book: We have made a few departures from standard ARRL practice. Probably the most significant one is that we try to put a lot of data directly into the drawing, including coil data when possible. This allows us to bypass the parts lists otherwise used.

### Chapter 2, Amplifier Design Basics

This chapter is the first in four aimed at the study of fundamental circuit types, with this chapter devoted to amplifiers. This follows the format of Solid State Design for the Radio Amateur, SSD, where modeling and amplifier basic design ideas were integrated with some practical examples.

2.1-Modeling Simple Solid State Devices: The chapter begins with some basic ideas of modeling, illustrated by the junction diode. The diode is modeled as a perfect diode in series with a battery and resistance. A more complicated mathematical expression is then offered. A small-signal model is contrasted with the large signal one. The diode behavior is then extended to generate a bipolar transistor, modeled as a combination of diodes and a dependent current source. Small signal models are derived for the transistor. The large signal model is now applied, used to analyze methods for biasing the part. Similar discussions are presented for the junction field effect transistor.

2.2-Amplifier Design Basics: Amplifiers are now studied with small signals. We use the models to calculate voltage gain for some simple circuits.
Input and output resistance are also calculated. The discussion is extended to FETs and to some high frequency effects.

2.3—Large Signal Amplifiers: The basic models used for biasing can also be used for analysis of circuits with large or practical (real) signal levels. These are the levels we might find well into a receiver system, or in a transmitter.
Some distortions are studied, illustrated with a simple emitter follower. A Class-A power amplifier is then considered.

2.4- Gain, Power, dB, and Impedance Matching: These parameters are all defined, definitions needed throughout the book.
The reflection coefficient is
introduced.

2.5—Differential Amplifiers and the Op-Amp: A special circuit type is presented, the differential amplifier. One ideal diff-amp is the op-amp, a form now discussed. The basic rules for application are presented.

2.6- Undesired Amplifier Characteristics: Some undesired characteristics of any small signal amplifier are presented. These include noise, gain compression, harmonic distortion, and intermodulation. The intercept idea is introduced.

2.7-Feedback Amplifiers: We now present one of our favorite circuits, the single transistor "feedback" amplifier. This is presented with design equations that allow the experimenter to design his or her own versions.
Some advanced forms are presented. Practical design information is presented. A program on the book CD, FBA.EXE, also considers feedback amplifiers. In that analysis, a more refined (hybrid-pi) model is used for the bipolar transistor.

2.8—Bypassing and Decoupling: This section discusses the critical, and often neglected problems of bypassing and decoupling. The differences between the two are emphasized. The problems with most bypass capacitors is modeled by a small inductor in series the larger capacitor. The problems of paralleled bypass capacitors are examined.

2.9—Power Amplifier Basics: The next section deals with RF power amplifiers, beginning with a discussion of amplifier operation class.

2.10-Practical Power Amplifiers: Several practical amplifier types are presented, augmented by example circuits. The information is expanded from bipolar transistors to include power MOSFET types, again with practical examples for both CW and SSB use. Experimental technique is emphasized.
Some efficiency considerations are given.

2.11-A 30-W, 7-MHz Power Amplifier: The chapter is finished with a practical example, an amplifier capable of over 30 watts output at 7 MHz or higher from a $1 HEXFET.

### Chapter 3, Filters and Impedance

3.1-Filter Basics: This chapter begins with some filter definitions.

3.2—The Low-Pass Filter-Design and Extension: A discussion of low pass filters. They are basic to all other filter types, but are important in themselves.
Design equations are given for some Butterworth and Chebyshev low pass filters, and are illustrated with examples. A variety of transformations are considered, allowing a low pass design to be converted into a high pass, a bandpass, and even a band stop filter.
Note that the numeric details here are
simplified for the reader by one of the included Windows © software programs, LoWH1.EXE.

3.3—LC Bandpass Filters: This section introduces the idea of Q and deals with
LC bandpass filters as coupled resonators or tanks. The emphasis is on the design of double and triple tuned circuits with practical, @ characterized components. Programs DTC.EXE and TTC.EXE simplify double and triple tuned bandpass filters designs. Higher order designs are possible with the same software.

3.4 Crystal Filters: The next section deals with quartz crystals, their evaluation and modeling, and their application as bandpass filters. Simple circuits are presented for practical measurements as well as simple filter circuits. This is expanded to the design of more complicated crystal bandpass filters.
Filter shape is discussed with regard to ringing. This section of the
chapter is augmented by Windows © programs XLAD.EXE and
FINETUNE.EXE, which expedite the crystal filter design procedures.

3.5— Active Filters: RC active filters appear in the next section. Design equations are given for several simple types. The all pass filter (phase shifting network) is briefly discussed and applied to an unusual analog filter type, a FIR filter, usually only considered possible with digital signal processing.

3.6- Impedance Matching Networks: This section begins with a discussion of the directional nature of impedance in a circuit. The classic L, pi, and Tee networks are discussed with included design equations. Transmission lines then provide impedance matching, followed by ideal transformers using power iron and ferrite cores. The ferrite loaded transmission line transformer 1s presented, including some popular forms using multiple cores. The section then moves to the discussion of networks with more than just two ports.
These include the splitter/combiner, diplexers, directional couplers, and quadrature couplers.

### Chapter 4, Oscillators and Frequency Synthesis

The vital function of generating a signal for use in transmitters and receivers is the basis for this chapter.

4.1-LC Oscillator Basics

* The chapter begins with descriptions of an oscillator circuit as an amplifier combined with a single tuned circuit. We then ask the question: Will it oscillate? This moves to a discussion of some basic LC oscillator types.
* The similarities of the Colpitts and Hartley forms are emphasized.
* The Colpitts variations of the Clapp, Seiler, and Vackar are presented.

4.2—Practical Hartley Circuits and Oscillator Drift Compensation

* The next section presents the Hartley as an example and considers the problem of temperature compensation.
* See [LEAP#418 CommonEmitterHartley](../../Electronics101/Oscillators/CommonEmitterHartley/)

4.3—The Colpitts and Other Oscillators

* Practical designs are presented that can be scaled to a needed frequency.
* Circuits considered include the Colpitts, Clapp, Seller, and Vackar.

4.4— Noise in Oscillators: The underlying concepts are presented.
Mathematical forms are available for those interested. Noise is also illustrated with intuitive discussion and some circuit examples that can be quickly built to be examined by the experimenter. One is a very good (low noise) crystal oscillator while another is a very poor (noisy) circuit.

4.5— Crystal oscillators: The discussion is practical, including several examples of VXO circuits, for they are very popular among experimenters.

4.6—Voltage Controlled Oscillators

* The VCO is now the most common oscillator form. This results from synthesizers having replaced free running LC oscillator systems. A related problem is that mechanically variable capacitors are disappearing. The VCO is illustrated with some practical circuits where we have measured both tuning frequency Vs control voltage and oscillator noise. One circuit is used later in the book in a QRP transceiver.
* see [LEAP#273 Voltage Controlled Oscillator](../../Electronics101/VoltageControlledOscillator/)

4.7—Frequency Synthesis: The chapter moves toward synthesis with a discussion of mixers that operate as phase detectors. This is presented in experimental terms with measurements we performed. The characterized phase detector is then combined with a VCO and an op-amp that functions as a
"loop filter" to generate a phase locked loop, PLL. This is a traditional 2nd order loop. A sidebar presents an even simpler 1st order loop. Next, a practical example, a 1-on-1 offset PLL is built. This was a 14 MHz VCO that was phase locked to a 1.5 MHz reference. The discussion continues with PLLs using programmable digital frequency dividers. The examples use general purpose logic components, but can be extended to include special purpose digital chips. Direct digital synthesis, DDS, is briefly presented and emphasizes the basic character of the function that will generate spurious outputs. A measured example is presented

4.8—The Ugly Weekender, MK-II, A 7-MHz VFO Transmitter: The ideas presented earlier in the chapter are now illustrated with a practical project, a version of a 1981 design, the "Ugly Weekender." This 1.5 watt QRP transmitter uses an LC Hartley oscillator.

4.9 A Digital Dial: A simple frequency counter using inexpensive HC type
CMOS integrated circuits. This circuit will function to nearly 50 MHz with modest current, simplicity, and low cost.

4.10- A General Purpose VXO-Extending Frequency Synthesizer: The chapter ends with a PLL frequency synthesizer. This design achieves high tuning resolution by programming of the reference divider ratio.

### Chapter 5, Mixers and Frequency Multipliers

5.1-Mixer Basics

* Our study of mixers begins with a JFET example.
* After DC characterization, the FET is used as a mixer. Mixing action results from the nonlinear behavior of the active FET while linear behavior produces no mixing. A diode is applied as a switching mode mixer, illustrating the other common form of mixer circuit.
Mixer specifications and the related measurements are then considered. The familiar gain and impedance specifications are augmented with parameters for spurious responses, a major mixer problem. Many of the same parameters that describe amplifiers can be applied to mixers. These include noise figure, gain, and intercepts.
* see [LEAP#326 Mixers](../../Electronics101/Mixers/)

5.2—Balanced Mixer Concepts

* We now begin a move toward practical circuits with a discussion of balance mixer concepts.
* JFET, MOSFET, and diodes are all presented in balanced mixers.
* See [LEAP#327 RF Diode Ring Mixer](../../Electronics101/Mixers/RFDiodeRing/)

5.3—Some Practical Mixers: The next section delves further with a discussion of the Gilbert Cell mixer. This is illustrated not only with off the shelf integrated circuits, but with a version built from discrete components. We present measured results for conversion gain, noise figure, intercept (third order), and even spurious responses. Single ended mixers are considered that use dual gate MOSFETs and cascode connected JFETs. Next, diode ring mixers are presented in more detail with emphasis on the problems of proper termination. This is extended to high level mixers, including an interesting mixer using four MOSFETs.

5.4- Frequency Multipliers: After a brief discussion of single ended bipolar and JFET multiplier designs, diode circuits are considered. The popular balanced diode frequency doubler is characterized with measured data. A new
"twist" on this classic circuit affords slightly higher output power. Some innovative frequency triplers are then presented, designs that offer very low noise. Finally, digital integrated circuits are considered for odd order multipliers.

5.5— A VXO Transmitter Using a Digital Frequency Multiplier: One of the multipliers discussed uses a digital divider to generate a square wave rich in odd harmonics of half of the input frequency. The resulting output signals are not harmonics of the input, and are on frequencies well away from the input.
This "multiplier" with a factor of 3/2, 5/2, etc, is a near ideal isolation circuit.
A transmitter project is presented using this concept.

### Chapter 6, Transmitters and Receivers

Having examined fundamental components, we now consider ways to put those parts together to build effective receivers and transmitters. The signal forms that interest us include CW, AM, DSB, SSB, and FM. The interest in AM is mainly because it is a step on the road toward SSB. FM is included only for completeness.

6.0-Signals and the Systems that Process Them: The chapter begins with a mathematical examination of the various signal types, and block diagrams of the equipment we might use to generate the signals. Readers without an interest in mathematical things may well wish to skip this first section.

6.1-Receiver Fundamentals: We begin with a look at commonly available headphones, which are probably the most effective way to translate the electrical signals from a receiver into audio energy that we can hear. The underlying question asks how much signal power is needed to drive headphones to a useful level. This will allow us to design receivers that we can use to listen to signals. The noise limits of the antenna are easily reached in an experimental direct conversion receiver built to illustrate the concepts. This leads us to a discussion of receiver minimum detectable signal (MD) and noise figure.
The role of rf amplifiers in determining noise figure and MDS now comes into the picture. Some typical RF amplifiers are presented, and discussed with regard to optimum design. A common gate JFET amplifier emphasizes that the amplifier with an input impedance match for best gain is not usually that producing lowest noise figure.

6.2—IF Amplifiers and AGC: IF amplifiers are a critical part of most superheterodyne systems. Several methods are presented and discussed. Special emphasis is given to amplifier schemes that fit with component types that are still available to the experimenter. A complete IF system will usually include some automatic gain control, or AGC, so envelope detectors are needed. Some detection schemes are presented. They are then combined with the IF amplifiers and DC amplifiers to form complete IF systems suitable for receivers.

6.3—Large Signals in Receivers and Front End Design: We now examine the affects of large signals in a receiver front end. This leads to discussion of receiver dynamic range as well as intercepts. The viable mathematical methods are presented that allow a multiple stage system to be investigated for cascaded noise figure and cascaded third order intercepts. The methods can also be applied through CASCADE.EXE, a Windows © program included with the book CD. Several receiver designs are considered to illustrate the concepts.
A practical, general purpose monoband, diode ring based receiver front end is presented that can be used in numerous applications. This is applied in the EZ90-14C, a receiver configured to easily provide a dynamic range beyond 90 dB at 14 MHz CW. The receiver design ideas are further illustrated with a high performance 14 MHz CW receiver. This receiver is the present incarnation of the "Progressive Receiver, " a 1981 design.

6.4-Local Oscillator Systems for superhets are discussed next. The emphasis is on methods to achieve a spectrally pure output that can be used at HF and VHF. Shielding schemes are presented, as are the virtues of isolated function modules.

6.5—We now delve into the fascinating problem of Receivers with Enhanced Dynamic Range, our so called "competition grade" receivers. Several schemes are presented, both in block diagram and in circuit form. The ultimate example offered is what we have named the "Triad" receiver, which features a switching mode MOSFET mixer followed directly by a crystal filter with constant input impedance. The resulting receiver has a 10 dB noise figure with an input 3rd order intercept of +45 dBm.
This far exceeds anything presently
offered commercially to the amateur radio market.

6.6-Transmitter and Transceiver Design: We need transmitters to go with our receivers. A discussion of transmitter design begins with the usual SSB equipment we use where mixers generate the output frequencies. A SSB transmitter differs little from a receiver except in the direction of signal flow.
Linear power amplifier chains (from microwatts up to a few watts) are then discussed and illustrated with some low power examples. Balanced modulators using diode rings and pairs as well as Gilbert Cells are presented and combined with the transmitter IF systems discussed. Some circuits vital to transceivers are presented, including bi-directional amplifiers.

6.7-Frequency Shifts, Offsets and Incremental Tuning: These are straight forward details that can add a lot to equipment functionality.

6.8-Transmit-Receive Antenna Switching: The problems of transmit-receive switching at the antenna are discussed with emphasis on electronic switching schemes. Examples up the 100 watt level are presented
The chapter ends with several projects.

6.9—The Lichen Transceiver: A Case Study is a monoband SSB design offering very high dynamic range. Although the unit shown operates in the 75 meter band, it can be adapted to other HF bands.

6.10--The next design example is "A Monoband SSB/CW Transceiver." This circuit is highly flexible and can be placed on any single band between 1.8 and
144 MHz when suitable filters are used. The version presented operates in the
6 Meter band. This design offers several circuit modules that can be used in other transceivers.

6.11-A Portable DSB/CW 50 MHz Station. The final design example is a portable rig for 6 Meters featuring a receiver with a crystal controlled converter driving a direct conversion receiver. The transmitter for the portable station uses an unusual VXO scheme to develop a DSB signal.

### Chapter 7, Measurement Equipment

Although this chapter contains pages devoted specifically to test equipment, measurement concepts are integrated throughout the book. We hope to convey the idea that measurement is a vital part of any experimental effort.

7.0-Measurement Basics. The chapter begins with some general philosophy regarding measurements. In situ measurements are compared with the substitution methods often used in RF work.

7.1—The first sections comments on simple DC measurements. A simple voltmeter is presented for use with other circuits within the book.

7.2—We now consider the oscilloscope. Basic concepts are presented, including an explanation of a 'scope probe and it's application. A paper on the CD expands some on the subject.

7.3—The next subject covered is that of RF Power Measurement. This is vital to anyone building a transmitter, although our applications also extend to receiver LO chains. Some of the several power meters presented are sensitive enough that they can easily measure signals off the air (from antennas) and can be used with signal generators for gain measurements on amplifiers. Further applications are found in a power meter paper on the book CD. Several paragraphs deal with the special problems of RF power measurements with an oscilloscope.

7.4—Attenuators are used to reduce the amplitude of RF signals in a specified impedance environment while preserving that environment. Design equations are given for several forms, and examples of power attenuators are shown.

7.5—Measuring Frequency, Inductance, and Capacitance: The problem measuring frequency is easily solved with a suitable counter. An example circuit was given in Chapter 4, and commercial units are widely available.
Once one has the ability to measure F, L and C are easily done with some existing "standard" values. This is done with a suitable general purpose oscillator.

7.6- Sources and Generators: Many of the measurements we do require a source of energy. The first example circuit presented is an audio oscillator that we have used for the testing and adjustment of SSB transmitters. A more elaborate audio generator is then presented for two-tone testing.
The next unit
presented is a general purpose RF source, providing outputs from 3 to 45 MHz in a relatively simple design. While this lacks the shielding needed to qualify it as a true "signal generator," it is suitable for extensive lab work when used with a step attenuator. The next unit describe is a "signal generator extender." This is a simple box that will allow a generator (such as many surplus HP units) that functions only down to 10 MHz to generate well defined outputs at frequencies down to audio.
The discussion of generators continues with a look as special crystal controlled sources. One example generates a stable 6 Meter signal using an off-the-shelf crystal. Next, weak signal sources for MDS measurements are discusses. These are extended to crystal controlled sources for intercept measurements, vital when experimenting with wide dynamic range receivers. The details of such measurements are presented.

7.7-Bridges and Impedance Measurement are presented in the next section.
The first bridge presented is a general purpose RF resistance bridge. This circuit uses a sensitive power meter or spectrum analyzer as a detector and is suitable for measurements between 10 and 1000 Ohms in the lower half of the HF spectrum. Methods to extend the measurements to higher frequency are suggested. The return loss bridge, or RLB, is then discussed in more detail.
Data are given to build effective bridges up through VHF. Bridges and integral transmatches are also presented in this section.

7.8-Spectrum Analysis is the subject of the next section. Most of the discussion in the book relates to basic concepts of spectrum analysis. Three papers are included on the book CD that show how to build a high performance (high IIP3) analyzer suitable for advanced measurements. This section presents some application information, including ways to measure harmonics with a SA. Some special purpose spectrum analysis tools are shown, suitable for IMD testing of SSB transmitters. This includes an adapter that allows such measurements to be done with FFT (Fast Fourier Transform) type analyzers on a personal computer sound card.

7.9-Q Measurement. In the past, the well equipped RF Lab included a commercial Q meter. Such a special purpose instrument has largely been replaced by more general instruments, including a vector network analyzer. In this section we show how to use a spectrum analyzer with a step attenuator and signal source to measure the L and Q of inductors. While we can do this via bandwidth measurements, we obtain better results with trap measurements.

7.10- Crystal Measurements. There is considerable interest in building crystal filters for communications gear. The book CD includes software for this purpose and Chapter 3 discussed it in detail. The methods all require knowledge of the parameters that model a crystal. This section shows how to determine these motional parameters, including Q with a variation on the methods of the previous section.

7.11—Noise and Noise Sources are the subject of the next section. The basis for this is a paper by Sabin that is included on the book CD that allows a simple noise source to be built. This source can be calibrated. Once a calibration is done, the source can be used to measure the noise figure of receivers, amplifiers, and even mixers with the methods presented here.

7.12—Assorted Circuits presents some test gear that didn't fit into other slots, but we still felt was useful. One is a simple circuit that can be used with a signal generator for AGC testing in a receiver. Another unit is a general purpose receiving converter, handy for testing both receivers and transmitters.
Evaluation of noise in receiver local oscillator systems is discussed and illustrated by an evaluation of a unit rich in spurious responses at discrete frequencies related to the direct digital synthesizer used in the receiver.
Finally, a simple oven is presented that may be used to measure thermal drift in oscillators and to realize temperature compensation of those designs. A paper on the book CD extends this work.

### Chapter 8, Direct Conversion Receivers

8.1-A Brief History. The chapter begins with historic comments going back to the very first ham receivers, followed soon by crystal sets augmented by local oscillators, then replaced by regenerative designs. By the end of the 1960s, early direct conversion receivers had been built, but considerable work was left to be done. It was not until 1980 that solid state DC receivers started to approach their full potential.

8.2—The Basic Direct Conversion Block Diagram. This block is the basis for analysis of the functions found in a DC receiver. Some designs use diode rings while others mix with "gain blocks" such as a Gilbert Cell. Very high audio gain is a vital part of a typical DC receiver. This section features a minimalist direct conversion receiver. This is what we consider to be the simplest DC receiver one might wish to build while still offering clean performance. A clean direct conversion receiver can form the basis of a clean superhet.
Section 12.3 shows a simple superhet based on this design.

8.3—Peculiarities of Direct Conversion. Although the block diagram is simple, the do receiver has characteristics that add challenge to the concept.
These include, but are not limited to high audio gain, local oscillator radiation, transients in LO radiation and reflection, Doppler effects, tunable or common mode hum, and AM demodulation. Eliminating or controlling these problems is discussed.

8.4-Mixers for Direct Conversion Receivers: Numerous devices have been used for this application, but only a few are considered here. Generally the diode ring is preferred over a Gilbert Cell. Passive FET mixers (switching mode) will certainly come into their own in the next few years. Some comments are made regarding excess noise sources that become important in DC receiver applications.

8.5— A Modular Direct Conversion Receiver: This section is essentially an update of earlier work. The various modules or elements in the block are considered with recommendations.

8.6 DC Receiver Advantages:
DC receivers have important differences
from superhets, and for the very best competition grade or laboratory grade HF receivers, superhets will continue to dominate. For other applications, Direct Conversion receivers may have significant advantages. Some of these advantages are described here.

### Chapter 9, Phasing Receivers and Transmitters

9.1—Block Diagrams: Blocks for familiar super-heterodyne transmitters and receiver are presented along with similar functions using phasing.
Hybrid
systems with both methods are also considered

9.2—Introduction to the Math: This section presents the basic parts of the mathematics used to develop the equipment of this chapter. Although there is a lot of math here, it should be within reason for the person with a technical education. Those without the background may want to skim through the section to pick up some salient features. This presentation differs from the traditional in using a phasing receiver as the basis for analysis.

9.3—From Mathematics to Practice: The detailed mathematics can be literally interpreted in terms of circuit development. When approximations are made in the mathematics, simplified circuits result. These design trade-off factors and risks are discussed. The more complete and literal interpretation is recommended.

9.4- Sideband Suppression Design: The reason we use phasing in a direct conversion receiver is to suppress the response of one sideband over that of the other. So, sideband suppression becomes a measure of how well a design performs. The first question addressed is a determination of just how much suppression is needed for practical communications. The question was of course answered with experiments. But the answer is often subjective, dependent on our application. Then, we use the approach of analyzing the difficulty involved in achieving various levels of performance. The benchmarks considered are receivers designed for opposite sideband suppression of 20, 30, 40, and 50 dB. The problems of systems of 60 dB suppression and beyond are even considered.

9.5—Binaural Receivers: A cousin to the phasing type DC receiver is a DSB type DC receiver with a binaural audio response.
While there is no selectivity
that causes one sideband to be suppressed over the other, there is a perceived spatial relation between information in one sideband over the other. It is possible to attach audio networks to these receives to achieve independent sideband stereo output. The receivers presented in this section illustrate adjustment methods needed to realize optimum sideband suppression.

9.6-L0 and RF Phase-Shift and In-Phase Splitter-Combiner Networks:
The networks we have mainly used are the quadrature splitters for realizing 90 degree phase differences. These networks can be built at both RF and audio, where the typical audio versions use pot cores. Wideband response is possible with a cascade of quadrature networks. The dominant audio phase shift networks use RC active all-pass structures. Considerable discussion is devoted to the details of these networks. Not only are they significant for the 50 dB sideband suppression designs, but the simpler networks are important for the less stringent demands.

9.7-Other Op-Amp Topologies, Polyphase Networks and DSP Phase Shifters: Numerous other schemes have been offered for the phase control function needed in phasing equipment. Comment is offered here regarding some of this work. The schemes offer opportunity for the builder/experimenter.

9.8-Intelligent Selectivity: Comments regarding optimization of opposite sideband suppression. The emphasis here is experimental-what is perceived by the builder/experimenter who listens to his or her receivers.

9.9—A Next-Generation R2 Single-Signal Direct Conversion Receiver:
Discussion begins with a list of project goals, followed by a block-by-block circuit description. This design uses separate boards for the various functions, including a RF amplifier with high reverse isolation. The gain distribution has been altered from earlier designs, resulting in enhanced dynamic range. The components used have 1 % tolerances, but are then user selected to 0.1 % with a digital volt meter. Extreme attention is devoted to low distortion design.
Details are presented for phase and amplitude trimming. An example of the
"R2-Pro" is found in Chapter 12.

9.10-A High Performance Phasing SSB Exciter:
The design of a very
high performance phasing SSB exciter is described, starting with the significant differences between phasing exciters and phasing receivers. The signal levels in the design are based on measurements of standard level packaged diode ring mixers. Emphasis is on low distortion, low noise off-channel, and opposite sideband suppression near 50 dB. Circuitry is also included for a high performance DSB exciter and one for very low distortion AM.

9.11-A Few Notes on Building Phasing Rigs: Some comments are presented with emphasis on complete transceivers. The ideal system uses separate blocks for each function with only a LO system being shared. Some other factors discovered, sometimes painfully, are outlined.

9.12-Conclusion: There are some situations where phasing based designs are preferred over a super-heterodyne system. These are discussed here.
Above all else, we encourage the builder/experimenter to try some of the ideas in his or her own home lab.

### Chapter 10 - DSP Components

Digital Signal Processing (DSP) implementations of circuit functions are presented in this chapter. Often these are direct substitutions for analog functions such as oscillators or filters. In other cases, functions such as large filter banks can be implemented through Fourier transforms that would be impractical with analog implementations. This chapter offers details on a select group of these DSP "components" that can be used to build portions of a radio system. No attempt is to be encyclopedic, rather enough detail and references are presented to allow implementation of these building blocks.
The Analog Devices ADSP-2181 EZ Kit is used as a platform to show real computer program snippets of many DSP components.
DSP programs for many of the components of this chapter are included on the CD-ROM that accompanies the book. These are in ADSP assembly language as well as assembled into read-to-run programs.

10.1 - The EZ-Kit Lite describes the platform and the motivation for using this type of device. Measurements of the input and output dynamic range are shown along with a discussion and measurement of intermodulation effects. A table shows possible alternatives to the EZ-Kit.

10.2 - A Program Shell presents the minimal DSP program that is needed for any of the components. The use of program interrupts is discussed along with the specific implementation of A/D and D/A interrupts used by Analog Devices. A sidebar later in the chapter presents considerable detail on the use of fixed-point (not floating point) numbers to represent "Voltages" inside the DSP.

10.3 - DSP Components looks at Amplification and Attenuation of signals, including the roles of shifting and multiplication.

10.4 - Signal Generation gives details of the generation of sine waves for use as internal functions and externally through D/A converters. Using this generator as an example, the use of Index Registers for data arrays in the DSP is covered.

10.5 - Random Noise Generation shows the generation of white noise at known levels by using random number generators. Both uniform and Gaussian distributions are covered.

10.6 - Filtering Components are presented in two forms. The IIR filter is shown for simple applications, such as might use R-C analog components.
Then, full details, including a design program, are given for FIR filters.
Performance tradeoffs are shown.

10.7 - DSP IF shows combinations of DSP components to produce an intermediate-frequency processing system.

10.8 - DSP Mixing shows the Double-Balanced Mixer in a single DSP multiplication instruction.

10.9 - Other DSP Components shows the use of the basic components to implement Automatic Gain Control, FM Transmission and FM Reception.

10.10 - Discrete Fourier Transform presents the FFT as an analog to Filter Banks. Implementation, spectral response, power extraction, and windowing are all covered.

10.11 - Automatic Noise Blankers are shown in block-diagram form.

10.12 - CW Signal Generation is presented as a simple form of amplitude modulation.

10.13 - SSB Signal Generation is covered in much detail in Chapter 11, but this section concentrates on the reduction of SSB distortion (splatter) by the application of a technique called "Predistortion." This is another example of a process that is particularly practical in a DSP implementation. Results are shown for a simple system, and a block diagram shows a more complex implementation.

### Chapter 11 - DSP Applications in Communications

The components of Chapter 10 are used to build a variety of applications.

11.1 - Program Structure outlines a simple scheme for using periodic interrupts to synchronize the program operation while still ensuring that all tasks are performed as needed.

11.2 - Using a DSP Device as a Controller performs control functions normally associated with a micro-controller. The DSP drives an LCD display as well as reading a rotary knob encoder and several switches, to provide a general interface. Program details are shown.

11.3 - An Audio Test Box uses the knob and display box of section 11.2 to control a DSP generator providing two precision sine waves and Gaussian noise. All levels and the sine-wave frequencies are adjustable

11.4 - An 18 MHz Transceiver uses the Chapter 10 components to make a SSB/CW transceiver operating in the 18 MHz amateur band. I-Q direct conversion of Chapter 9 is implemented in DSP for both reception and transmission. Vector error correction is applied in the DSP for improved
sideband rejection. Binaural reception is added by the delay method. A 5-Watt amplifier is included.

11.5 - The DSP-10 2-Meter Transceiver is an example of a DSP-based transceiver using a computer for a front panel. This project was first published in QST and these articles and all the associated software are included with the book CD-ROM. This same software can be run on a PC plus the EZ-Kit, without RF hardware. An example of the audio processor operation is shown.

### Chapter 12, Field Operation, Portable Gear and Integrated Stations

This is a chapter of projects. These are things that the three of us have built for our own use and enjoyment, subjects of our own experimentation.

12.1—Simple Equipment for Portable Operation: All three of us have, at one time or another, taken homebrew equipment into the field for portable operation. This section summarizes some of the experience we have garnered.
The section begins with a discussion of batteries and power sources. A method is presented to test a battery at home to evaluate its life later in the field. Next, some antennas are discussed. We then comment on band choices and the concept of the "Trail Friendly Radio" introduced by AA7QU. Alternative power sources are presented. We then discuss the so called
"micromountaineer" class of transceiver, a direct conversion format of especially simple design described in a paper on the book CD. A VFU 1s presented that allows such a radio to be expanded in capability.
Another practical example is presented, the so called "Western Mountaineer." This DC transceiver uses RC active audio filtering with a voltage controlled oscillator with active temperature compensation. Some antenna tuners that accompany this rig are presented.

12.2—The "Unfinished," A 7-MHz CW Transceiver: This rig is a deluxe Field Day type transceiver featuring a receiver dynamic range around 100 dB. This radio never seems to be done, being always in a state of modification, justifying the name.

12.3—The S7C, A Simple 7-MHz Super-Heterodyne Receiver: This radio emphasizes simplicity, but without a sacrifice in fundamental performance. It is an outgrowth of an ultra simple DC receiver presented in Chapter 8. This receiver would be a suitable first project for a budding experimenter wanting to put a primitive station together for 7 MHz. (If this is anticipated, we recommend a change to a 4 MHz IF with a VXO at 11.04 MHz, for all crystals are inexpensive and readily available.)

12.4- A Dual Band QRP CW Transceiver: We often seek equipment that is as simple as possible. But this radio was built with a different goal in mind.
Here, we ask what we would have to do in a modest rig to realize good receiver dynamic range and a transmitter with very good spectral purity. While we don't expect many to duplicate this box, some of the circuitry may be useful.

12.5 - Weak-Signal Communications Using the DSP-10: This section provides an introduction to using signal processing with signals too weak for conventional CW or SSB operation. Along with a historical introduction to the early work of Victor Poor, K3NIO, two examples of EME Moon bounce echoing and communication with the multi-tone PUA43 code are shown.

12.6— A 28 MHz QRP Module: This box contains a VXO based transmitter with a 18.7 MHz crystal and a X 3/2 frequency multiplier as described in Chapter 5. The VXO covers the bottom 60 kHz of the 28 MHz CW band.
The transmitter is purposefully limited to an output of 1 watt. A crystal controlled receiving converter is then put into the same box, allowing an existing receiver to complete the station. This was an easy way to add a band to an existing QRP station. The 1 watt is enough power to make a good showing for itself when conditions are good. We used the rig with a dipole at 30 ft to work 60 countries in the sunspot peak around 2001.

12.7-A General Purpose Receiver Module: Many of the receivers we build are direct conversion designs. This includes some binaural receivers. Others are simple super-heterodyne designs with single conversion requiring a product detector and a modest audio system. This design is for a board suitable for these applications. A TUF-3 diode ring mixer drives a bipolar transistor audio amplifier. This is then applied to a gain switched op-amp amplifier into an RC active audio low pass filter. An output amplifier using a single op-amp is the next stage. A sidetone oscillator is included on the board. The astute reader will note a couple places where we have used this board in the book.

12.8—Direct Conversion Transceivers for 144-MHz SSB and CW: This discussion supplements some prior QST articles (The Mini R2 and the T2, both included on the book CD) that describe the basic blocks needed in a transceiver. These are combined with a board to provide a local oscillator function via a VXO to realize an effective transceiver for 144 MHz. Two versions are described, using either a wooden or a metal box.

12.9—A 52-MHz Tunable IF for VHF and UHF Transverters: This is yet another direct conversion transceiver. However, it is quite specialized, operating at 52 MHz. Extensive shielding is used, along with numerous step attenuators, affording very careful control of signal levels in both the transmit and receive paths. The box even takes on a "retro" look, using an old Eddystone Dial popular in an earlier era.

12.10-A Sleeping Bag Radio: This 7 MHz portable rig is yet another mountain box. It is built to illustrate some concepts that produce excellent product detector isolation, needed when direct conversion is employed. A frequency doubler is used on a 3.5 MHz VFO to enhance isolation. The VFO is completely shielded from the 5 watt power amplifier. The builder can use a traditional DC receiver board, a phasing type design, or even a binaural system, depending on the needs.

12.11-A 14-MHz CW Receiver: The "R2-Pro" Design featured in Chapter 9 is applied in this example. A 7 MHz VFO is frequency doubled to 14 MHz and is amplified and split. The result is a set of three outputs. Two of these are in phase quadrature and available for use in the receiver. A third is available for transmitter applications. A bandwidth tailored by the builder for CW use can be achieved in the audio filtering portion of the R2-Pro.

### CD-ROM Contents

The various programs on the ROM are listed in the text. The ROM includes 60
articles from prior issues of QST, QEX, HR, Communications Quarterly, and
Microwave Update. The CD includes 10 circuit design programs and several
DSP code listings, including source code for the 18-MHz transceiver and the
DSP-10 144-MHz transceivers.
