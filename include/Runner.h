#ifndef __RUNNER_H_INCLUDED__
#define __RUNNER_H_INCLUDED__

#inclide <ICommandQueue.h>

class Runner
{
    ICommandQueuePtr m_pCommandQueue = nullptr;

public:
    Runner(ICommandQueuePtr CommandQueue);

    void Execute();
};

#endif