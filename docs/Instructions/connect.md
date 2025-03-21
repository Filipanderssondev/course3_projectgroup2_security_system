# How to connect the device

### **[Components](https://github.com/Filipanderssondev/course3_projectgroup2_security_system/tree/dev-bubba/94?tab=readme-ov-file#potential-extensions-if-time-and-resources-are-available)** needed before you start

## The tinkerCAD sketch for V1 of the SAFE-AlarmSystem project.

    ![view Safe_AlarmSystemV1.png](tools/SAFE_Alarm_System_v1.png)

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

1. Start by connecting arduino pins accordingly **(preferably connect on TinkerCAD first to prevent damages on components)**  
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

3. Carefully pin the device together **(without power to prevent shortcircuiting)**
