#ifndef __MOVE_H_INCLUDED__
#define __MOVE_H_INCLUDED__

#include <ICommand.h>
#include <IMovingObject.h>
#include <memory>

class Move: public ICommand
{
    std::shared_ptr<IMovingObject> m_Object = nullptr;

public:
    Move(std::shared_ptr<IMovingObject> moveObject);

    void Execute() override;
};

#endif