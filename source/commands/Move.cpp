#include <Move.h>
#include <stdexcept>

Move::Move(std::shared_ptr<IMovingObject> moveObject)
{
    m_Object = moveObject;
}


void Move::Execute()
{
    if (m_Object != nullptr)
    {
        m_Object->setLocation( m_Object->getLocation() + m_Object->getVelocity() );
    }
    else 
    {
        throw std::runtime_error("Move::m_Object is nullptr");
    }
}