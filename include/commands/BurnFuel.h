#ifndef __BURNFUEL_H_INCLUDED__
#define __BURNFUEL_H_INCLUDED__

#include <ICommand.h>
#include <IFuelObject.h>
#include <memory>

class BurnFuel: public ICommand
{
    IFuelObjectPtr m_pFuelObject;

public:
    BurnFuel(IFuelObjectPtr fuelObject);

    void Execute() override;
};

typedef std::shared_ptr<BurnFuel> BurnFuelPtr;

#endif
