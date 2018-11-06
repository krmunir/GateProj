// led.h

#ifndef _LED_h
#define _LED_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

enum class LEDmode {
	LED_ON,
	LED_OFF,
	SINGLE_COL_BLINK,
	DUAL_COL_BLINK
};

enum class Colour {
	NONE,
	RED,
	GREEN,
	BLUE
};

enum class BlinkRate {
	FAST,
	SLOW,
	NONE
};

class led {
private:
	int m_redPin = 0;
	int m_greenPin = 0;
	int m_bluePin = 0;
	void blinkStateMachine(LEDmode ledMode, BlinkRate blinkRate, Colour col1, Colour col2);

public:
	led(int redPin, int greenPin, int bluePin) :m_redPin{ redPin }, m_greenPin{ greenPin }, m_bluePin{ bluePin }
	{
		//setup RGB pins as output
		pinMode(m_redPin, OUTPUT);
		pinMode(m_greenPin, OUTPUT);
		pinMode(m_bluePin, OUTPUT);
	}

	void turnOn(Colour col);
	void turnOff();
	void blink(Colour col, BlinkRate rate);
	void blink(Colour col1, Colour col2, BlinkRate rate);



};




#endif

