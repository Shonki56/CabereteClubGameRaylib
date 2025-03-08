#include "Timer.hpp"

void Timer::updateCurrentTime()
{
	m_currentTimeInProgram = GetTime();
}

void Timer::setTimeLeft()
{
	updateCurrentTime();
	m_timeLeft = m_howLongUntilStop - m_currentTimeInProgram;
}

void ExtendedTimer::extendTimer(float extraTime)
{
	m_howLongUntilStop += extraTime;
}
