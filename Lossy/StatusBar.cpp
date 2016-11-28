#include "stdafx.h"
#include "StatusBar.h"
#include "DrawManager.h"
#include "Resource.h"


StatusBar::StatusBar()
{
    this->bitmap = DrawManager::Inst()->LoadBitmapFromResource(IDB_STATUSBAR);
}

StatusBar::~StatusBar()
{
    DeleteObject(bitmap);
}

void StatusBar::Update()
{
}

void StatusBar::Draw()
{
    DrawManager::Inst()->DrawBitmap(bitmap, 0, 0, value * 800, 25, 0, 0, 1, 1);
}
