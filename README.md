
<h1 align="center">
  <br>
  <a href=""><img src="https://raw.githubusercontent.com/BeachtechRobotics/Battle-Bot-PS3-Code/main/BEACHTECH%20logo.png" alt="Markdownify" width="800"></a>
</h1>

<h4  Battle Bot Controller for Based on an ESP-32.</h4>




<a href=""><img src="https://raw.githubusercontent.com/BeachtechRobotics/Battle-Bot-PS3-Code/85f9a0fc75de0117010c7f4378fe868461111a3c/Madewitharduino.svg" alt="Markdownify" width="300"></a>

# Getting Started

Detal guid  You can [download](https://github.com/BeachtechRobotics/Battle-Bot-PS3-Code/blob/main/Programming%20ESP32%20Guide.pdf)

## Installing the ESP32 board

In case you haven't yet, you can add the ESP32 boards to your Arduino IDE by adding them to the Boards Manager: 

Open `File -> Preferences`, and paste the following URL in the `Additional Boards Manager URLs` field:
```bash
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```
Open the Boards Manager with `Tools -> Board: "xxx" -> Boards Manager`, 
look for `esp32` 
(probably the last one in the list), and click `Install`.Finally, select the ESP32 board you have with `Tools -> Board: "xxx"` under the section ESP32 Arduino 
(I always have ESP32 Dev Module selected).

## Installing the librares

You can install the Arduino librares from within the Arduino IDE. Open the Library Manager with `Sketch -> Include Library -> Manage Libraries...`.

Search for `PS3 Controller Host`, and click `Install`.

Search for `ESP32Servo`, and click `Install`.

## Using the the Code

In the sketch find Ps3.begin("00:00:00:00:00:00"); and replace with MAC address that is associated with in the PS3 Controller.

```bash
#include <Ps3Controller.h>

void setup()
{
    Ps3.begin("00:00:00:00:00:00");
}
```

> **Note**
> You can use [Sixaxis Pair Tool](https://sixaxispairtool.en.lo4d.com/download/mirror-hs1)  software is uesd to look up and update the MAC address of the controller.


## Download

You can [download](https://github.com/BeachtechRobotics/Battle-Bot-PS3-Code/blob/main/BATTLEBOT_ESP32_PS3.ino)  arduino code at this link

## Credits

I've had tremendous help developing this this guide and code by reading these sources:

- [jvpernis ESP-32 PS3 libary](https://github.com/jvpernis/esp32-ps3)
- [aed3 ESP-32 PS4 libary](https://github.com/openobjects/PS4-esp32)
- [randomnerdtutorials ESP32 Tutorial](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)

