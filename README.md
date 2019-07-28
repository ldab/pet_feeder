# Pet-Feeder
ESP8266 based Pet Feeder.

[![GitHub version](https://img.shields.io/github/release/ldab/Pet_Feeder.svg)](https://github.com/ldab/Pet_Feeder/releases/latest)
[![CodeFactor](https://www.codefactor.io/repository/github/ldab/pet_feeder/badge/master)](https://www.codefactor.io/repository/github/ldab/pet_feeder/overview/master)
[![Build Status](https://travis-ci.org/ldab/Pet_Feeder.svg?branch=master)](https://travis-ci.org/ldab/Pet_Feeder)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://github.com/ldab/Pet_Feeder/blob/master/LICENSE)

[![GitHub last commit](https://img.shields.io/github/last-commit/ldab/Pet_Feeder.svg?style=social)](https://github.com/ldab/Pet_Feeder)

* This was more than a weekend project, took few designs to get it working, below few examples, being the last one the most successful one:

![](./pics/feed%20screw.gif) 

![](./pics/espet.gif) 

![](./pics/espet_cut.gif) 

![](./pics/moving_gate.gif)

## Sumary

1. [PlatformIO](/README.md#PlatformIO)
2. [Hardware](/README.md#Hardware)
3. [Blynk](/README.md#Blynk)
4. [3D Printing](/README.md#3d-printing)
5. [Credits](/README.md#Credits)

## PlatformIO

* More information can be found on their comprehensive [Docs](https://docs.platformio.org/en/latest/ide/vscode.html). But Basically:

  0. Download and install official Microsoft Visual Studio Code. PlatformIO IDE is built on top of it
  1. **Open** VSCode Package Manager
  2. **Search** for official `platformio-ide` [extension](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)
  3. **Install** PlatformIO IDE.

![PlatformIO installation](https://docs.platformio.org/en/latest/_images/platformio-ide-vscode-pkg-installer.png)

## Hardware

### Servo

* Just using the cheap blue [SG90](https://www.google.com/search?client=firefox-b-d&q=sg90+servo):

![SG90](https://opencircuit.nl/resources/content/2ed9317749689/crop/400-320/TowerPro-SG90-9G-micro-servo-motor.jpg)

### Board Pinout

![](https://www.prometec.net/wp-content/uploads/2016/03/e90c9fb2-9114-3c70-5adf-5697ba268788.jpg)

## Blynk App

<img src="./pics/ESPet_blynk.jpg" width="30%"> <img src="./pics/QR.jpg" width="30%"> 

## 3D Printing

* You can find the 3D files [here](./3d%20files) or [https://www.thingiverse.com/thing:3776532](https://www.thingiverse.com/thing:3776532)

* Print seetings:
  * Anycubic I3 Mega;
  * PLA 195degC;
  * 0.25 resolution;
  * No support, (only the `gate` requires it);
  * 3 walls;
  * 20% Zigzag infill;

![ESPet](./pics/servo.png) ![ESPet](./pics/moving_gate.gif)

## Credits

*.gif created with [EZGIF.COM](https://ezgif.com/)

GitHub Shields and Badges created with [Shields.io](https://github.com/badges/shields/)
