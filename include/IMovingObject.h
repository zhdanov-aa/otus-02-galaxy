class IMovingObject
{
public:
    virtual Location getLocation(void) = 0;
    virtual Velocity getVelocity(void) = 0;
    virtual void setLocation(Location newLocation) = 0;
};