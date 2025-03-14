

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
int powerOffTune = 75;
int powerOnTune = 500;

// Variables for containing the value from a reading.
bool sensorState = false;
bool buttonState = false;

// Variables for button debounce
unsigned long lastButtonPress = 0; // Store last press time
const unsigned long buttonDebounce = 50; // Debounce time

// Function declarations
void writeToLCD(const char* LCDMessage);
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
  
  Serial.print("Button state: ");
  Serial.println(buttonState ? "PRESSED" : "NOT PRESSED");

  delay(500); 
  
  if (sensorState) { // If motion is detected
    Serial.println("Motion detected! Starting alarm...");
    alarmRinging();  // Trigger the alarm
  }

  // update LED logic to use red and green led?
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}

// Function definitions 
void writeToLCD(const char* LCDMessage, int row)
{
  // Sets cursor for centralized text
  // LCD.clear(); I (Sabina) have to read more about how to construct LCD output
  int textLength = strlen(LCDMessage);
  int padding = (16 - textLength) / 2;

  LCD.setCursor(padding, row); 
  LCD.print(LCDMessage);
}
void readPirSensor()
{
  sensorState = digitalRead(PIR_SENSOR);
}

void alarmRinging()
{
  // Reference the variable and function list to implement function
  if (sensorState) { // If motion detected, enter the function
    buttonState = false; // Reset buttonState to false

    // Use both of the writeTo functions to inform the user that the alarm has detected something 
    writeToLCD("Alarm: Intruder!", 0); // Shorter message for LCD
    Serial.println("Alarm triggered, Motion detected!"); // Message displayed in Serial monitor

    // Invoke the tone() function with no set duration
    tone(BUZZER, alarmTune); // Start the alarm sound with no set duration

    // Eternal loop for checking button state
    while (true) 
    {
      // Invoke checkButtonState inside the loop
      checkButtonState();

      // If buttonState returns true, invoke alarmDeactivated()
      if (buttonState) {
        alarmDeactivated();
        break;
      }
    }
  }
}

void checkButtonState()
{
  bool buttonRead = digitalRead(BUTTON); // Read button state

  if (buttonRead == HIGH && !buttonState) { // If button is pressed
    if (millis() - lastButtonPress > buttonDebounce) { // Debounce check
      buttonState = true; // Update state
      lastButtonPress = millis();
      Serial.println("Button Pressed!");
    }
  }
  if (buttonRead == LOW && buttonState) { // If button released
    if (millis() - lastButtonPress > buttonDebounce) { // Debounce check
      buttonState = false; // Mark button as released
      Serial.println("Button Released!");
    }
  }
}

void alarmDeactivated() 
{
  if (buttonState) { // If buttonState is true, enter the function
    noTone(BUZZER); // Stop the buzzer
    writeToLCD("Alarm deactivated.", 0); // add clear output
    Serial.println("Alarm deactivated.");
    buttonState = false; // Reset button state
    sensorState = false; // Reset motion sensor
  }
}