#include <Angle.h>
#include <stdexcept>

Angle::Angle()
{
}

Angle::Angle(int angle)
{
    m_angle = angle % 360;
}

int operator == (const Angle &a1, const Angle &a2)
{
    return ( ((a1.angle + 360) % 360) == ((a2.angle + 360) % 360) );
}

int operator != (const Angle &a1, const Angle &a2)
{
    return !(a1 == a2);
}

Angle operator + (const Angle &a1, const Angle &a2)
{
    return Angle(a1.m_angle + a2.m_angle);
}
