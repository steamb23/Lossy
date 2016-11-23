#include "stdafx.h"
#include "HDCManager.h"

HDCManager* HDCManager::instance;

HDCManager::HDCManager()
{
	cornflowerBlue = RGB(100, 149, 237);
	magenta = RGB(255, 0, 255);
	bgBrush = CreateSolidBrush(cornflowerBlue);
}


HDCManager::~HDCManager()
{
}

HDCManager* HDCManager::Inst()
{
	if (instance == nullptr)
		instance = new HDCManager();
	return instance;
}
