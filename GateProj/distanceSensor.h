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
	void m_checkIfClosing();
	void m_checkIfOpening();
	bool m_isOpening;
	bool m_isClosing;

public:
	distanceSensor() : m_distance{ 0 }, m_isClosing{ false }, m_isOpening{ false } 	{}
	
	bool isOpen();
	bool isClosed();
	bool isOpening();
	bool isClosing();
	bool isHalfOpen();
	bool isFullyOpen();
	int percent_open();
	void checkIfGateMoving();
	//for testing only
	//unsigned short m_readSensor();

};

#endif

