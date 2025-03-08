#pragma once
#include <raylib.h>
#include <iostream>
class Timer
{
public:
	Timer() 
	{
		m_timeLeft = m_totalTime;
		m_currentTimeInProgram = GetTime();
	}
	enum TimerState {PAUSED, NOT_PAUSED, NOT_STARTED};
	void pauseTimer();
	void startTimer();
	void continueTimer();
	void updateCurrentTimeAndTimeLeft();
	TimerState m_currentState = NOT_STARTED;
	float getTimeLeft() { return m_timeLeft; }
	void setTotalTime(float time);
private:
	float m_timeLeft;
	float m_startTime;
	float m_currentTimeInProgram;
	float m_timePaused;
	float m_timeToAdd;

protected:
	float m_totalTime;


};


class ExtendedTimer : public Timer
{
public:
	void extendTimer(float extraTime);


private:


};

