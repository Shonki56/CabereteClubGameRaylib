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
	const float m_howLongUntilStop;
	float m_currentTimeInProgram;
	float m_timeLeft;
	void setTimeLeft();
private:
	void updateCurrentTime();

};

