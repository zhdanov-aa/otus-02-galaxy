#include <Rotate.h>
#include <exception>

Rotate::Rotate(std::shared_ptr<IRotatingObject> rotatingObject)
{
    m_Object = rotatingObject;
}


void Rotate::Execute(void)
{
    if (m_Object != nullptr)
    {
        // TODO:
    }
    else
    {
        throw std::runtime_error("Rotate::m_Object is nullptr");
    }
}