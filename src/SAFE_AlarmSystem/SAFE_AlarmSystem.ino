

// Library for the LiquidCrystal class, required
// to use LCD.
#include <LiquidCrystal.H>

// Variables for components connected to arduino.
const int BUZZER = 9;
const int BUTTON = 10;
const int PIR_SENSOR = 6;
const int RED_LED = 7;
const int GREEN_LED = 8; 

// Variables for containing the value from a reading.
int sensorState;
int buttonState;

// Frequency for alarm
int alarmTune = 700;

// Function for updating the PIR Sensor value
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

void readPirSensor()
{
  sensorState = digitalRead(PIR_SENSOR);
}