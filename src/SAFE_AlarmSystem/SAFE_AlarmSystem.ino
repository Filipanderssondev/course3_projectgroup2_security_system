// Library for the LiquidCrystal class, required
// to use LCD.
#include <LiquidCrystal.h>

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
const unsigned long buttonDebounce = 100; // Debounce time

unsigned lastLEDBlink = 0;

// Variable for tracking if alarm is active
bool alarmActive = false;

// Timer variables for alarm loop (previous blocked)
//unsigned long lastAlarmCheck = 0;
//const unsigned long alarmInterval = 100; // ms between alarmchecks

// Function declarations
void switchLED(int pinSlot); // pinSlot as parameter too set that slot as HIGH / ON
void blinkingLED();
void writeToLCD(const char* LCDMessage, int row, bool clearDisplay = false);
void readPirSensor();
void alarmDeactivated();
void alarmRinging();
void checkButtonState();
void alarmModeOn();
void alarmModeOff();

void setup()
{
  Serial.begin(9600);
  
  pinMode(BUZZER, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT); 
  pinMode(BUTTON, INPUT);
  pinMode (PIR_SENSOR, INPUT);

  // Initialize LCD
  LCD.begin(16, 2);
  writeToLCD("SAFE", 0);
  writeToLCD("SECURITY SYSTEM", 1);

  Serial.println("System Initialized.");
}

void loop()
{
  readPirSensor(); // Check PIR sensor
  checkButtonState(); // Check button state
	
  // Start alarm
  if (buttonState == HIGH && !alarmActive)
  {
    alarmEnabled = !alarmEnabled;
    buttonState = false;
  }
	
  if (alarmEnabled)
  {
    alarmModeOn();
    doItOnceAlarmModeOff = true;
    // If block for chekcing motion
    if (sensorState && !alarmActive) 
    {
    	alarmRinging(); // Trigger the alarm
  	}
  }
  
  else
  {
    alarmModeOff();
    doItOnceAlarmModeOn = true;
  }
  //delay (250);
}

// Function definitions 

void writeToLCD(const char* LCDMessage, int row, bool clearDisplay) //only resets if LCD if specified.
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

void blinkingLED()
{

  if (millis() - lastLEDBlink >= 200)
  {

      digitalWrite(RED_LED, !digitalRead(RED_LED));
      lastLEDBlink = millis();
  }

}

void alarmRinging()
{
  // If alarm is not already active, trigger it
  if (!alarmActive) {
    alarmActive = true; // Mark alarm as active
    tone(BUZZER, alarmTune); // Start buzzer sound
    //LCD.clear();
    writeToLCD("Alarm: Intruder!", 0, true); // Notify user
    Serial.println("Alarm triggered, Motion detected!");

    //Enter loop
    if (alarmActive)
    {

      blinkingLED(); //LED blinking every 200 ms.

      // Non-blocking check for deactivating alarm
    //if (alarmActive) {
      //if (millis() - lastAlarmCheck >= alarmInterval) {
        //lastAlarmCheck = millis(); // Update timer
        //checkButtonState(); // Check if button is pressed

      if (buttonState) {
          alarmActive = false; // Reset alarm status
          alarmDeactivated(); // Stop alarm if button pressed
      }
    }
  }
}


void checkButtonState()
{
  buttonRead = digitalRead(BUTTON); // Read button state

 
  if (buttonRead == HIGH && !buttonState) { // If button is pressed
    if (millis() - lastButtonPress >= buttonDebounce) { // Debounce check

      tone(BUZZER, buttonPressTune, 50); //make a sound for 150 ms.
      buttonState = true; // Update state
      lastButtonPress = millis();
      Serial.println("Button Pressed!");
    }
  }
  if (buttonRead == LOW && buttonState) { // If button released
    if (millis() - lastButtonPress >= buttonDebounce) { // Debounce check
      buttonState = false; // Mark button as released
      Serial.println("Button Released!");
    }
  }
}

void alarmDeactivated() 
{
  //if (buttonState) { // If buttonState is true, enter the function
    noTone(BUZZER); // Stop the buzzer
    //LCD.clear();
    //writeToLCD("Alarm deactivated.", 0); // add clear output
    //LCD.clear();
	  //LCD.setCursor(0, 0);
	  //LCD.print("Alarm deactivated.");
    writeToLCD("Alarm", 0);
	  writeToLCD("deactivated", 1);

    Serial.println("Alarm deactivated.");
    buttonState = false; // Reset button state
    sensorState = false; // Reset motion sensor
  //}
}

// Probably need some rework?
void alarmModeOn()
{
    // Run this block once every time function alarmModeOn() is called.
    // Initialize doItOnce in setup() as true?
    if (doItOnceAlarmModeOn)
    {
      // buttonState = false; 
      switchLED(RED_LED); // Turn on red led.
      writeToLCD("ALARM MODE", 0, true); // Clear and write new message
      writeToLCD("ON", 1, false);
      Serial.println("ALARM IS ACTIVE! Searching....");
      doItOnceAlarmModeOn = false;
    }
    /*
    if (buttonState)
    {
      doItOnceAlarmModeOn = true;
    }
  	*/
}

void alarmModeOff()
{
  if (doItOnceAlarmModeOff)
  {
    // buttonState = false;
    switchLED(GREEN_LED); //Turn the led green
    writeToLCD("ALARM MODE ", 0, true); // Clear and write new message
    writeToLCD("OFF", 1);
    doItOnceAlarmModeOff = false;
  }
}