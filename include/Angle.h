#ifndef __ANGLE_H_INCLUDED__
#define __ANGLE_H_INCLUDED__

class Angle
{
public:
    Angle();
    Angle(int angle);

    friend int operator == (const Angle &a1, const Angle &a2);
    friend int operator != (const Angle &a1, const Angle &a2);

    friend Angle operator + (const Angle &a1, const Angle &a2);
};

#endif