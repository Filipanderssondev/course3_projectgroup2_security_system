# How to connect the device

### **[Components](https://github.com/Filipanderssondev/course3_projectgroup2_security_system/tree/dev-bubba/94?tab=readme-ov-file#potential-extensions-if-time-and-resources-are-available)** needed before you start

## The tinkerCAD sketch for V1 of the SAFE-AlarmSystem project.

![view Safe_AlarmSystemV1.png](https://github.com/Filipanderssondev/course3_projectgroup2_security_system/blob/main/tools/SAFE_Alarm_System_v1.png?raw=true)

### Create your own copy of the sketch

If you want to take a closer look, or simply test, play around or make a copy of the TinkerCAD sketch, click on the link below.
[SAFE_AlarmSystemV1](https://www.tinkercad.com/things/2IvXT1tnwTr-safe-alarm-system-v10?sharecode=3K8oA0UX7hQ530EvdRRKtiQOKeserKk2IRnFxNyzCII)

## Wiring the Arduino.
1. Start by looking through the component-list linked at the top of the document.
For a quick reminder, the components needed are the following.
* One Arduino Uno R4 Wifi or other compatible controller
* One breadboard
* One buzzer
* One LCD display
* One passive infrared sensor
* One pushbutton.
* One RGB-LED (can be replaced by a red and green LED).

Keep in mind that the wiring and sensitivity of the components you have compared to the ones available in TinkerCad or used by us while assembling the project may differ slightly or greatly. Before you proceed we strongly recommend that you consult the ***datasheets*** or ***instructions*** for your own components and adapt the wiring accordingly.

2. Connecting the components.
* Pay close attention to which pin is connect to which component in the sketch, make sure that they match your physical wiring. 
* To make it easier to keep track of the wiring and the components, we advise you to stick as closely to the sketch as possible. However, if you need the space, or can still easily keep track of the wires and components. Feel free to place them wherever you wish, as long as the wiring matches the sketch. 

### List of components and respective wiring. 

comprehensive list of wiring.

#### Buzzer
1. Connect one side of the buzzer to D9 on the Arduino.
2. Connect the other side to ground with a resistor, the strength of the resistor depends on your desired sound level. We recommend you start with a resistor with a high Ohm before moving to a lower one.

#### LCD display
1. Connect GND from the display to Arduino GND.
2. Connect VCC to 5V.
3. Connect VO/Contrast to ground.
4. Connect RS (Register Select) to D11 on the Arduino.
5. Connect R/W (Read/Write) to GND.
6. Connect E (Enable) to D12 on the Arduino.
7. Connect DB4 on the display to D2 on the Arduino.
8. Connect DB5 on the display to D3 on the Arduino.
9. Connect DB6 on the display to D4 on the Arduino.
10. Connect DB7 on the display to D5 on the Arduino.
11. Connect LED anode on the display to 5V through a 1k Ohm Resistor.
12. Connext LED Cathode on the display to GND.

#### PIR (Passive Infrared ) sensor
1. Connect the Signal/OUT to D6 on the Arduino.
2. Connect Power to 5V.
3. Connext Ground to GND.

#### RGB-LED
1. Connect the leg controlling the red LED through a suitable resistor to D7 on the Arduino.
2. Connect the leg controlling the green LED through a suitable resistor to D8 on the Arduino.
3. Connect the common cathode to GND.

#### Button 
1. One leg to D10 on the Arduino.
2. Connect the leg opposite vertically to GND through a 10k Ohm resistor.
3. The leg horizontally from the grounded leg is connected to 5V.



<!-- 1. Start by connecting arduino pins accordingly **(preferably connect on TinkerCAD first to prevent damages on components)**  
```cpp
// Library for LCD Screen
#include <LiquidCrystal.h>

// Initialize LCD with pin: (RS, E, D4, D5, D6, D7)
LiquidCrystal LCD(11, 12, 2, 3, 4, 5);

// Variables for components connected to arduino.
const int BUZZER = 9;
const int BUTTON = 10;
const int PIR_SENSOR = 6;
const int RED_LED = 7;
const int GREEN_LED = 8; 
```

2. Open the [TinkerCAD](https://www.tinkercad.com/things/hkzwk208qim-testing-safealarmsystemino/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=D0tnPiXF99BZVIktJoVi4gTVeHDah8EVGiA-xL8jnsk)
to look up the wiring.  

3. Carefully pin the device together **(without power to prevent shortcircuiting)** -->
