#include "Timer.hpp"

void Timer::updateCurrentTimeAndTimeLeft()
{
	if (m_currentState == TimerState::NOT_PAUSED)
	{
		m_timeLeft = m_totalTime - m_currentTimeInProgram;
		std::cout << "Time remaining: " << m_timeLeft << std::endl;
	}
	m_currentTimeInProgram = GetTime();
}

void Timer::setTotalTime(float time)
{
	m_totalTime = time;
	m_timeLeft = time;
}

void Timer::pauseTimer()
{
	m_currentState = TimerState::PAUSED;
	m_timePaused = GetTime();
}

void Timer::startTimer()
{
	m_startTime = GetTime();
	m_currentState = TimerState::NOT_PAUSED;
}

void Timer::continueTimer()
{
	float pausedDuration = GetTime() - m_timePaused;
	m_totalTime += pausedDuration;
	m_currentState = TimerState::NOT_PAUSED;

}

void ExtendedTimer::extendTimer(float extraTime)
{
	m_totalTime += extraTime;
}
