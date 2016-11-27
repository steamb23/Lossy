#include "stdafx.h"
#include "Sprite.h"


Sprite::Sprite(HBITMAP bitmap, std::vector<RECT> sourceRect)
{
	this->bitmap = bitmap;
	this->sourceRect = sourceRect;
}

Sprite::~Sprite()
{
}

void Sprite::Draw(int x, int y, int sourceRectIndex)
{
	this->Draw(x, y, sourceRect[sourceRectIndex]);
}

void Sprite::Draw(int x, int y, RECT sourceRect)
{
	this->Draw(x, y, sourceRect.right, sourceRect.bottom, sourceRect);
}

void Sprite::Draw(int x, int y, int width, int height, int sourceRectIndex)
{
	this->Draw(x, y, width, height, sourceRect[sourceRectIndex]);
}

void Sprite::Draw(int x, int y, int width, int height, RECT sourceRect)
{
	this->Draw(x, y, width, height, sourceRect.left, sourceRect.top, sourceRect.right, sourceRect.bottom);
}

void Sprite::Draw(int dest_x, int dest_y, int dest_width, int dest_height, int source_x, int source_y, int source_width, int source_height)
{
	DrawManager::Inst()->DrawBitmap(bitmap, dest_x, dest_y, dest_width, dest_height, source_x, source_y, source_width, source_height);
}
