# aqua_man
## Introduction
I want to implement a system to messure the current waterlevel of a watertank with the help of a ultrasonic sensor. I want to integrate the sensor into the local home assistant network with the help of esphome.

## Initial Situation
There are to large watertanks with a total volume of 2000 liters installed half way up the mountain for a fresh water supply. From there we supply all the facilities of the FabFarm. The watertanks are connect to the waterpump thats installed in the valley of the farm. The waterpump is already integrated into the home assistant network through a relay thats connected to a microcontroller.

<p align="center">
<img src="./images/watertank-side.jpeg" width="30%" />
<img src="./images/watertank-top.jpeg" width="30%" align="left"/> 
<img src="./images/watertank-front.jpeg" width="30%" align="right"/>
</p>

## Goal and Requirments

The goal is to monitor the waterlevel, transmit the data to the local home assistant server and implement an automation based on the datastream. Based on local circumstances and some research, I came up with the following requirments:

The System must
  1) include a self-sufficient energy supply
  2) communicate through WI-FI and Network with local home assistant server
  3) store excessiv energy
  4) work highly efficent
  5) withstand all weather conditions
  6) resistant to extreme heat and sun.

## Design

Based on the requirments I came up with the following compontants:

### ESP01

<p align="center">
<img src="./images/esp01.jpeg" width="30%" />
</p>

The ESP01  is a type of low-cost Wi-Fi microcontroller module.  It is based on the ESP8266 chip and is small in size, making it a good choice for this project. Furthermore is works on 3.3 V and need only little power. [(Datasheet)](/datasheets/ESP01.PDF)

### ESP01 Programmer

<p align="center">
<img src="./images/esp01-programmer.jpeg" width="30%" />
</p>

An ESP01 programmer is a device used to program the ESP01 module,It acts as a bridge between a computer and the ESP01 module, allowing you to upload your code to the module, as well as perform other tasks such as setting its parameters or reading its data. DIY solutions available.

### Grove - Ultrasonic Ranger V2.0

<p align="center">
<img src="./images/grove-front.jpeg" width="30%" />
<img src="./images/grove-back.jpeg" width="30%" />
</p>

This Sensor uses ultrasound to mesure the distance to an object or surface. Unlike the well known HC-SR04 sensor this one works with 3.3 V and trig and echo signal share 1 SIG pin. Therefore it can share the same power supply then the ESP.
[(Website)](https://wiki.seeedstudio.com/Grove-Ultrasonic_Ranger/)


- Operating Voltage: 3.2 ~ 4.2V
- Operating Current: 8mA
- Measuring range: 2 - 350cm
- Resolution: 1cm

### TP4056

<p align="center">
<img src="./images/tp4056.jpeg" width="30%" />
</p>

Linear Li-Ion battery charger IC with a constant-current and constant-voltage charging algorithm, thermal regulation, and charge status indication. It can work with USB or a supply of up to 8 V. Charging current is programmable with resistor. [(Datasheet)](/datasheets/ESP01.PDF)

- Programmable Charge Current Up to 1000mA
- Input Supply Voltage：4Vmin, 5Vtyp, 8Vmax
- Charging current from 130mA to 1A
- Upper charge stop voltage : 4.2V.

### Solar Panel

<p align="center">
<img src="./images/solar-front.jpeg" width="30%" />
<img src="./images/solar-back.jpeg" width="30%" />
</p>

This Solar Panel will generate the needed energy for the system and will charge the battery up for periods of missing sun.

- Pmax: 5W
- V at Pmax: 9V
- Current at Pmax: 560mA

### Other Compontents

- **Waterproof Container**: A plastik box or simlar. I used an cleaned up plastik jar. SHould be large enough to contain all the components mounted on the wooden board.
- **Wooden Board**: Should have enough surface for all the compontents and bettery cell.
- **Cable**
- **Glue**: To fix the wooden board to the container 
- **Soldering iron plus accessories**
- **Drill, screwdriver and screws**: To mount the compontents and drill the hole for the ultrasonic sensor


## Hardware Design

I used a little wooden board as the mount for the components. With glue I connected the board to the plastic jar, which works as awater proof container.

### 



## Resources
1) [ESP Home Custom Sensor Component](https://esphome.io/custom/custom_component.html)

## Tasks and Improments
- [ ] [Enable deep sleep on ESP01](https://www.instructables.com/Enable-DeepSleep-on-an-ESP8266-01/)
- [ ] [Remove LEDs from ESP](https://quadmeup.com/esp8266-esp-01-low-power-mode-run-it-for-months/)
- [ ] Remove battery indicator circuit. (Not working with GPIO 0 of ESP)
- [ ] Integrate heatmanagment for the hole system
- [ ] Dokumentation of Hardwaresetup
- [ ] Dokumentation of Softwaresetup