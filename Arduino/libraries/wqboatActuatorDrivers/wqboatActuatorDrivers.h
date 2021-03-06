/*

  wqboatActuatorDrivers.h - Library for the low level commands to put the actuators in a desired position.
  Created by Davi H. dos Santos, March 31, 2018.
  BSD license, all text above must be included in any redistribution.

*/

#ifndef wqboatActuatorDrivers_h
#define wqboatActuatorDrivers_h

#include "Arduino.h"
#include "Servo.h"

class wqboatActuatorDrivers
{
  public:
    wqboatActuatorDrivers(int rudderPin, int sailPin);
    wqboatActuatorDrivers();

    void setRudderAngle(float rudderAngle);
    void setThrusterPower(float thrusterPower);

    float getRudderAngle();
    float getThrusterPower();    

    void initThruster();
  private:
    Servo rudder, thruster;
    int _rudderPin = 12, _thrusterPin = 9;

     //TODO calibrate. lower limit = boat turns counterclockwise
    float _rudderLowerLimit = 50, _rudderUpperLimit = 130; 

    //TODO calibrate. lower limit = low power on thruster
    float _thrusterLowerLimit = 15, _thrusterUpperLimit = 120;
     //float _thrusterLowerLimit = 95, _thrusterUpperLimit = 100;

     int init_thruster = 1;

     int cont = 0;   

};

#endif
