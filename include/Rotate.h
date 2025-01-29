#ifndef __ROTATE_H_INCLUDED__
#define __ROTATE_H_INCLUDED__

#include <IRotatingObject.h>
#include <memory>

class Rotate
{
    std::shared_ptr<IRotatingObject> m_Object = nullptr;

public:
    Rotate(std::shared_ptr<IRotatingObject> rotatingObject);

    void Execute(void);
};

#endif