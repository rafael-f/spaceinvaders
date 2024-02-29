#include "Clock.h"

Clock::Clock()
{
    m_Milliseconds = getCurrentTimeMilliseconds();
}

Time Clock::getElapsedTime() const
{
    long long elapsedTime = getCurrentTimeMilliseconds() - m_Milliseconds;

    return Time(static_cast<float>(elapsedTime));
}

Time Clock::restart()
{
    Time elapsed = getElapsedTime();

    m_Milliseconds = getCurrentTimeMilliseconds();

    return elapsed;
}

long long Clock::getCurrentTimeMilliseconds() const
{
    auto currentTimePoint = std::chrono::system_clock::now();
    auto microseconds = std::chrono::time_point_cast<std::chrono::milliseconds>(currentTimePoint);
    return microseconds.time_since_epoch().count();
}
