#include <Rotate.h>
#include <stdexcept>

Rotate::Rotate(std::shared_ptr<IRotatingObject> rotatingObject)
{
    m_Object = rotatingObject;
}


void Rotate::Execute()
{
    if (m_Object != nullptr)
    {
        m_Object->setAngle( m_Object->getAngle() + m_Object->getRotationSpeed() );
    }
    else
    {
        throw std::runtime_error("Rotate::m_Object is nullptr");
    }
}