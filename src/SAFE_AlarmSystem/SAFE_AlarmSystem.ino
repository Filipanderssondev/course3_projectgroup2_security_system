// Library for the LiquidCrystal class, required
// to use LCD.
#include <LiquidCrystal.H>

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
int buttonPressTune = 600;
int buttonDebounce = 50;

// Variables for timestamps
unsigned long lastButtonPress;

// Variables for containing the value from a reading.
bool sensorState;
bool buttonState;

// Function declarations
void switchLED(int pinSlot); // pinSlot as parameter too set that slot as HIGH / ON
void writeToLCD(const char* LCDMessage);
void readPirSensor();

void setup()
{
  pinMode(BUZZER, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}

// Function definitions 
void writeToLCD(const char* LCDMessage)
{
  LCD.clear();
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