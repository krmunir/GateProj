// 
// 
// 

#include "distanceSensor.h"
#include <SoftwareSerial.h>

//need to access these constants defined in GateProj.ino
extern const uint8_t slidingGateDistanceSensor_RX;
extern const uint8_t slidingGateDistanceSensor_TX;

extern SoftwareSerial slidingGateDistanceSensorSerial(slidingGateDistanceSensor_RX, slidingGateDistanceSensor_TX,true); //sig from sensor is inverted


bool distanceSensor::isOpen() {

}

bool distanceSensor::isClosed() {

}

int distanceSensor::percent_open() {

}

bool distanceSensor::isOpening() {

}

bool distanceSensor::isClosing() {

}

bool distanceSensor::isHalfOpen() {
	
}

unsigned short distanceSensor::m_readSensor() {


	char buffer[6];
	int bytesAvailToRead{ 0 };
	char charRead;

	// flush and wait for a range reading
	slidingGateDistanceSensorSerial.flush();

	/*while (!slidingGateDistanceSensorSerial.available() || slidingGateDistanceSensorSerial.read() != 'R');*/
	
		do
	{
		bytesAvailToRead = slidingGateDistanceSensorSerial.available();
		Serial.print("no of bytes avail to read : ");
		Serial.println(bytesAvailToRead);

		charRead = slidingGateDistanceSensorSerial.read();
		Serial.print("char read : ");
		Serial.println(charRead);

		yield();//poll background tasks and reset watchdog, prevents soft WDT reset errors
	} while (true);

	// read the range
	for (int i = 0; i < 6; i++) {
		while (!slidingGateDistanceSensorSerial.available());

		buffer[i] = slidingGateDistanceSensorSerial.read();
	}

	return atoi(buffer);
	
	//static unsigned int testVal{ 0 };
	//return testVal++;

}