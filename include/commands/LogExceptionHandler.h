#ifndef __LOGEXCEPTIONHANDLER_H_INCLUDED__
#define __LOGEXCEPTIONHANDLER_H_INCLUDED__

#include <ICommand.h>
#include <ICommandQueueBuilder.h>
#include <IException.h>
#include <ILog.h>
#include <memory>

class LogExceptionHandler: public ICommand
{
    ICommandQueueBuilderPtr m_pBuilder;
    IExceptionPtr m_pException;
    ILogPtr m_pLog;
public:
    LogExceptionHandler(ILogPtr log, IExceptionPtr exception, ICommandQueueBuilderPtr builder);

    void Execute() override;
};

typedef std::shared_ptr<LogExceptionHandler> LogExceptionHandlerPtr;

#endif