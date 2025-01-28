#include <Move.h>
#include <exception>

Move::Move(std::shared_ptr<IMoveObject> moveObject)
{
    m_Object = moveObject;
}


void Move::Execute(void)
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