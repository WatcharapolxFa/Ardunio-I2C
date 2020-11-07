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
    Serial.print("\n I2C Device Address: "); // Print Device Address
    Serial.println(address, HEX); // print as an ASCII-encoded hexa);
    }
  }
  data = 111;
}
void loop()
{
  Wire.beginTransmission(device);
  Wire.write(data);
  Wire.endTransmission();
  
  Wire.requestFrom(device, 1); // recive 1 bytes from slave device
  byte x = Wire.read(); // Read pin state
  Serial.print("\t pin state : In = "); // Print pin state
  Serial.println(x, BIN); // print as an ASCII-encoded binary);
  x = x & 0x0f;
  if ((x & 4) != 4)
    data |= 16;
  else
    data &= 239;
}
