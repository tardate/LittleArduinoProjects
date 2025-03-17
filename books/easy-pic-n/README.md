# #709 Easy Pic'N

Book notes: Easy Pic'N: A Beginners Guide to Using Pic16/17 Microcontrollers from Square 1, by David Benson. First published December 31, 1996.

[![Build](./assets/easy-pic-n_build.jpg?raw=true)](https://amzn.to/3XZxPVJ)

## Notes

See also:

* [amazon](https://amzn.to/3XZxPVJ)
* [goodreads](https://www.goodreads.com/book/show/3411576-easy-pic-n)

## Contents

* PIC PRODUCT OVERVIEW
* PIC16F84
    * Pins and Functions
    * Package
    * Clock Oscillator
    * Configuration bits
    * Reset
    * Ports
    * Special Features
        * Watchdog Timer
        * Power-up Timer
        * Sleep Mode
    * PIC16 Architecture
        * Program Memory
        * Weird Hex Notation
        * File Registers
        * Working Register (W)
        * Option Register
        * Stack
        * Reset Vector
        * Interrupt Vector
    * Option Register
    * Program Counter
    * Status Register
* CIRCUIT FOR EXPERIMENTS
    * '84 On A Board
* CHOOSING DEVELOPMENT TOOLS
    * MPLAB/Windows vs. MPASM/MS-DOS
    * Choosing A Device Programmer
* USING AN ASSEMBLER
    * Source Code For The Assembler
        * Semicolon (;)
        * Tabs
    * Style
    * Headers
    * Labels
    * Equates Literals
    * Origin
    * End
    * Program Format
    * Files Used By Assembler
    * Files Created By Assembler
    * Preventing Some Gotchas
* USING THE MS-DOS BASED MPASM ASSEMBLER
    * How To Assemble A Program
* MPLAB OVERVIEW - GETTING STARTED
    * Using MPLAB - Getting Started
        * Toolbars
        * Select Development Mode And Device Type
        * Project
        * Text Editor
        * Edit Project
        * Assembler
    * More MPLAB Operations
* PROGRAMMING A DEVICE
* WRITING PROGRAMS
    * Programming Concepts
    * Instruction Set
    * Weird Move Instruction
    * Instruction Format For The Assembler
        * Byte-Oriented Instructions Bit-Oriented Instructions
        * Literal Instructions
        * Control Instructions (CALL and GOTO)
        * Destination Designator (d)
    * Hexadecimal Numbers vs. MPASM Assembler Binary And Decimal Numbers vs. MPASM Assembler
    * ASCII Characters vs. MPASM
        * Assembler
        * Addressing Modes
        * Immediate addressing
        * Direct Addressing
        * Indirect Addressing Relative Addressing
        * Use Of The RETLW Instruction For Accessing Tables of Data Via Relative Addressing
    * Using The Ports
        * Data Direction
        * Port Read/Write
    * Flags
    * Simple Data Transfers
    * Loop - Endless
    * Loop With a Counter
    * Loop Until Comparisons
    * Bit Manipulation Using Bit Manipulation Instructions
    * Bit Manipulation
    * Using Logic Instructions
    * Using Bit Manipulation
    * Sequencing Subroutines
    * Time Delay Loop
    * Lookup Tables
* INTERRUPTS
    * Interrupt Control Register
    * Interrupt Sources
        * External
        * Timer/Counter
        * Port B Interrupt On Change - Bits 7,6,5,4
    * Global Interrupt Enable Flag
    * Saving Status During An Interrupt (Context Saving)
    * Where To Put The Interrupt Service Routine
    * Interrupt Latency
    * Multiple Interrupt Sources
    * Example - External Interrupt
* TIMING AND COUNTING
    * Digital Output Waveforms
    * Timing And Counting Using The PIC16F84's TMR On-Board Timer/Counter
        * Prescaler
        * Changing Prescaler Assignment
        * Using The Timer/Counter
        * Timer/Counter Experiments
            * Digital Output Using TMRO - Internal Clock Single Time Interval - Internal Clock Single Time Interval - External Clock
            * Free Running Mode - Internal Clock Free Running Mode - External Clock
            * Counting Events (Pulses)
* PIC16C54
    * Pins And Functions
    * Packages
    * Clock Oscillator
    * Configuration bits
    * Ports
    * Architecture
        * Program Memory File Registers
        * Stack
        * Reset
        * Vector
        * Program Counter
        * Option Register
        * Status Register
    * No Timer/Counter Overflow Interrupt/Flag Output
    * Fewer Instructions
    * PIC16C54 Programming Example
    * Timing And Counting
    * Timer/Counter Description
    * Using The Timer/Counter Timer/Counter Experiment
* MENDING OUR WAYS
    * Sink vs. Source
    * File Register Bank Switching
    * Bank Switching Demo
    * Interrupts And Bank Switching
    * Program Memory Paging
    * Include Files
* 1/O CONVERSION
    * Input Conversion
    * Output Conversion
* MORE PIC'n BOOKS
* APPENDICES
    * Appendix A - Sources
    * Appendix B - Hexadecimal Numbers
    * Appendix C - Program Listings vs. Page Number
