const int PIR_SENSOR = 6;
const int LED = 7;

// External value for state (used for the while loop)
bool sensorState; 

// Use inside while loop instead of delay() 
unsigned long previousTime = 0;
const int interval = 500; // 1 second

// Class for Sensor handling
class Sensor {
private:
  int value;
  bool state;
public:
  // Set value (0 , 1) of the Sensor
  Sensor ()
  {
    value = 0;
    state = false;
  }
  
  // Initializing value with reading from PIR_SENSOR(HIGH/1 or LOW/0)
  void sensorVal()
  {
    value = digitalRead(PIR_SENSOR);
  }
  
  // Getter for the current state (want to save the value externally to run the loop)
  bool getStateOfSensor()
  {
    return state; 
  }
  
  // Set true if motion has been detected detected 
  bool detectMotion()
  {
    // Evaluates the PIR Sensors reading
    sensorVal();
    
    if (value == 1)
    {
      Serial.println("Motion detected!");
      return state = true;
    }
    
    if (value == 0)
    {
      Serial.println("Searching .....");
      return state = false; 
    }
  }
};

// Inititalize an obj of Sensor
Sensor pirObj;

/*
void setSensorState(int pinNumber, bool checked);
bool detectMotion(int sensor);
*/

void setup()
{
  pinMode(PIR_SENSOR, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{ 
  pirObj.detectMotion();
  if (pirObj.getStateOfSensor() == true)
  {
    sensorState = true;
  }
  
  // If motion detected, run this loop? Needs a little bit of work 
  while (sensorState == true)
  {
    unsigned long currentTime = millis();
    
    if (currentTime - previousTime >= interval) {
      digitalWrite(LED, HIGH);
      previousTime = currentTime; // Update time
      digitalWrite(LED, LOW);  	
    }
  }
  
  delay(500);
}