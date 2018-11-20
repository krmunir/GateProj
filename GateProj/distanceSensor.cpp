// 
// 
// 

#include "distanceSensor.h"
#include <SoftwareSerial.h>
#include "utilities.h"

//need to access these constants defined in GateProj.ino
extern const uint8_t slidingGateDistanceSensor_RX;
extern const uint8_t slidingGateDistanceSensor_TX;
extern const uint8_t SLIDING_GATE_CLOSED_LS_PIN;
extern const uint8_t SLIDING_GATE_FULL_OPEN_LS_PIN;
extern const unsigned short gateClosedReading;
extern const unsigned short gateHalfOpenReading;
extern const unsigned short gateFullyOpenReading;
extern const unsigned short readingTolerance;

//need to provide access to these outside of this file
extern SoftwareSerial slidingGateDistanceSensorSerial(slidingGateDistanceSensor_RX, slidingGateDistanceSensor_TX, true); //sig from sensor is inverted


bool distanceSensor::isOpen() {
	if (!isClosed())
		return true;
	else
		return false;

}

bool distanceSensor::isClosed() {
	if (digitalRead(SLIDING_GATE_CLOSED_LS_PIN) == HIGH)
		return true;
	else
		return false;
}

int distanceSensor::percent_open() {
	return (m_readSensor() - gateFullyOpenReading) / (gateClosedReading - gateFullyOpenReading) * 100;
}

bool distanceSensor::isOpening() {
	enum states {
		INIT,
		READ_FIRST_VAL,
		READ_SECOND_VAL
	};

	static bool isOpeningStatus = false;
	static states state = INIT;
	constexpr unsigned long waitDelay = 300; //300ms
	constexpr unsigned short minTravelDistance = 50; //50mm
	static unsigned short firstReading;
	static unsigned short secondReading;
	static bool firstValueRead;
	intervalTimer waitDelayTimer;

	switch (state)
	{
	case INIT:
		firstValueRead = false;
		state = READ_FIRST_VAL;
		break;

	case READ_FIRST_VAL:
		//read value
		if (!firstValueRead) {
			firstReading = m_readSensor();
			firstValueRead = true;
			waitDelayTimer.start();
		}
		if (waitDelayTimer.timeElapsed(waitDelay))
			state = READ_SECOND_VAL;
		break;

	case READ_SECOND_VAL:
		//check value again after 'waitDelay' millisecs
		secondReading = m_readSensor();
		//if first reading - second reading > 'minTravelDistance' then gate is opening
		if ((firstReading-secondReading) > minTravelDistance)
			isOpeningStatus=true;
		else
			isOpeningStatus=false;
		state = INIT;
		break;
	}

	return isOpeningStatus;
}

bool distanceSensor::isClosing() {
	enum states {
		INIT,
		READ_FIRST_VAL,
		READ_SECOND_VAL
	};

	static bool isClosingStatus = false;
	static states state = INIT;
	constexpr unsigned long waitDelay = 300; //300ms
	constexpr unsigned short minTravelDistance = 50; //50mm
	static unsigned short firstReading;
	static unsigned short secondReading;
	static bool firstValueRead;
	intervalTimer waitDelayTimer;

	switch (state)
	{
	case INIT:
		firstValueRead = false;
		state = READ_FIRST_VAL;
		break;

	case READ_FIRST_VAL:
		//read value
		if (!firstValueRead) {
			firstReading = m_readSensor();
			firstValueRead = true;
			waitDelayTimer.start();
		}
		if (waitDelayTimer.timeElapsed(waitDelay))
			state = READ_SECOND_VAL;
		break;

	case READ_SECOND_VAL:
		//check value again after 'waitDelay' millisecs
		secondReading = m_readSensor();
		//if second reading - first reading > 'minTravelDistance' then gate is opening
		if ((secondReading - firstReading) > minTravelDistance)
			isClosingStatus = true;
		else
			isClosingStatus = false;
		state = INIT;
		break;
	}

	return isClosingStatus;
}

bool distanceSensor::isHalfOpen() {
	if (m_isWithin(m_readSensor(), gateHalfOpenReading, readingTolerance))
		return true;
	else
		return false;

}

bool distanceSensor::isFullyOpen() {
	if (digitalRead(SLIDING_GATE_FULL_OPEN_LS_PIN) == HIGH)
		return true;
	else
		return false;

}

unsigned short distanceSensor::m_readSensor() {

	char buffer[5];

	// flush and wait for a range reading
	slidingGateDistanceSensorSerial.flush();

	//wait for serial to be available and buffer to have contained an 'R'
	while (!(slidingGateDistanceSensorSerial.available() > 0) || slidingGateDistanceSensorSerial.read() != 'R');

	// read the range
	for (int i = 0; i < 4; i++) {
		while (!slidingGateDistanceSensorSerial.available());

		buffer[i] = slidingGateDistanceSensorSerial.read();
	}
	buffer[4] = '\0'; //null terminate string

	return atoi(buffer);
}

//returns true if readvalue is within +/- tolerance of targetvalue
bool distanceSensor::m_isWithin(unsigned short readvalue, unsigned short targetvalue, unsigned short tolerance) {
	if ((readvalue > (targetvalue - tolerance)) && (readvalue < (targetvalue + tolerance)))
		return true;
	else
		return false;
}




