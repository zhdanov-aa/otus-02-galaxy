#ifndef __VECTOR2D_H_INCLUDED__
#define __VECTOR2D_H_INCLUDED__

class Vector2D
{
    int m_x = 0;
    int m_y = 0;
public:
    Vector2D();
    Vector2D(int x, int y);

    friend int operator == (const Vector2D &v1, const Vector2D &v2);
    friend int operator != (const Vector2D &v1, const Vector2D &v2);

    friend Vector2D operator + (const Vector2D &v1, const Vector2D &v2);
};

#endif