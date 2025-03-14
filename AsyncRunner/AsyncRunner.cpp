#include <AsyncRunner.h>
#include <ICommand.h>
#include <IException.h>
#include <IoC.h>
#include <HardStopCommand.h>

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

AsyncRunner::~AsyncRunner()
{
    Stop();
}

BlockingQueuePtr AsyncRunner::getQueue()
{
    return m_CommandQueue;
}

void AsyncRunner::setStartAction(std::function<void ()> action)
{
    m_onStartAction = action;
}

void AsyncRunner::setStopAction(std::function<void ()> action)
{
    m_onStopAction = action;
}

void AsyncRunner::setCheckContinueAction(std::function<bool ()> action)
{
    m_checkContinueAction = action;
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

void AsyncRunner::Stop()
{
    if (m_currentThread != nullptr)
    {
        m_CommandQueue->Push(std::make_shared<HardStopCommand>(shared_from_this()));
        m_currentThread->join();
        m_currentThread = nullptr;
    }
}
