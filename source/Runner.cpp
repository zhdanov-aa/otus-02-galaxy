#include <Runner.h>
#include <ICommand.h>
#include <IException.h>

void Runner::Execute()
{
    if (m_pCommandQueue != nullptr)
    {
        while (!m_pCommandQueue->IsEmpty())
        {
            ICommandPtr pCmd = m_pCommandQueue.GetHead();
            if (pCmd != nullptr)
            {
                try
                {
                    pCmd->Execute();
                }
                catch(IException *e)
                {
                    ExceptioHandler::Handle(pCmd, IExpertionPtr(e))->Execute();
                }
            }
        }
    }
}