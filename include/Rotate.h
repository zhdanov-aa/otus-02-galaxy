#include <memory>


class Rotate
{
    std::shared_ptr<IRotatingObject> m_Object = nullptr;

public:
    Rotate(std::shared_ptr<IRotatingObject> rotatingObject);

    void Execute(void);
};