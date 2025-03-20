# How to connect the device

### **[Components](https://github.com/Filipanderssondev/course3_projectgroup2_security_system/tree/dev-bubba/94?tab=readme-ov-file#potential-extensions-if-time-and-resources-are-available)** needed before you start

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
