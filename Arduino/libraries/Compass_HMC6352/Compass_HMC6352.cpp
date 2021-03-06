/*

  Compass_HMC6352.cpp - Library for getting curent heading from Compass model HMC6352.
  Created by Davi H. dos Santos, March 25, 2018.
  BSD license, all text above must be included in any redistribution.

*/


#include "Arduino.h"
#include "Compass_HMC6352.h"
#include "Wire.h"

Compass_HMC6352::Compass_HMC6352(float gridNorth){
  HMC6352Address = 0x42;
  slaveAddress = HMC6352Address >> 1;
  Wire.begin();
  sum = 0;
  _gridNorth = gridNorth;
  i = 0;
  numberOfReadings = 10;
}

void Compass_HMC6352::read(){
  sum = 0;
  for (int j = 1; j <= numberOfReadings; j++){
    Wire.beginTransmission(slaveAddress);
    Wire.write("A");
    Wire.endTransmission();
    delay(10);
    Wire.requestFrom(slaveAddress, 2);
    i = 0;
    while(Wire.available() && i < 2)
    { 
      headingData[i] = Wire.read();
      i++;
    }
    headingValue = headingData[0]*256 + headingData[1];
    _heading = headingValue/numberOfReadings;
   //  heading = -heading;
    _heading = _heading - _gridNorth;
    
    if (_heading > 180) _heading = _heading - 360;
    if (_heading < -180) _heading = _heading + 360;
    
    sum += _heading;
  }

  _heading = sum/10;
}

float Compass_HMC6352::getHeading(){
  return _heading;
}
