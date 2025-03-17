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
bool buttonRead;

// Variables for button debounce
unsigned long lastButtonPress = 0; // Store last press time
const unsigned long buttonDebounce = 100; // Debounce time

// Variable for tracking if alarm is active
bool alarmActive = false;

// Timer variables for alarm loop (previous blocked)
unsigned long lastAlarmCheck = 0;
const unsigned long alarmInterval = 100; // ms between alarmchecks

// Function declarations
void switchLED(int pinSlot); // pinSlot as parameter too set that slot as HIGH / ON
void writeToLCD(const char* LCDMessage, int row);
void readPirSensor();
void alarmDeactivated();
void alarmRinging();
void checkButtonState();

void setup()
{
  Serial.begin(9600);
  
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT); // Replace with RGB LED (RED_LED, OUTPUT and GREEN_LED, OUTPUT)
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

  // If motion is detected and alarm is not active
  if (sensorState && !alarmActive) {
    alarmRinging(); // Trigger the alarm
  }

}

// Function definitions 

void writeToLCD(const char* LCDMessage, int row)
{
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

void alarmRinging()
{
  // If alarm is not already active, trigger it
  if (!alarmActive) {
    alarmActive = true; // Mark alarm as active
    tone(BUZZER, alarmTune); // Start buzzer sound
    LCD.clear();
    writeToLCD("Alarm: Intruder!", 0); // Notify user
    Serial.println("Alarm triggered, Motion detected!");

    //Enter a eternal loop
    while (true)
    {

      // Non-blocking check for deactivating alarm
    if (alarmActive) {
      if (millis() - lastAlarmCheck >= alarmInterval) {
        lastAlarmCheck = millis(); // Update timer
        checkButtonState(); // Check if button is pressed

      if (buttonState) {
          alarmActive = false; // Reset alarm status
          alarmDeactivated(); // Stop alarm if button pressed
      }
    }
  }
    }
  }
}

void checkButtonState()
{
  buttonRead = digitalRead(BUTTON); // Read button state

  if (buttonRead == HIGH && !buttonState) { // If button is pressed
    if (millis() - lastButtonPress >= buttonDebounce) { // Debounce check
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
  if (buttonState) { // If buttonState is true, enter the function
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

    break;
  }
}