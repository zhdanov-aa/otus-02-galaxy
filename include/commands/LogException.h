#ifndef __LOGEXCEPTION_H_INCLUDED__
#define __LOGEXCEPTION_H_INCLUDED__

#include <ICommand.h>
#include <IException.h>
#include <ILog.h>
#include <memory>

class LogException: public ICommand
{
    IExceptionPtr m_pException;
    ILogPtr m_pLog;

public:
    LogException(ILogPtr pLog, IExceptionPtr pException);

    void Execute() override;
};

typedef std::shared_ptr<LogException> LogExceptionPtr;

#endif