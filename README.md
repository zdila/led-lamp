# Motion and light controlled LED lamp

## Features

- smooth light fade-in and fade-out
- power saving features:
  - light turned off when no motion is detected 
  - light turned off on ambient light presence
- adjustable ambient light and movement sensor sensitivity
- movement sensor in retriggering mode
- USB rechargeable

## Components

- Arduino Pro Mini 3.3V Atmega328
- HC-SR501 Infrared PIR Motion Sensor
- Photoresistor Light Detection Sensor Module (http://www.ebay.com/itm/1PCS-Photoresistor-Sensor-Module-Light-Detection-Light-for-Arduino/221891172110)
- USB battery charger with output and protection (http://www.ebay.com/itm/5V-Mini-USB-Li-ion-18650-Lithium-3-7V-Battery-Charging-Charger-Module-Protection-/112448290719)
- resistors 10M and 10R
- N-Channel MOSFET FQP30N06L
- 1W LED Bead
- Li-Ion Battery 18650

## Connecting components

- connect battery to USB charger which is also providing the power (+/-)
- connect Arduino to power
- connect Photoresistor Light Detection Sensor Module to the power and to Arduino PIN 4
- connect PIR Sensor to the power and to Arduino PIN 3
- connect LED via 10R resistor from MOSFET drain to LED and 
- connect + to LED anode via 10R
- connect LED cathode to MOSFET drain
- connect MOSFET source to -
- connect MOSFET gate to Arduino PIN 9
- connect 10M to MOSFET gate and -
