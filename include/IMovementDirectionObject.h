#ifndef __IMOVEMENTDIRECTIONOBJECT_H_INCLUDED__
#define __IMOVEMENTDIRECTIONOBJECT_H_INCLUDED__

#include <memory>
#include <Angle.h>

class IMovementDirectionObject
{
public:
    virtual ~IMovementDirectionObject() = default;

    /*!
    @return Возвращает текущее направление движения. Если объект в данный момент 
            не двигается (не имеет направления движения), то генерируется 
            исключение UnavailableAction.
    */
    virtual Angle getDirection() = 0;
    
    /*!
    @param [in] newDirection Значение нового направления движения.
    @return Возвращаемое значение отсутсвует. Если объект в данный момент не двигается
            (имеет нулевое значение скорости или по каким-то причинам не может поменять
            направление), то генерируется исключение UnavailableAction.
    */
    virtual void setDirection(Angle newDirection) = 0;

    /*! 
    @return Возвращает значение мгновенного изменения направления движения объекта. 
            Если объект не меняет направления движения, то возвращается значение 0.
    */
    virtual Angle getInstantChange() = 0;
};

typedef std::shared_ptr<IMovementDirectionObject> IMovementDirectionObjectPtr;

#endif