#include <CheckFuel.h>
#include <InvalidArgument.h>
#include <NotEnoughFuel.h>

CheckFuel::CheckFuel(IFuelObjectPtr pFuelObject)
    :m_pFuelObject(pFuelObject)
{
}

void CheckFuel::Execute()
{
    if (m_pFuelObject == nullptr)
        throw new InvalidArgument("m_pFuelObject is nullptr");

    if (m_pFuelObject->getLevel() < m_pFuelObject->getConsumption())
        throw new NotEnoughFuel();
}