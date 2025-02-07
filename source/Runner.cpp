#include <Runner.h>
#include <IException.h>
#include <ExceptionHandler.h>

Runner::Runner(ICommandQueuePtr pCommandQueue, IExceptionHandler pExceptionHandler)
    : m_pCommandQueue(pCommandQueue), m_pExceptionHandler(pExceptionHandler)

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
            ICommandPtr handler = m_pExceptionHandler->GetCommand(pCmd, IExceptionPtr(e));
            if (handler != nullptr) 
            {
                handler->Execute();
            }
        }
    }
}