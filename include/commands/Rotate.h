#ifndef __ROTATE_H_INCLUDED__
#define __ROTATE_H_INCLUDED__

#include <ICommand.h>
#include <IRotatingObject.h>
#include <memory>

class Rotate: public ICommand
{
    std::shared_ptr<IRotatingObject> m_Object = nullptr;

public:
    Rotate(std::shared_ptr<IRotatingObject> rotatingObject);

    void Execute() override;
};

#endif