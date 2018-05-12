/*

  SensorManager.cpp - Library for getting curent heading from Compass model HMC6352.
  Created by Davi H. dos Santos, March 25, 2018.
  BSD license, all text above must be included in any redistribution.

*/


#include "Arduino.h"
#include "SensorManager.h"

SensorManager::SensorManager(){
  SD.begin(48);
}

//TODO
bool SensorManager::checkSensors(){
}

void SensorManager::read(){
  gps1.read();
  //compass1.read();
  wind.read();
  //magnetometer1.read();
  imu1.read();

	  while(Serial1.available() > 0){
	    in_char = Serial1.read();
	    data1 = String(in_char);
	    if(in_char != '\n') {
	      data2 = data2 + data1;
	    }
	  }
         //Serial.println(data2);
}

void SensorManager::readImu(){
  imu1.read();
}

GPSData SensorManager::getGPS(){
  return gps1.get();
}

Pose SensorManager::getMagnetometer(){
//  return magnetometer1.get();
}

float SensorManager::getCompass(){
 // return compass1.getHeading();
}

WindData SensorManager::getWind(){
  return wind.get();
}

IMUData SensorManager::getIMU(){
  return imu1.get();
}
  
void SensorManager::setThrusterPower(float thrusterPower){
  _thrusterPower = thrusterPower;
}

void SensorManager::setRudderAngle(float rudderAngle){
  _rudderAngle = rudderAngle;
}

void SensorManager::setWindSpeed(float windSpeed){
  _windData.speed = windSpeed;
}

void SensorManager::setdistanceTravelled(double distanceTravelled){
  _distanceTravelled = distanceTravelled;
}

//posição (lat, lon), velocidade do vento (direção, speed), posição dos atuadores (leme, vela), velocidade (speed) e orientação do gps (course), orientação da bussola (heading), informações do IMU (R, P, Y).
void SensorManager::logState(){

  if (gps1.get().date != "" && gpsDateCtrl == 0) {
    _experimentName = String(gps1.get().date+".csv");
    gpsDateCtrl = 1;

    dataFile = SD.open(_experimentName, FILE_WRITE);

    //first line of log file
    if (dataFile) {
      Serial.println("LOGGING");
      dataFile.print("Date");             dataFile.print(",");
      dataFile.print("TimeStamp");        dataFile.print(",");
      dataFile.print("Latitude");         dataFile.print(",");
      dataFile.print("Longitude");        dataFile.print(",");
      dataFile.print("Wind Direction");   dataFile.print(",");
      dataFile.print("Wind Speed");       dataFile.print(",");
      dataFile.print("Rudder Angle");     dataFile.print(",");
      dataFile.print("Sail Angle");       dataFile.print(",");
      dataFile.print("GPS Course");       dataFile.print(",");
      dataFile.print("GPS Speed");        dataFile.print(",");
      dataFile.print("Yaw");              dataFile.print(",");
      dataFile.print("Pitch");            dataFile.print(",");
      dataFile.print("Roll");             dataFile.print(",");
      dataFile.print("Magnetometer Heading");  dataFile.print(",");
      dataFile.print("OD");               dataFile.print(",");
      dataFile.print("POR");              dataFile.print(",");
      dataFile.print("Ph");               dataFile.print(",");
      dataFile.print("EC");               dataFile.print(",");
      dataFile.print("TDS");              dataFile.print(",");
      dataFile.print("S");                dataFile.print(",");
      dataFile.println("Water Temperature");
      digitalWrite(LED_BUILTIN, HIGH);
    }
    dataFile.close();
  }

  if (gpsDateCtrl == 1){
    dataFile = SD.open(_experimentName, FILE_WRITE);
    if (dataFile) {
      //Serial.println("LOGGING2");
      dataFile.print(gps1.get().dateFull);                  dataFile.print(",");
      dataFile.print(timeStamp, 2);                         dataFile.print(",");
      dataFile.print(gps1.get().location.latitude, 6);      dataFile.print(",");
      dataFile.print(gps1.get().location.longitude, 6);     dataFile.print(",");
      dataFile.print(wind.get().direction, 2);              dataFile.print(",");
      dataFile.print(wind.get().speed, 2);                  dataFile.print(",");
      dataFile.print(_rudderAngle, 2);                      dataFile.print(",");
      dataFile.print(_thrusterPower, 2);                    dataFile.print(",");
      dataFile.print(gps1.get().course, 2);                 dataFile.print(",");
      dataFile.print(gps1.get().speed, 2);                  dataFile.print(",");
      dataFile.print(imu1.get().eulerAngles.yaw, 2);        dataFile.print(",");
      dataFile.print(imu1.get().eulerAngles.pitch, 2);      dataFile.print(",");
      dataFile.print(imu1.get().eulerAngles.roll, 2);       dataFile.print(",");
      dataFile.print(imu1.get().heading, 2);                dataFile.print(",");
      dataFile.print(data2);       dataFile.print("\n");
     
      dataFile.close();
      timeStamp += 0.2;
      data2 = " ";
    }
  }
}

void SensorManager::printState()
{
	Serial.print(gps1.get().location.latitude, 6);
	Serial.print(" ");
	Serial.print(gps1.get().location.longitude, 6);
	Serial.print(" ");
	Serial.print(wind.get ().direction, 2);
	Serial.print(" ");
	Serial.print(wind.get().speed, 2);
	Serial.print(" ");
	Serial.print(_rudderAngle, 2);
	Serial.print(" ");
	Serial.print(_thrusterPower, 2);
	Serial.print(" ");
	Serial.print(gps1.get().course, 2);
	Serial.print(" ");
	Serial.print(gps1.get().speed, 2); 
	Serial.print(" ");
	Serial.print(imu1.get().eulerAngles.yaw, 2);
	Serial.print(" ");
	Serial.print(imu1.get().eulerAngles.pitch, 2);
	Serial.print(" ");
	Serial.print(imu1.get().eulerAngles.roll, 2);
	Serial.print(" ");
	Serial.println(imu1.get().heading, 2); 
}

