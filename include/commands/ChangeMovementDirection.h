#ifndef __CHANGEMOVEMENTDIRECTION_H_INCLUDED__
#define __CHANGEMOVEMENTDIRECTION_H_INCLUDED__

#include <ICommand.h>
#include <memory>
#include <IMovementDirectionObject.h>

class ChangeMovementDirection: public ICommand
{
    IMovementDirectionObjectPtr m_pObject;

public:
    ChangeMovementDirection(IMovementDirectionObjectPtr pObject);

    void Execute() override;
};

typedef std:shared_ptr<ChangeMovementDirection> ChangeMovementDirectionPtr;

#endif