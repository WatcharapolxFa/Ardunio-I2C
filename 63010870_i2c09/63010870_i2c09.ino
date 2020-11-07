// Write data to I2C slave device
byte address,data,device;
#include <Wire.h>
void setup()
{
  Wire.begin(); // Start I2C bus
  Serial.begin(115200); // Setup serial for debug
  pinMode(LED_BUILTIN,OUTPUT);
  for(address = 1; address < 127; address++ ) // sets the value (range from 1 to 127)
  {
    Wire.beginTransmission(address); // transmit to address
    if (Wire.endTransmission() == 0) // I2C devices found
    {
    device = address;
    }
  }
}
void loop()
{

  Wire.requestFrom(device, 1); // recive 1 bytes from slave device
  byte f = Wire.read(); // Read pin state

  f = f & 0x0f;
  
  if ((f & 4) != 4)
    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on
  else
    digitalWrite(LED_BUILTIN, LOW); // turn the LED off
}
