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
	enum status {
		IS_OPEN,
		IS_CLOSED,
		IS_OPENING,
		IS_CLOSING,
		IS_HALF_OPEN,
		IS_FULLY_OPEN,
		UNDEFINED
	} m_gateStatus;

public:
	distanceSensor() : m_distance{ 0 }, m_gateStatus{ UNDEFINED } 	{}
	
	void statusCheckStateMachine();

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

