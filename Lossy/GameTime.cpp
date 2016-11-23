#include "stdafx.h"
#include "GameTime.h"


GameTime::GameTime()
	: frameRateTimer(), totalTimer(),deltaTime(0),totalTime(0),totalFrameCount(0),deltaRatio(0)
{
	
}

void GameTime::Start()
{
	frameRateTimer.Start();
	totalTimer.Start();
}
void GameTime::Stop()
{
	frameRateTimer.Stop();
	totalTimer.Stop();
}

void GameTime::Update()
{
	deltaTime = frameRateTimer.GetElapsedTotalSeconds();
	frameRateTimer.Restart();

	totalTime = totalTimer.GetElapsedTotalSeconds();
	totalFrameCount++;

	deltaRatio = DeltaTimeD() * 30;
}
