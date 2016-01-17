EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:nrf24_schematic
LIBS:nrf24_breakout-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "nRF24 breakout board"
Date "2016-01-16"
Rev "1.2.0"
Comp "github.com/tardate/LittleArduinoProjects/blob/master/Electronics101/nRF24Breakout"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_01X08 P1
U 1 1 569AD7BE
P 4800 3350
F 0 "P1" H 4800 3800 50  0000 C CNN
F 1 "CONN_01X08" V 4900 3350 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08" H 4800 3350 50  0001 C CNN
F 3 "" H 4800 3350 50  0000 C CNN
	1    4800 3350
	1    0    0    -1  
$EndComp
$Comp
L nRF24 U1
U 1 1 569ADBE8
P 3400 3200
F 0 "U1" H 3400 2500 60  0000 C CNN
F 1 "nRF24" H 3350 3050 60  0000 C CNN
F 2 "nrf24_footprint:nRF24" H 3000 3200 60  0001 C CNN
F 3 "" H 3000 3200 60  0000 C CNN
	1    3400 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 3000 4600 3000
Wire Wire Line
	4000 3100 4600 3100
Wire Wire Line
	4000 3200 4600 3200
Wire Wire Line
	4000 3300 4600 3300
Wire Wire Line
	4000 3400 4600 3400
Wire Wire Line
	4000 3500 4600 3500
Wire Wire Line
	4000 3600 4600 3600
Wire Wire Line
	4000 3700 4600 3700
$Comp
L CP1 C1
U 1 1 569B7630
P 4300 4000
F 0 "C1" H 4325 4100 50  0000 L CNN
F 1 "10µF" H 4325 3900 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D6.3_L11.2_P2.5" H 4300 4000 50  0001 C CNN
F 3 "" H 4300 4000 50  0000 C CNN
	1    4300 4000
	0    1    1    0   
$EndComp
Wire Wire Line
	4150 4000 4150 3000
Connection ~ 4150 3000
Wire Wire Line
	4450 4000 4450 3700
Connection ~ 4450 3700
$EndSCHEMATC
