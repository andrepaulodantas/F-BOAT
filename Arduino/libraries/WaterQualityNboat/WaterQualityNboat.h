/*

	WaterQualityNboat.h - Library for monitoring water quality into system
	Created by Andouglas Goncalves da Silva Junior, April 4, 2018
	Released into Nboat private folder
*/

#ifndef WaterQualityNboat_h
#define WaterQualityNboat_h

#include "Arduino.h"

class WaterQualityNboat
{
	public:
		WaterQualityNboat();
		WaterQualityNboat(int addr_ph, int addr_por, int addr_oxigen, int addr_temperature, int addr_condutivity);
		void startCommunication(int address);
		void closeCommunication();
		float getData(int sensorId, char * cmd);
		void sendData(char * cmd);
		void requestData(int address);
		bool dataAvailable();
		byte read();
		float * WaterQualityNboat::getAllData();
		float getDataTemperature();

	private:
		int _sensorId;
		char * _cmd;
		byte code;
		int _addr_ph = 99;
		int _addr_por = 98;
		int _addr_oxigen = 97;
		int _addr_temperature;
		int _addr_condutivity = 100;
		int time_ = 900;
		char _data[20];
		float _dataFloat;		

};

#endif