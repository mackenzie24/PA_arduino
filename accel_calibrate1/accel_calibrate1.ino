#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>

/* Assign a unique ID to accelerometer*/
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(54321);

long lastDisplayTime;

void setup(void) 
{
  Serial.begin(9600);
  // beginning accelerometer setup
  Serial.println("LSM303 Calibration"); Serial.println("");
  
  /* Initialise the accelerometer */
  if(!accel.begin())
  {
    /* There was a problem detecting the ADXL345 ... check your connections */
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    while(1);
  }
  lastDisplayTime = millis();
  // end of accelerometer setup
}

void loop(void) 
{
  // beginning of accelerometer
  /* Get accelerometer sensor event */ 
  sensors_event_t accelEvent; 
  accel.getEvent(&accelEvent);

  if ((millis() - lastDisplayTime) > 1000)  // display once/second
  {
    Serial.print("Accel X: ");
    Serial.print(accelEvent.acceleration.x);
    Serial.print("/tAccel Y: ");
    Serial.print(accelEvent.acceleration.y);
    Serial.print("/tAccel Z: ");
    Serial.println(accelEvent.acceleration.z);
    
    lastDisplayTime = millis();
  }
  // end of accelerometer
}
