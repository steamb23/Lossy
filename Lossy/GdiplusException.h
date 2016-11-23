#pragma once
#include <exception>
class GdiplusException :
	public std::exception
{
public:
	GdiplusException();
	virtual ~GdiplusException();
};

