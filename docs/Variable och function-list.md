# Official naming conventions of current project

### Variable List  
We use the `camelCase` naming convention for general variables.   
Constants should be named with **CAPITAL** letters:  
Initialization of variables/functions should be located **before** the running code (with commenting if need be).  
Definitions of variables/functions should be located **after** the running code.  

### Variable list:    
`{number} = pin slot`  

```cpp
const int BUZZER {9};
const int BUTTON {10};
const int PIR_SENSOR {6};
const int RED_LED {7};
const int GREEN_LED {8};

bool sensorState: Stores boolean value from the PIR_SENSOR.
bool buttonState: Stores boolean value from BUTTON.
bool doItOnce: Evaluates ......
int powerOnTune: tune for when the system is turned on.
int powerOffTune: tune for when the system is turned off.
int alarmTune: tune for when the alarm is triggered.
int buttonPressTune: Tune for when a push-button or 4x4 button is pressed.
```

### Function list: 
```cpp
void
void readPirSensor();
void writeToLCD(const char* LCDMessage);
void writeToSerialMonitor(const char* SerialMessage);
void alarmPowerOff();
void alarmPowerOn();
void alarmRinging();
void alarmDeactivated();

```

### Function explanations:
```cpp
readPirSensor().
Updates the value of sensorState through digitalRead(PIR_SENSOR).

writeToLCD(const char* LCDMessage).
The content of the parameter passed into the function is printed on the LCD display using the LiquidCrystal class’ print() method.

writeToSerialMonitor(const char* SerialMessage).
The content of the parameter passed into the function is printed on the Serial monitor using the Serial objects. print() method.

alarmPowerOff().
Power off the alarm when the button is pressed whilst the alarm is powered on.

alarmPowerOn().
Power on the alarm when the button is pressed whilst the alarm is powered off.

alarmRinging().
Invoke the tune() function with alarmTune as frequency, enters a loop until alarmDeactivated() is invoked by pressing the button while in the loop.

alarmDeactivated()
Waits for buttonState to record a change in the state of the BUTTON, thereafter proceed with breaking out of the loop caused by alarmRinging(), followed immediately by invoking noTune(BUZZER) to turn off the alarm. 
Also informs the user by invoking both writeToLCD() and writeToSerialMonitor to tell them that the alarm has been deactivated.
```
