// Write data to I2C slave device
#include <Wire.h>
byte address,data,device,x;
byte Ar1 = 23, Ar2 = 55,Ar3 = 39, Ar4 = 71,Ar5=103,Ar6=199,Ar7=135,Ar8=151;
void setup()
{
 Wire.begin(); // Start I2C bus
 Serial.begin(115200); // Setup serial for debug

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
   
}
void loop()
{

 Wire.requestFrom(device, 1); // recive 1 bytes from slave device
 x = Wire.read(); // Read pin state
 x = x & 0x0f;
  if ((x & 1) != 1)
  {
        Wire.beginTransmission(device); // transmit to device
        Wire.write(Ar8); // sends one byte
        Wire.endTransmission(); // stop transmitting
        delay(5); // wait for stepper speed

        Wire.beginTransmission(device); // transmit to device
        Wire.write(Ar7); // sends one byte
        Wire.endTransmission(); // stop transmitting
        delay(5); // wait for stepper speed

        Wire.beginTransmission(device); // transmit to device
        Wire.write(Ar6); // sends one byte
        Wire.endTransmission(); // stop transmitting
        delay(5); // wait for stepper speed

        Wire.beginTransmission(device); // transmit to device
        Wire.write(Ar5); // sends one byte
        Wire.endTransmission(); // stop transmitting
        delay(5); // wait for stepper speed
        Wire.beginTransmission(device); // transmit to device
        Wire.write(Ar4); // sends one byte
        Wire.endTransmission(); // stop transmitting
        delay(5); // wait for stepper speed

        Wire.beginTransmission(device); // transmit to device
        Wire.write(Ar3); // sends one byte
        Wire.endTransmission(); // stop transmitting
        delay(5); // wait for stepper speed

        Wire.beginTransmission(device); // transmit to device
        Wire.write(Ar2); // sends one byte
        Wire.endTransmission(); // stop transmitting
        delay(5); // wait for stepper speed

        Wire.beginTransmission(device); // transmit to device
        Wire.write(Ar1); // sends one byte
        Wire.endTransmission(); // stop transmitting
        delay(5); // wait for stepper speed

 }
 else
 {
        Wire.beginTransmission(device); // transmit to device
        Wire.write(Ar1); // sends one byte
        Wire.endTransmission(); // stop transmitting
        delay(5); // wait for stepper speed

        Wire.beginTransmission(device); // transmit to device
        Wire.write(Ar2); // sends one byte
        Wire.endTransmission(); // stop transmitting
        delay(5); // wait for stepper speed

        Wire.beginTransmission(device); // transmit to device
        Wire.write(Ar3); // sends one byte
        Wire.endTransmission(); // stop transmitting
        delay(5); // wait for stepper speed

        Wire.beginTransmission(device); // transmit to device
        Wire.write(Ar4); // sends one byte
        Wire.endTransmission(); // stop transmitting
        delay(5); // wait for stepper speed

        Wire.beginTransmission(device); // transmit to device
        Wire.write(Ar5); // sends one byte
        Wire.endTransmission(); // stop transmitting
        delay(5); // wait for stepper speed

        Wire.beginTransmission(device); // transmit to device
        Wire.write(Ar6); // sends one byte
        Wire.endTransmission(); // stop transmitting
        delay(5); // wait for stepper speed

        Wire.beginTransmission(device); // transmit to device
        Wire.write(Ar7); // sends one byte
        Wire.endTransmission(); // stop transmitting
        delay(5); // wait for stepper speed

        Wire.beginTransmission(device); // transmit to device
        Wire.write(Ar8); // sends one byte
        Wire.endTransmission(); // stop transmitting
        delay(5); // wait for stepper speed

 }
 

 

}
