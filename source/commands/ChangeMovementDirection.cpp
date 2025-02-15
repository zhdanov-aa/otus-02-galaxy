#include <ChangeMovementDirection.h>
#include <InvalidArgument.h>
#include <UnavailableAction.h>

ChangeMovementDirection::ChangeMovementDirection(IMovementDirectionObjectPtr pObject)
    : m_pObject(pObject)
{
}

void ChangeMovementDirection::Execute()
{
    if (m_pObject == nullptr)
        throw new InvalidArgument("ChangeMovementDirection::m_pObject is nullptr");

    try
    {
        m_pObject->setDirection( m_pObject->getDirection() + m_pObject->getInstantChange() );
    }
    catch (UnavailableAction *pException)
    {
        delete pException;
    }
}