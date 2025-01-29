#include <Angle.h>
#include <stdexcept>

Angle::Angle()
{
    //TODO:
}

Angle::Angle(int angle)
{
    //TODO:
}

int operator == (const Angle &a1, const Angle &a2)
{
    //TODO:
    throw std::runtime_error("Angle operator == not implemented");
}

int operator != (const Angle &a1, const Angle &a2)
{
    return !(a1 == a2);
}

Angle operator + (const Angle &a1, const Angle &a2)
{
    //TODO:
    throw std::runtime_error("Angle operator + not implemented");
}
