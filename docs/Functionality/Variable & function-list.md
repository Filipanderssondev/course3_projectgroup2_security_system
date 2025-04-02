# Official naming conventions of current project

### Variable List  
We use the `camelCase` naming convention for general variables.   
Constants should be named with **CAPITAL** letters:  
Initialization of variables/functions should be located **before** the running code (with commenting if need be).  
Definitions of variables/functions should be located **after** the running code.  

### Variable list:    
`{number} = pin slot`  

```cpp
const int BUZZER = 9;             // Pin slot for buzzer
const int BUTTON = 10;            // Pin slot for push button
const int PIR_SENSOR = 6;         // Pin slot for PIR sensor
const int RED_LED = 7;            // Pin slot for red LED
const int GREEN_LED = 8;          // Pin slot for green LED

int alarmTune = 700;              // Tune frequency for alarm trigger
int alarmModeOffTune = 75;        // Tune frequency for alarm mode OFF
int alarmModeOnTune = 500;        // Tune frequency for alarm mode ON
int buttonPressTune = 600;        // Tune frequency for button press

bool sensorState = false;         // Stores value from PIR_SENSOR
bool buttonState = false;         // Tracks state of BUTTON (pressed/released)
bool currentButtonState;          // Temporary BUTTON pin reading used in checkButtonState() logic

unsigned long lastButtonPress = 0;            // Stores last button press time
const unsigned long buttonDebounce = 300;     // Debounce duration for button (ms)

unsigned long lastLEDBlink = 0;               // Tracks last RED_LED blink time

bool alarmActive = false;                     // Tracks if alarm is active
bool alarmMode = false;                       // Tracks if alarm mode is ON/OFF
bool alarmTriggeredOnce = false;              // Prevents repeated alarm triggers
bool waitingForPIRClear = false;              // Waits for PIR sensor to reset (LOW) when activating


```

### Function list: 
```cpp
void switchLED(int pinSlot);
void handleBlinkingLED();
void readPirSensor();
void writeToLCD(const char* LCDMessage, int row, bool clearDisplay = false);
void alarmRinging();
void alarmDeactivated();
void checkButtonState();
void handleButtonPress();
```

### Function explanations:
```cpp
switchLED(int pinSlot)
// Turns ON the specified LED (RED_LED or GREEN_LED) and turns OFF the other.

handleBlinkingLED()
// Blinks RED_LED every 200 ms while alarm is active.

readPirSensor()
// Updates sensorState with the current PIR_SENSOR reading.

writeToLCD(const char* LCDMessage, int row, bool clearDisplay = false)
// Prints LCDMessage to the specified row on LCD.
// clearDisplay (default false) clears the LCD before printing.
// Text is centered on a 16-character line.

alarmRinging()
// Activates the alarm: sets alarmActive = true, plays alarmTune, and displays/logs alarm status.

alarmDeactivated()
// Stops the alarm, resets system to safe mode, updates LEDs and messages.

checkButtonState()
// Handles button debounce and press/release detection.
// On press, triggers sound and calls handleButtonPress().

handleButtonPress()
// Handles logic for toggling alarm mode or deactivating alarm.
// Plays corresponding tunes, updates LEDs, resets flags, and logs actions.
```
