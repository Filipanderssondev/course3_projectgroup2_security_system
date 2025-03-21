// Library for the LiquidCrystal class, required
// to use LCD.
#include <LiquidCrystal.h>
#include <Keypad.h>

// Initialize LCD with pin: (RS, E, D4, D5, D6, D7)
LiquidCrystal LCD(11, 12, 2, 3, 4, 5);

// Variables for components connected to arduino.
const int BUZZER = 9;
const int BUTTON = 10;
const int PIR_SENSOR = 6;
const int RED_LED = 7;
const int GREEN_LED = 8; 

// Frequencies for diffrent tunes  
int alarmTune = 700;
int alarmModeOffTune = 75;
int alarmModeOnTune = 500;
int buttonPressTune = 600;

// Variables for containing the value from a reading.
bool sensorState = false;
bool buttonState = false;
bool alarmEnabled = false;
bool doItOnceAlarmModeOn = true;
bool doItOnceAlarmModeOff = true;
bool buttonRead; //variable used for the logic of checkButtonState
bool clearDisplay; //Determine whether or not to wipe the LCD screen before printing.

// Variables for button debounce
unsigned long lastButtonPress = 0; // Store last press time
const unsigned long buttonDebounce = 300; // Debounce time

// Variables for password
const int MAX_INDEX = 4; // Used for loops aswell
int currentIndexOfAttempt; // Keep track of what index is being stored in password attempt
bool createPassword; // Not used 
char storedKey; // Store key from keypad
const char presetPassword[MAX_INDEX] = {'1','3','3','7'}; // Preset password
char passwordAttempt[MAX_INDEX]; // Variable for comparing with preset password
int wrongPassword;

// Keypad initialization
unsigned long timerStart = 0;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {13, A5, A4, A3}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {A2, A1, A0, 0}; // Connect to the column pinouts of the keypad
// Keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS );

unsigned lastLEDBlink = 0;

// Flag for tracking if alarm is active
bool alarmActive = false;

// Flag for tracking if alarm mode is ON/OFF
bool alarmMode = false;

// Flag for blocking repeated alarm triggers until alarm mode is reactivated
bool alarmTriggeredOnce = false;

// Flag to wait for PIR to reset to LOW when alarm mode is activated
bool waitingForPIRClear = false;

// Function declarations
void switchLED(int pinSlot); // pinSlot as parameter too set that slot as HIGH / ON
void blinkingLED();
void writeToLCD(const char* LCDMessage, int row, bool clearDisplay = false);
void readPirSensor();
void alarmDeactivated();
void alarmRinging();
void checkButtonState();
void handleButtonPress();
void handleBlinkingLED();

// Password / keypad functions
char getStoredKey();
void createPasswordAttempt();
bool comparePassword(char* attempt);

void setup()
{
  Serial.begin(9600);

  pinMode(BUZZER, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT); 
  pinMode(BUTTON, INPUT);
  pinMode(PIR_SENSOR, INPUT);

  // Initialize LCD
  LCD.begin(16, 2);
  writeToLCD("SAFE", 0);
  writeToLCD("SECURITY SYSTEM", 1);

  Serial.println("System Initialized.");
}

void loop()
{
  getStoredKey(); // Check key presses 
  checkButtonState();  // Always check for button press

  // Wait until PIR sensor resets to LOW after alarm mode is activated
  if (waitingForPIRClear) {
    if (digitalRead(PIR_SENSOR) == LOW) {
      waitingForPIRClear = false;  // Sensor is ready
      Serial.println("PIR cleared - system ready.");
    }
    return; // Skip loop until PIR is cleared
  }

  if (alarmMode) {
    readPirSensor();  // Read PIR only when alarm mode is ON

    // If motion is detected and alarm is not active, trigger the alarm
    if (sensorState && !alarmActive && !alarmTriggeredOnce) {
      alarmRinging(); // Trigger the alarm
    }
  }

  // Blinking LED during active alarm
  if (alarmActive) {
    handleBlinkingLED(); // LED blinking every 200 ms
  }
}

// Function definitions 

void writeToLCD(const char* LCDMessage, int row, bool clearDisplay)
{
  if (clearDisplay)
  {
    LCD.clear();
  }

  int textLength = strlen(LCDMessage);
  int padding = (16 - textLength) / 2;
  if (padding < 0) padding = 0;

  LCD.setCursor(0, row); 
  LCD.print("                ");
  LCD.setCursor(padding, row); 
  LCD.print(LCDMessage);
}

void readPirSensor()
{
  sensorState = digitalRead(PIR_SENSOR);
}

void switchLED(int pinSlot)
{
  if (pinSlot == GREEN_LED)
  {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }
  else if (pinSlot == RED_LED)
  {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }
  else 
  {
    Serial.println("Wrong pin slot determined.");
  }
}

void handleBlinkingLED()
{
  if (millis() - lastLEDBlink >= 200)
  {
    lastLEDBlink = millis();
    digitalWrite(RED_LED, !digitalRead(RED_LED));
  }
}

