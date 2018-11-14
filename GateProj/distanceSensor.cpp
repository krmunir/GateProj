// 
// 
// 

#include "distanceSensor.h"
#include <SoftwareSerial.h>

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
extern SoftwareSerial slidingGateDistanceSensorSerial(slidingGateDistanceSensor_RX, slidingGateDistanceSensor_TX,true); //sig from sensor is inverted


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

}

bool distanceSensor::isOpening() {

}

bool distanceSensor::isClosing() {

}

bool distanceSensor::isHalfOpen() {
	if(m_isWithin(m_readSensor(),gateHalfOpenReading,readingTolerance))
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
	while (!(slidingGateDistanceSensorSerial.available()>0) || slidingGateDistanceSensorSerial.read() != 'R');
	
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