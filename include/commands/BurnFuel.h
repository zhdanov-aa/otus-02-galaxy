#ifndef __BURNFUEL_H_INCLUDED__
#define __BURNFUEL_H_INCLUDED__

#include <ICommand.h>
#include <IFuelObject.h>

class BurnFuel: ICommand
{
public:
    BurnFuel(IFuelObjectPtr, FuelLevel burnValue);

    void Execute() override;
};

#endif
