#ifndef __IEXCEPTIONHANDLER_H_INCLUDED__
#define __IEXCEPTIONHANDLER_H_INCLUDED__

#include <memory>
#include <ICommand.h>
#include <IException.h>

class IExceptionHandler
{
public:
    virtual ~IExceptionHandler() = default;

    virtual ICommandPtr GetCommand(ICommandPtr pCommand, IExceptionPtr pException) = 0;
};

typedef std::shared_ptr<IExceptionHandler> IExceptionHandlerPtr;

#endif