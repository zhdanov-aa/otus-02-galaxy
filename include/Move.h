#include "IMoveObject.h"
#include <memory>

class Move
{
    std::shared_ptr<IMoveObject> m_Object;

public:
    Move(std::shared_ptr<IMoveObject> moveObject);

    void Execute(void);
};