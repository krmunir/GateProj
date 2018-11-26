// 
// 
// 

#include "gateControl.h"
#include "distanceSensor.h"

distanceSensor slidingGateDistanceSensor;


void gateControl::m_gateButtonPress() {

}

void gateControl::m_changeDirection() {

}

void gateControl::fullOpen() {

}

void gateControl::fullClose() {

}

void gateControl::halfOpen() {

}

void gateControl::stop() {
	if (slidingGateDistanceSensor.isClosing() || slidingGateDistanceSensor.isOpening())
		m_gateButtonPress();//press button to stop only if moving
}