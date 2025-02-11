#ifndef __IFUELOBJECT_H_INCLUDED__
#define __IFUELOBJECT_H_INCLUDED__

#include <FuelLevel.h>
#include <memory>

class IFuelObject
{
public:
    virtual ~IFuelObject() = default;

    virtual FuelLevel getLevel() = 0;
    virtual void setLevel(FuelLevel newLevel) = 0;

    virtual FuelLevel getConsumption() = 0;
};

typedef std::shared_ptr<IFuelObject> IFuelObjectPtr;

#endif