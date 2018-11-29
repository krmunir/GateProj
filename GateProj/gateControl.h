// gateControl.h

#ifndef _GATECONTROL_h
#define _GATECONTROL_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class gateControl {
private:
	int m_outputPinNo = 0;
	void m_gateButtonPress();
	void m_changeDirection();

public:
	enum command {
		NONE,
		FULL_OPEN,
		HALF_OPEN,
		FULL_CLOSE,
		STOP
	};

	command currCommand;

	gateControl(int outputPinNo) : m_outputPinNo{ outputPinNo }, currCommand{NONE}
	{
		pinMode(m_outputPinNo, OUTPUT);
	}

	void fullOpen();
	void fullClose();
	void halfOpen();
	void stop();


};


#endif

