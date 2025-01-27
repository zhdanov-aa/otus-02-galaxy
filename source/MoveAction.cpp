#include "../include/MoveAction.h"
#include <exception>

void MoveAction::execute(void)
{
    throw std::runtime_error("MoveAction::execute() is not implemented");
}