void alarmRinging()
{
  // If alarm is not already active, trigger it
  if (!alarmActive && !alarmTriggeredOnce) {
    alarmActive = true; // Mark alarm as active
    alarmTriggeredOnce = true; // Block further alarms
    tone(BUZZER, alarmTune); // Start buzzer
    digitalWrite(GREEN_LED, LOW);
    writeToLCD("Alarm: Intruder!", 0, true);
    Serial.println("Alarm triggered, Motion detected!");
  }
}


void checkButtonState() {

  buttonRead = digitalRead(BUTTON); // Read button state

  if (buttonRead == HIGH && !buttonState) { // If button is pressed
    if (millis() - lastButtonPress >= buttonDebounce) {
      tone(BUZZER, buttonPressTune, 150); // Make a sound for 150 ms
      buttonState = true; // Update state
      lastButtonPress = millis();
      Serial.println("Button Pressed!"); // Log button press

      handleButtonPress(); // Call the new function to handle the button logic
    }
  }

  if (buttonRead == LOW && buttonState) { // If button is released
    if (millis() - lastButtonPress >= buttonDebounce) {
      buttonState = false; // Mark button as released
      Serial.println("Button Released!");
    }
  }
}

// New function to handle the button press logic
void handleButtonPress() {
  if (alarmActive) {
    alarmActive = false; // Reset alarm status
    alarmDeactivated(); // Stop alarm if button pressed
  } else {
    alarmMode = !alarmMode; // Toggle alarm mode

    if (alarmMode) {
      sensorState = digitalRead(PIR_SENSOR); // Read sensor on activation
      if (sensorState == HIGH) {
        waitingForPIRClear = true;  // Wait for PIR to reset
        Serial.println("PIR HIGH on activation - waiting for LOW...");
      }
      sensorState = false;
      alarmTriggeredOnce = false; // Reset block
      tone(BUZZER, alarmModeOnTune, 200);
      writeToLCD("Alarm mode", 0, true);
      writeToLCD("ON", 1);
      switchLED(RED_LED);
      Serial.println("Alarm mode ON.");
    } else {
      tone(BUZZER, alarmModeOffTune, 200);
      writeToLCD("Alarm mode", 0, true);
      writeToLCD("OFF", 1);
      switchLED(GREEN_LED);
      Serial.println("Alarm mode OFF.");
      sensorState = false;
      noTone(BUZZER);
      digitalWrite(RED_LED, LOW); // Ensure RED_LED is off
    }
  }
}

void alarmDeactivated() 
{
  noTone(BUZZER); // Stop the buzzer
  writeToLCD("Alarm", 0);
  writeToLCD("deactivated", 1);
  Serial.println("Alarm deactivated.");
  sensorState = false;// Reset motion sensor
  alarmMode = false;
  switchLED(GREEN_LED); // Set LED status
  //digitalWrite(RED_LED, LOW); // Ensure RED_LED is off
  //digitalWrite(GREEN_LED, HIGH); // Ensure GREEN_LED is on
  
  buttonState = false;
}
char getStoredKey()
{
  // Read from keyPad object.
  storedKey = keypad.getKey();
  
  // Press asterix to activate password input
  if (storedKey == '*')
  {
    createPasswordAttempt();
  }
  // Return key only if it is pressed
  if (storedKey){
    return storedKey;
  }
}

bool comparePassword(char* attempt)
{ 
  // Return false if any index is wrong.
  for (int i = 0; i < MAX_INDEX; i++)
  {
    if (attempt[i] != presetPassword[i])
  	{
      return false;
     
    }
  }
  return true;
}

void createPasswordAttempt()
{ 
  // Reset index to 0
  currentIndexOfAttempt = 0;
  wrongPassword = 0;
  
  // STOP THE ALARM WAIT FOR INPUT?
  // Timer when entering function 
  unsigned long startTime = millis();
  
  Serial.println("You have 15s to enter correct password: ");
  
  // Loop until password is correct or 15s have run out.
  while (currentIndexOfAttempt < MAX_INDEX && millis () - startTime <= 15000)
  {
    // Store the newKey inside this loop
    char newKey = getStoredKey();
    
    if (startTime == 14999)
    {
		Serial.println("SOUND THE ALARM!");
    }
    // Keep the loop going
    if (currentIndexOfAttempt < MAX_INDEX)
    {
      // assign newKey to passwordAttempt
      passwordAttempt[currentIndexOfAttempt] = newKey;
    	
      if (newKey)
      {
        Serial.println(newKey);
        currentIndexOfAttempt++;
        
        // Compares the password attempt
        if (currentIndexOfAttempt == MAX_INDEX)
        {
          Serial.println("Checking password....");

          if (comparePassword(passwordAttempt))
          {
            // Run code here if password true
            alarmDeactivated();
            alarmActive = false;
            writeToLCD("Password", 0,true);
            writeToLCD(" correct", 1);
            break;
          }
          else
          {
            alarmRinging();
            writeToLCD("Password", 0,true);
            writeToLCD(" incorrect", 1);
            break;
          }
        }
      }
    }
  }
}