#include "stdafx.h"
#include "GdiplusException.h"


GdiplusException::GdiplusException()
	:std::exception("GDI+ ���̺귯���� �ʱ�ȭ�� �� �����ϴ�.")
{
}


GdiplusException::~GdiplusException()
{
}
