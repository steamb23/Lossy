#pragma once
#include "GameObject.h"
class StatusBar
{
    float value;
    HBITMAP bitmap;
public:
    StatusBar();
    virtual ~StatusBar();

    float GetValue() { return value; };
    void SetValue(float value) { this->value = value; };

    virtual void Update();
    virtual void Draw();
};

