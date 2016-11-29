#include "stdafx.h"
#include "Stopwatch.h"


DOUBLE SteamB23::Stopwatch::tickFrequency;
LONGLONG SteamB23::Stopwatch::frequency;
BOOL SteamB23::Stopwatch::isHighResolution;
BOOL SteamB23::Stopwatch::isInitialized;

LONGLONG SteamB23::Stopwatch::Frequency()
{
    if (!isInitialized)
        Initialize();
    return frequency;
}

BOOL SteamB23::Stopwatch::IsHighResolution()
{
    if (!isInitialized)
        Initialize();
    return isHighResolution;
}

void SteamB23::Stopwatch::Initialize()
{
    LARGE_INTEGER fre;
    bool succeeded = QueryPerformanceFrequency(&fre);
    frequency = fre.QuadPart;
    if (succeeded)
    {
        isHighResolution = true;
        tickFrequency = TicksPerSecond / frequency;
    }
    else
    {
        isHighResolution = false;
        frequency = TicksPerSecond;
        tickFrequency = 1;
    }
    isInitialized = true;
}

SteamB23::Stopwatch::Stopwatch()
    : elapsed(0), startTimeStamp(0),isRunning(false)
{
}

void SteamB23::Stopwatch::Start()
{
    if (!isRunning)
    {
        startTimeStamp = GetTimeStamp();
        isRunning = true;
    }
}

void SteamB23::Stopwatch::Stop()
{
    if (isRunning)
    {
        LONGLONG endTimeStamp = GetTimeStamp();
        LONGLONG elapsedThisPeriod = endTimeStamp - startTimeStamp;
        elapsed += elapsedThisPeriod;
        isRunning = false;
        if (elapsed < 0)
            elapsed = 0;
    }
}

void SteamB23::Stopwatch::Reset()
{
    elapsed = 0;
    isRunning = false;
    startTimeStamp = 0;
}

void SteamB23::Stopwatch::Restart()
{
    elapsed = 0;
    startTimeStamp = GetTimeStamp();
    isRunning = true;
}

double SteamB23::Stopwatch::GetElapsedTotalSeconds()
{
    return GetElapsedDataTimeTicks() / (double)TicksPerSecond;
}

double SteamB23::Stopwatch::GetElapsedTotalMiliseconds()
{
    return GetElapsedDataTimeTicks() / (double)TicksPerMillisecond;
}

LONGLONG SteamB23::Stopwatch::GetElapsedMiliseconds()
{
    return GetElapsedDataTimeTicks() / TicksPerMillisecond;
}

LONGLONG SteamB23::Stopwatch::GetElapsedTicks()
{
    LONGLONG timeElapsed = elapsed;

    if (isRunning)
    {
        LONGLONG currentTimeStamp = GetTimeStamp();
        LONGLONG elapsedUntilNow = currentTimeStamp - startTimeStamp;
        timeElapsed += elapsedUntilNow;
    }
    return timeElapsed;
}

LONGLONG SteamB23::Stopwatch::GetTimeStamp()
{
    if (IsHighResolution())
    {
        LARGE_INTEGER timestamp;
        timestamp.QuadPart = 0;
        QueryPerformanceCounter(&timestamp);
        return timestamp.QuadPart;
    }
    else
    {
        LONGLONG tick = 0;
        FILETIME fileTime;
        GetSystemTimeAsFileTime(&fileTime);
        tick |= fileTime.dwHighDateTime;
        tick <<= 32;
        tick |= fileTime.dwLowDateTime;
        tick += 584388 * 864000000000;
        return tick;
    }
}

LONGLONG SteamB23::Stopwatch::GetElapsedDataTimeTicks()
{
    LONGLONG rawTicks = GetElapsedTicks();
    if (IsHighResolution())
    {
        double dticks = rawTicks;
        dticks *= tickFrequency;
        return dticks;
    }
    else
    {
        return rawTicks;
    }
}
