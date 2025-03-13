

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

// Variables for containing the value from a reading.
bool sensorState;
bool buttonState;

// Function declarations
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