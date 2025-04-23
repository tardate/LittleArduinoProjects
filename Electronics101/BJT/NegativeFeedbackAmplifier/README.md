# #495 Negative Feedback Amplifier

Examining the design and performance of an ac-coupled negative feedback amplifier constructed with BJTs.

![Build](./assets/NegativeFeedbackAmplifier_build.jpg?raw=true)

## Notes

Negative feedback is by definition the concept of using a fraction of the output to dampen the input.
When designed appropriately, this can trade some gain for higher linearity and stability,
and reduced sensitivity to component parameter variations.

## Circuit

The circuit design used here is based on a fairly common "Negative Feedback Amplifier Kit" (easily found on Aliexpress or eBay).
It essentially a two-stage common-emitter amplifier with a feedback loop from the output of the final stage to the emitter of the first stage.
NB: the circuit is exactly as covered in 10-5 Two-Stage Feedback of
[Electronic Principles by Albert Paul Malvino](../../../books/electronic-principles/).

The feedback loop creates an AC voltage divider between the output and ground:

    ve = RF1/(RF1 + RF2) . vo

Thus the negative feedback: the first stage output is reduced in proportion to an increase in the second stage output

![Schematic](./assets/NegativeFeedbackAmplifier_schematic.jpg?raw=true)

See [LEAP#389 TwoStageCommonEmitterAmplifier](../TwoStageCommonEmitterAmplifier), for a similar two-stage CE amplifier but without feedback.

## Breadboard Construction

![Breadboard](./assets/NegativeFeedbackAmplifier_bb.jpg?raw=true)

![NegativeFeedbackAmplifier_bb_build](./assets/NegativeFeedbackAmplifier_bb_build.jpg?raw=true)

Scope trace with a 1kHz 200mV peak-peak input and finely adjusted bias and feedback:

CH1 (Yellow): input
CH2 (Blue): output

![scope_bb](./assets/scope_bb.gif?raw=true)

## Protoboard Construction

![protoboard_layout_and_board](./assets/protoboard_layout_and_board.jpg?raw=true)

Under test:

![under_test](./assets/under_test.jpg?raw=true)

Scope trace with a 1kHz 200mV peak-peak input and finely adjusted bias and feedback:

CH1 (Yellow): input
CH2 (Blue): output

![scope_out](./assets/scope_out.gif?raw=true)

## Credits and References

* [Negative-feedback amplifier](https://en.wikipedia.org/wiki/Negative-feedback_amplifier) - wikipedia
* [Chapter 4 - Bipolar Junction Transistors - Feedback](https://www.allaboutcircuits.com/textbook/semiconductors/chpt-4/feedback/)
* [10.1 Cascade of two single transistor stages](https://wiki.analog.com/university/courses/electronics/text/chapter-10) - Analog wiki
* [Design of 2 stage BJT CE amplifier](https://ampdesigns.tripod.com/2_Stage_BJT_amplifier.html)
* [Electronic Principles by Albert Paul Malvino](../../../books/electronic-principles/)
* [Multistage Transistor Amplifiers](https://www.youtube.com/watch?v=FbdZ46VdTjE)
* [LEAP#389 TwoStageCommonEmitterAmplifier](../TwoStageCommonEmitterAmplifier)
