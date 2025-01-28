#include "IMoveObject.h"
#include <memory>

class Move
{
    std::shared_ptr<IMovingObject> m_Object = nullptr;

public:
    Move(std::shared_ptr<IMovingObject> moveObject);

    void Execute(void);
};