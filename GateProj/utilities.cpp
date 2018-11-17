#include "utilities.h"

timer::timer() : m_startTime{ 0 } {
}


void timer::start() {
	m_startTime = millis();
}

//max delay settable = 2^32 milliseconds = 49 days
bool timer::timeElapsed(unsigned long delay) {
	if ((millis() - m_startTime) > delay)
		return true;
	else
		return false;
}

void timer::restart() {
	m_startTime = millis();
}
