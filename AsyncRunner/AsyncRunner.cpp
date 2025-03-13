#include <AsyncRunner.h>
#include <ICommand.h>
#include <IException.h>
#include <IoC.h>

void AsyncRunner::ThreadFunction()
{
    m_onStartAction();

    while (m_checkContinueAction())
    {
        ICommandPtr pCmd = m_CommandQueue->Pop();

        try {
            pCmd->Execute();
        }
        catch(IException *e)
        {
            auto handler = IoC::Resolve<ICommandPtr>("Exception.Handler.Get", pCmd, IExceptionPtr(e));
            if (handler != nullptr)
            {
                handler->Execute();
            }
        }
    }

    m_onStopAction();
}

AsyncRunner::AsyncRunner(BlockingQueuePtr commandQueue)
    :m_CommandQueue(commandQueue)
{
    m_onStartAction = [](){};
    m_onStopAction = [](){};
    m_checkContinueAction = [](){ return true; };
}

void AsyncRunner::Start()
{
    if(m_currentThread == nullptr)
    {
        m_currentThread = std::make_shared<std::thread>(
            [this](){
                ThreadFunction();
            }
            );
    }
}
