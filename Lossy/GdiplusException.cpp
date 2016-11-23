#include "stdafx.h"
#include "GdiplusException.h"


GdiplusException::GdiplusException()
	:std::exception("GDI+ 라이브러리를 초기화할 수 없습니다.")
{
}


GdiplusException::~GdiplusException()
{
}
