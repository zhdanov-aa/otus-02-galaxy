#ifndef ASYNCRUNNER_H
#define ASYNCRUNNER_H

#include <BlockingQueue.h>
#include <functional>
#include <memory>
#include <thread>

class AsyncRunner
{
    BlockingQueuePtr m_CommandQueue;

    std::function<void()> m_onStartAction;
    std::function<void()> m_onStopAction;
    std::function<bool()> m_checkContinueAction;

    std::shared_ptr<std::thread> m_currentThread;

    void ThreadFunction();

public:
    AsyncRunner(BlockingQueuePtr commandQueue);

    void Start();
};

#endif // ASYNCRUNNER_H
