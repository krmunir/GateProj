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
	unsigned short m_readSensor();
	bool m_isWithin(unsigned short readvalue, unsigned short targetvalue, unsigned short tolerance);

public:
	distanceSensor() : m_distance{ 0 }, m_gateStatus{ UNDEFINED } 	{}
	
	bool isOpen();
	bool isClosed();
	bool isOpening();
	bool isClosing();
	bool isHalfOpen();
	bool isFullyOpen();
	int percent_open();

	//for testing only
	//unsigned short m_readSensor();

};

#endif

