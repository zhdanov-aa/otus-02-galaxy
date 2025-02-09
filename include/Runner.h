#ifndef __RUNNER_H_INCLUDED__
#define __RUNNER_H_INCLUDED__

#include <ICommandQueue.h>
#include <IExceptionHandler.h>

class Runner
{
    ICommandQueuePtr m_pCommandQueue;
    IExceptionHandlerPtr m_pExceptionHandler;

public:
    Runner(ICommandQueuePtr pCommandQueue, IExceptionHandlerPtr pExceptionHandler);

    void Execute();
};

#endif