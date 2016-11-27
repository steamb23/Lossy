#pragma once
#include <memory>
#include "Stopwatch.h"
class GameTime
{
private:
	SteamB23::Stopwatch frameRateTimer;
	SteamB23::Stopwatch totalTimer;
	DOUBLE deltaTime;
	DOUBLE totalTime;

	ULONGLONG totalFrameCount;
	DOUBLE deltaRatio;
public:
	GameTime();

	DOUBLE FPS()
	{
		return 1 / DeltaTimeD();
	}
	DOUBLE DeltaTimeD()
	{
		return deltaTime;
	}
	DOUBLE DeltaRatioD()
	{
		return deltaRatio;
	}
	FLOAT DeltaTime()
	{
		return (float)DeltaTimeD();
	}
	FLOAT DeltaRatio()
	{
		return (float)DeltaRatioD();
	}
	DOUBLE GetTotalTime()
	{
		totalTimer.GetElapsedTotalSeconds();
	}
	void Start();
	void Stop();

	void Update();
};