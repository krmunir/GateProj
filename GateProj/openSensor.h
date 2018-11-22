// openSensor.h

#ifndef _GATESENSOR_h
#define _GATESENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class openSensor { 
private:
	int m_inputPin = 0;



public:
	openSensor(int InPin) : m_inputPin {InPin}
	{
		pinMode(m_inputPin, INPUT);
	}

	bool isClosed();
	bool isOpen();

};






#endif

