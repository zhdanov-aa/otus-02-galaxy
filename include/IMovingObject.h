#include <Vector2D.h>

class IMovingObject
{
public:
    virtual ~IMovingObject() = default;

    virtual Vector2D getLocation(void) = 0;
    virtual Vector2D getVelocity(void) = 0;
    virtual void setLocation(Vector2D newLocation) = 0;
};