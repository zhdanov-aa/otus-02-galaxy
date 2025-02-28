#include <BurnFuel.h>
#include <InvalidArgument.h>

BurnFuel::BurnFuel(IFuelObjectPtr fuelObject) 
    :m_pFuelObject(fuelObject)
{
}

void BurnFuel::Execute()
{
    if (m_pFuelObject == nullptr)
        throw new InvalidArgument("BurnFuel::m_pFuelObject is nullptr");

    m_pFuelObject->setLevel(
        m_pFuelObject->getLevel() - m_pFuelObject->getConsumption());
}