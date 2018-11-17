#pragma once

//non blocking timer class
class intervalTimer
{
private:
	unsigned long m_startTime;
public:
	void start();
	bool timeElapsed(unsigned long delay);//max delay settable = 2^32 milliseconds = 49 days
	void restart();
	intervalTimer();
	//~timer();
};

