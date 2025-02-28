#include <Vector2D.h>

Vector2D::Vector2D()
{
}

Vector2D::Vector2D(int x, int y)
    : m_x(x), m_y(y)
{
}

int operator == (const Vector2D &v1, const Vector2D &v2)
{
    return (v1.m_x == v2.m_x) && (v1.m_y == v2.m_y);
}

int operator != (const Vector2D &v1, const Vector2D &v2)
{
    return !(v1 == v2);
}

Vector2D operator + (const Vector2D &v1, const Vector2D &v2)
{
    return Vector2D(v1.m_x + v2.m_x, v1.m_y + v2.m_y);
}