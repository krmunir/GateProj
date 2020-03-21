#include "utilities.h"
#include "Arduino.h"

intervalTimer::intervalTimer() : m_startTime{ 0 } {
}


void intervalTimer::start() {
	m_startTime = millis();
}

//max delay settable = 2^32 milliseconds = 49 days
bool intervalTimer::timeHasElapsed(unsigned long delay) {
	if ((millis() - m_startTime) > delay)
		return true;
	else
		return false;
}

void intervalTimer::restart() {
	m_startTime = millis();
}
