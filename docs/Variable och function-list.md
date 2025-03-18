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
bool buttonRead // Evaluates the buttonState
bool doItOnce: // Makes the first part of alarmModeOn only execute once per call. 
bool clearDisplay: Determines if the display should be cleared or not before printing. 

int alarmModeOnTune: tune for when the system is turned on.
int alarmModeOffTune: tune for when the system is turned off.
int alarmTune: tune for when the alarm is triggered.
int buttonPressTune: Tune for when a push-button or 4x4 button is pressed. 

unsigned long lastButtonPress = 0: // Store last press time
const unsigned long buttonDebounce = 100: // Debounce time
unsigned lastLEDBlink: //Store last blink of the Red LED.
```

### Function list: 
```cpp
void switchLED(int pinSlot);
void blinkingLED();
void readPirSensor();
void writeToLCD(const char* LCDMessage, int row, bool clearDisplay = false);
void writeToSerialMonitor(const char* SerialMessage);
void alarmModeOn();
void alarmModeOff();
void alarmActivated();
void alarmDeactivated();

```

### Function explanations:
```cpp
switchLED(int pinSlot).
Depending on the pinSlot parameter, turns on/off RED_LED and GREEN_LED.
if the parameter is GREEN_LED, turns on GREEN_LED and turns off RED_LED and vice versa. 

blinkingLED().
Makes the RED_LED blink roughly every half second. Used in the alarmRinging() function.

readPirSensor().
Updates the value of sensorState through digitalRead(PIR_SENSOR).

writeToLCD(const char* LCDMessage, int row, bool clearDisplay = false).
The content of the LCDMessage parameter passed into the function is printed on the LCD display using the LiquidCrystal class’ print() method.
The row parameter determine whether or not the message is printed on the first or second line.
The clearDisplay parameter determine whether or not to call the LiquidCrystal class' .clear() method before printing, has false as default value.


writeToSerialMonitor(const char* SerialMessage).
The content of the parameter passed into the function is printed on the Serial monitor using the Serial objects. print() method.

alarmModeOn().
The Alarm is standing by and mnonitoring (its on and searching for motion)

alarmModeOff().
The Alarm is not standing by and monitoring (its off and not searching for motion)

alarmActivated().
Invoke the tune() function with alarmTune as frequency, enters a loop until alarmDeactivated() is invoked by pressing the button while in the loop.

alarmDeactivated()
Waits for buttonState to record a change in the state of the BUTTON, thereafter proceed with breaking out of the loop caused by alarmRinging(), followed immediately by invoking noTune(BUZZER) to turn off the alarm. 
Also informs the user by invoking both writeToLCD() and writeToSerialMonitor to tell them that the alarm has been deactivated.
```
