#ifndef __IROTATINGOBJECT_H_INCLUDED__
#define __IROTATINGOBJECT_H_INCLUDED__

#include <Angle.h>

class IRotatingObject
{
public:
    virtual ~IRotatingObject() = default;

    virtual Angle getAngle(void) = 0;
    virtual void setAngle(Angle newAngle) = 0;

    virtual Angle getRotationSpeed(void) = 0;
};

#endif