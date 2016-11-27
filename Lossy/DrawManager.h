#pragma once
class DrawManager
{
    DrawManager();
    ~DrawManager();

    static DrawManager* instance;
    COLORREF cornflowerBlue;
    COLORREF magenta;
    HBRUSH bgBrush;

    HDC hdc, memDC;
public:
    static DrawManager* Inst();

    HBITMAP LoadBitmapFromResource(HINSTANCE hInst, int i)
    {
        return LoadBitmap(hInst, MAKEINTRESOURCE(i));
    }

    void SetDC(HDC hdc, HDC memDC)
    {
        this->hdc = hdc;
        this->memDC = memDC;
    }

    HDC GetDC()
    {
        return this->hdc;
    }
    HDC GetMemDC()
    {
        return this->memDC;
    }

    void ScreenClear()
    {
        auto temp = SelectObject(hdc, bgBrush);
        Rectangle(hdc, -1, -1, 801, 601);
        SelectObject(hdc, temp);
    }

    void DrawLine(int x1, int y1, int x2, int y2)
    {
        MoveToEx(hdc, x1, y1, 0);
        LineTo(hdc, x2, y2);
    }
    void DrawBitmap(HBITMAP bitmap, int dest_x, int dest_y, int dest_width, int dest_height, int source_x, int source_y, int source_width, int source_height)
    {
        auto temp = SelectObject(memDC, bitmap);
        TransparentBlt(hdc, dest_x, dest_y, dest_width, dest_height, memDC, source_x, source_y, source_width, source_height, magenta);
        SelectObject(memDC, temp);
    }

};

