#ifndef __EXCEPTIONHANDLER_H_INCLUDED__
#define __EXCEPTIONHANDLER_H_INCLUDED__

#include <ICommand.h>
#include <IException.h>

typedef ICommandPtr(*Handler)(ICommandPtr, IExceptionPtr);

class ExceptionHandler
{
public:
    static ICommandPtr Handle(ICommandPtr pCmd, IExceptionPtr pException);

    template<typename CommandType, typename ExceptionType>
    static void Register(Handler handler)
    {
        //TODO:
    }
};

#endif