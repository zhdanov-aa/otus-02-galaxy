#include <Runner.h>
#include <ICommand.h>
#include <IException.h>

void Runner::Execute()
{
    if (m_pCommandQueue == nullptr)
        return;

    ICommandPtr pCmd = nullptr;
    while (pCmd = m_pCommandQueue->GetHead())
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