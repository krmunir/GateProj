// 
// 
// 

#include "led.h"

void led::turnOn(Colour col) {
	blinkStateMachine(LEDmode::LED_ON, BlinkRate::NONE, col, Colour::NONE);
}

void led::turnOff() {
	blinkStateMachine(LEDmode::LED_OFF, BlinkRate::NONE, Colour::NONE, Colour::NONE);
}

void led::blink(Colour col, BlinkRate rate) {
	blinkStateMachine(LEDmode::SINGLE_COL_BLINK, rate, col, Colour::NONE);
}

void led::blink(Colour col1, Colour col2, BlinkRate rate) {
	blinkStateMachine(LEDmode::DUAL_COL_BLINK, rate, col1, col2);
}

void led::blinkStateMachine(LEDmode ledMode, BlinkRate blinkRate, Colour col1, Colour col2){

	switch (ledMode)
	{
	case LEDmode::LED_ON:

		break;
	case LEDmode::LED_OFF:

		break;
	case LEDmode::SINGLE_COL_BLINK:

		break;
	case LEDmode::DUAL_COL_BLINK:

		break;
	default:
		break;
	}




}