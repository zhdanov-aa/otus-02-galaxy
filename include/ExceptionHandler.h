#ifndef __EXCEPTIONHANDLER_H_INCLUDED__
#define __EXCEPTIONHANDLER_H_INCLUDED__

#include <ICommand.h>
#include <IException.h>
#include <map>
#include <utility>
#include <string>

using namespace std;

typedef ICommandPtr(*Handler)(ICommandPtr, IExceptionPtr);

class ExceptionHandler
{
    static map<pair<string,string>, Handler> Handlers;

public:
    static ICommandPtr Handle(ICommandPtr pCmd, IExceptionPtr pException);

    template<typename CommandType, typename ExceptionType>
    static void Register(Handler handler)
    {
        Handlers[make_pair(typeid(CommandType).name(), typeid(ExceptionType).name())] = handler;
    }
};

#endif