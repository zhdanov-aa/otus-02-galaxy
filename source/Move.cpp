#include "../include/Move.h"
#include <exception>

Move::Move(std::shared_ptr<IMoveObject> moveObject)
{
    m_Object = moveObject;
}


void Move::Execute(void)
{
    throw std::runtime_error("MoveAction::execute() is not implemented");
}