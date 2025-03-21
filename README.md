# <p align="center"> SAFE - Security system </p>
Project Group 2 - Course 3  
Assignment to summarize our third course and prepare for the next.  
**Contributors:** [Sabina](https://github.com/binasime), [Alexander](https://github.com/alexanderchasacademy), [Filip](https://github.com/Filipanderssondev),  [Jacob](https://github.com/jalis00), [Johan](https://github.com/bubba-94)  

![SAFE Security system](https://github.com/Filipanderssondev/course3_projectgroup2_security_system/blob/main/tools/SAF.png)  

### File tree/Structure:
course3_projectgroup2_security_system/
├── docs/
│   ├── Assignment/
│   │   └── Projectassignment.pdf
│   ├── Functionality/
│   │   └── Variable & function-list.md
│   └── Instructions/
│       ├── Arduino_IDE.md
│       ├── connect.md
│       └── manual.md
│   
├── src/
│   └── SAFE_AlarmSystem_V1/
│       └── SAFE_AlarmSystem_V1.ino
│
├── tools/
│   ├── Saf.png
│   ├── SAFE_Alarm_System_V1.png
│   └── SAFE_Alarm_System_V1_Schematic.pdf
│
└── README.md


________________
**Links that we have used during the construction of our prototype**  
### [Kanban/Progress Board](https://github.com/users/Filipanderssondev/projects/6)

### [TinkerCAD sketch](https://www.tinkercad.com/things/2IvXT1tnwTr-safe-alarm-system-v10?sharecode=3K8oA0UX7hQ530EvdRRKtiQOKeserKk2IRnFxNyzCII)   
_____________
### Overview:  
Develop a security alarm system that detects motion using an infrared sensor. The alarm system consists of the following components:   
* Infrared motion sensor - detects movement.
* One buzzer - signals when motion is detected and when the alarm is activated.
* Pushbutton - deactivates the alarm.    
* LCD display - outputs the current alarm status (on/off/alarm triggered).
* RGB-LED - indicates system status: Green = alarm is off and red = alarm is on.
_________

### Components (no extensions included): 
* One ***Arduino Uno R4 Wifi*** or other compatible controller  
* One ***breadboard***   
* One ***buzzer***      
* One ***LCD display***
* One ***infrared sensor**  
* One ***pushbutton***  
* One ***RGB-LED*** (can be replaced by a ***red*** and ***green LED***)
____  

### Potential extensions (if time and resources are available):  

- [ ] Replace pushbuttons with a keypad for code entry.  
- [ ] Enable admin access to change the personal password.
- [ ] Introduce the usage of a servo component.
- [ ] Expand the alarm with diffrent sensors for example ultrasound or vibrationdetector.  

______
### Instructions for usage:  
Follow these instructions to build a complete prototype.
1. Connect the hardware. [Link to instructions to connect physical hardware](https://github.com/Filipanderssondev/course3_projectgroup2_security_system/blob/main/docs/Instructions/connect.md)
2. Build code using **C++/Arduino IDE**. [Link to source code](https://github.com/Filipanderssondev/course3_projectgroup2_security_system/blob/main/src/SAFE_AlarmSystem/SAFE_AlarmSystem.ino)
3. Schematics for prototype. [Link to schematics](https://github.com/Filipanderssondev/course3_projectgroup2_security_system/blob/main/tools/TESTING%20SAFE_AlarmSystem.ino.pdf)
4. Manual for completed prototype. [How to use the device](https://github.com/Filipanderssondev/course3_projectgroup2_security_system/blob/main/docs/Instructions/manual.md)
   
### Safety requirements:  
(To be defined based on project scope and implementation)
