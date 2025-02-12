#ifndef __CHECKFUEL_H_INCLUDED__
#define __CHECKFUEL_H_INCLUDED__

#include <ICommand.h>
#include <IFuelObject.h>
#include <memory>

class CheckFuel: public ICommand
{
    IFuelObjectPtr m_pFuelObject;

public:
    CheckFuel(IFuelObjectPtr pFuelObject);

    void Execute() override;
};

typedef std::shared_ptr<CheckFuel> CheckFuelPtr;

#endif