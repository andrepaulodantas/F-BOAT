/*

  BoatControl.h - Library containing the movement controllers used in Nboat project.
  Created by Davi H. dos Santos, March 31, 2018.
  BSD license, all text above must be included in any redistribution.

*/

#ifndef BoatControl_h
#define BoatControl_h

#include "Arduino.h"
#include "Location.h"
#include "GPS.h"
#include "Compass.h"
#include "ActuatorsDrivers.h"

class BoatControl
{
  public:
    BoatControl();
    void rudderHeadingControl(Location target);
    void thrusterControl(Location target, float mediumDistance = 10.0, float closeDistance = 5.0);
    float adjustFrame(float angle);
    float P(float currentError);
    float I(float currentError);
    float rudderAngleSaturation(float sensor);
  private:
    float _heading, _sp, _currentError, rudderAngle_prior, rudderAngle, I_prior, _cycleTime, _kp, _ki, _starttime, _endtime, _distanceToTarget;
    GPS _gps;
    Compass _compass;
    Location _currentPosition;
    ActuatorsDrivers _actuators;

};

#endif
