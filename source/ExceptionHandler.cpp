#include <ExceptionHandler.h>

map<pair<string,string>, Handler> ExceptionHandler::Handlers;

ICommandPtr ExceptionHandler::Handle(ICommandPtr pCmd, IExceptionPtr pException)
{
    Handler handler = Handlers[make_pair(typeid(*pCmd).name(), typeid(*pException).name())];
    if (handler != nullptr)
    {
        return handler(pCmd, pException);
    }

    return nullptr;
}
