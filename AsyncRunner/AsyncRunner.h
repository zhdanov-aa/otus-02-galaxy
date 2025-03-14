#ifndef ASYNCRUNNER_H
#define ASYNCRUNNER_H

#include <BlockingQueue.h>
#include <functional>
#include <memory>
#include <thread>

class AsyncRunner: public std::enable_shared_from_this<AsyncRunner>
{
    BlockingQueuePtr m_CommandQueue;

    std::function<void()> m_onStartAction;
    std::function<void()> m_onStopAction;
    std::function<bool()> m_checkContinueAction;

    std::shared_ptr<std::thread> m_currentThread;

    void ThreadFunction();

public:
    AsyncRunner(BlockingQueuePtr commandQueue);
    ~AsyncRunner();

    BlockingQueuePtr getQueue();

    void setStartAction(std::function<void()> action);
    void setStopAction(std::function<void()> action);
    void setCheckContinueAction(std::function<bool()> action);

    void Start();
    void Stop();
};

using AsyncRunnerPtr = std::shared_ptr<AsyncRunner>;

#endif // ASYNCRUNNER_H
