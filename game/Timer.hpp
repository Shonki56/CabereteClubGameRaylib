#pragma once
#include <raylib.h>
class Timer
{
public:
	Timer(float howLongTimer, float startTime = GetTime()) 
		: m_howLongUntilStop(howLongTimer),
		  m_startTime(startTime)
	{
	}
	const float m_startTime;
	float m_howLongUntilStop;
	float m_currentTimeInProgram;
	float m_timeLeft;
	void setTimeLeft();
private:
	void updateCurrentTime();

};


class ExtendedTimer : public Timer
{
public:
	void extendTimer(float extraTime);


private:


};

