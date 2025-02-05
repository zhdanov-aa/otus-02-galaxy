#include <Runner.h>
#include <IException.h>
#include <ExceptionHandler.h>

void Runner::Execute()
{
    if (m_pCommandQueue == nullptr)
        return;

    ICommandPtr pCmd = nullptr;
    while (pCmd = m_pCommandQueue->GetCommand())
    {
        try
        {
            pCmd->Execute();
        }
        catch(IException *e)
        {
            ICommandPtr handler = ExceptionHandler::Handle(pCmd, IExceptionPtr(e));
            if (handler != nullptr) 
            {
                handler->Execute();
            }
        }
    }
}