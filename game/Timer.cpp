#include "Timer.hpp"


Timer::Timer()
{
	m_startTime = 0.0f;
	m_totalTime = 0.0f;
	m_timeLeft = 0.0f;
	m_currentState = TimerState::NOT_STARTED;
}

void Timer::updateCurrentTimeAndTimeLeft()
{

	if (m_currentState == TimerState::NOT_STARTED) return;


	if (m_currentState == TimerState::NOT_PAUSED)
	{
		m_currentTimeInProgram = GetTime() - m_startTime;
		m_timeLeft = m_totalTime - m_currentTimeInProgram;
		if (m_timeLeft <= 0)
		{
			m_hasTimerRunOut = true;
		}
	}
}

void Timer::setTotalTime(float time)
{
	m_totalTime = time;
}

void Timer::resetTimer()
{
	//if (m_hasTimerRunOut) // why do i need this?
	//{
		m_startTime = GetTime();
		m_timeLeft = m_totalTime;
		std::cout << m_timeLeft << std::endl;
		m_hasTimerRunOut = false;
	//}
}

void Timer::continueTimerWithoutAddingPausedTime()
{
	m_currentState = TimerState::NOT_PAUSED;
}

void Timer::extendTimer(float timeToAdd)
{
	setTotalTime(m_timeLeft + timeToAdd);
	resetTimer();
}


void Timer::pauseTimer()
{
	m_currentState = TimerState::PAUSED;
	m_timePaused = GetTime();
}

void Timer::startTimer()
{
	if (m_currentState == TimerState::NOT_STARTED) 
	{
		m_startTime = GetTime();
		m_currentState = TimerState::NOT_PAUSED;
	}
}

void Timer::continueTimer()
{
	float pausedDuration = GetTime() - m_timePaused;
	m_totalTime += pausedDuration; // this is causing the bug!! its adding the paused duration on
	m_currentState = TimerState::NOT_PAUSED;
}

void ExtendedTimer::extendTimer(float extraTime)
{
	m_totalTime += extraTime;
}
