// distanceSensor.h

#ifndef _DISTANCESENSOR_h
#define _DISTANCESENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class distanceSensor {
private:
	int m_distance;
	//unsigned short m_readSensor();
public:
	distanceSensor() : m_distance{ 0 } 	{}
	
	//for testing only
	unsigned short m_readSensor();

	bool isOpen();
	bool isClosed();
	bool isOpening();
	bool isClosing();
	bool isHalfOpen();
	int percent_open();

};

#endif

