# Official Naming Conventions of This Project

## Variable List  
We use the `camelCase` naming convention for general variables. Constants should be named with **CAPITAL** letters:  

### Preset Variables  
`{number} = pin slot`  

```cpp
const int BUZZER {9};
const int BUTTON {10};
const int PIR_SENSOR {6};
const int RED_LED {7};
const int GREEN_LED {8};

int sensorState: Stores the read value from the PIR_SENSOR.
int buttonState: Stores the read value from BUTTON.
int powerOnTune: tune for when the system is turned on.
int powerOffTune: tune for when the system is turned off.
int alarmTune: tune for when the alarm is triggered.
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
Updates the value of sensorState through 

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
Also informs the user by invoking both writeToLCD() and writeToSerialMonitor to tell them thar the alarm has been deactivated.
```
