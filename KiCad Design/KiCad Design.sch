EESchema Schematic File Version 4
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATmega:ATmega328-PU U?
U 1 1 5C885665
P 5300 2750
F 0 "U?" H 4659 2796 50  0000 R CNN
F 1 "ATmega328-PU" H 4659 2705 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 5300 2750 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 5300 2750 50  0001 C CNN
	1    5300 2750
	1    0    0    -1  
$EndComp
Text GLabel 5900 2450 2    50   Input ~ 0
A0
Text GLabel 5900 2550 2    50   Input ~ 0
A1
Text GLabel 5900 2650 2    50   Input ~ 0
A2
Text GLabel 5900 2750 2    50   Input ~ 0
A3
Text GLabel 5900 2850 2    50   Input ~ 0
A4
Text GLabel 5900 2950 2    50   Input ~ 0
A5
$Comp
L Interface_USB:FT232RL U?
U 1 1 5C88576D
P 2300 2500
F 0 "U?" H 2300 3678 50  0000 C CNN
F 1 "FT232RL" H 2300 3587 50  0000 C CNN
F 2 "Package_SO:SSOP-28_5.3x10.2mm_P0.65mm" H 2300 2500 50  0001 C CNN
F 3 "http://www.ftdichip.com/Products/ICs/FT232RL.htm" H 2300 2500 50  0001 C CNN
	1    2300 2500
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_2Rows-05Pins J?
U 1 1 5C885909
P 8050 1700
F 0 "J?" H 8100 2017 50  0000 C CNN
F 1 "Conn_2Rows-05Pins" H 8100 1926 50  0000 C CNN
F 2 "" H 8050 1700 50  0001 C CNN
F 3 "~" H 8050 1700 50  0001 C CNN
	1    8050 1700
	1    0    0    -1  
$EndComp
Text GLabel 5900 3450 2    50   Input ~ 0
D2
Text GLabel 5900 3550 2    50   Input ~ 0
D3
Text GLabel 5900 3650 2    50   Input ~ 0
D4
Text GLabel 5900 3750 2    50   Input ~ 0
D5
Text GLabel 5900 3850 2    50   Input ~ 0
D6
Text GLabel 5900 3950 2    50   Input ~ 0
D7
Text GLabel 8250 2600 2    50   Input ~ 0
D8
Text GLabel 8250 2700 2    50   Input ~ 0
D9
Text GLabel 8250 2800 2    50   Input ~ 0
D10
Text GLabel 8250 2900 2    50   Input ~ 0
D11
Text GLabel 8250 3000 2    50   Input ~ 0
D12
Text GLabel 8550 3100 2    50   Input ~ 0
D13
Text GLabel 8250 3200 2    50   Input ~ 0
D14
Text GLabel 8250 3300 2    50   Input ~ 0
D15
Wire Wire Line
	8250 3100 8550 3100
$Comp
L MCU_Microchip_ATmega:ATmega328P-PU U?
U 1 1 5C885CD0
P 7650 3800
F 0 "U?" H 7009 3846 50  0000 R CNN
F 1 "ATmega328P-PU" H 7009 3755 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 7650 3800 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 7650 3800 50  0001 C CNN
	1    7650 3800
	1    0    0    -1  
$EndComp
$EndSCHEMATC
