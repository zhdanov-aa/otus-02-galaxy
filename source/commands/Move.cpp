#include <Move.h>
#include <stdexcept>

Move::Move(std::shared_ptr<IMovingObject> moveObject)
{
    m_Object = moveObject;
}


void Move::Execute()
{
    if (m_Object == nullptr)
        throw new InvalidArgument("Move::m_Object is nullptr");

    m_Object->setLocation( m_Object->getLocation() + m_Object->getVelocity() );
}