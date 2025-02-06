#ifndef __WRITEEXCEPTIONTOLOG_H_INCLUDED__
#define __WRITEEXCEPTIONTOLOG_H_INCLUDED__

#include <ICommand.h>
#include <IException.h>
#include <ILog.h>

class WriteExceptionToLog: public ICommand
{
    IExceptionPtr m_pException;
    ILogPtr m_pLog;

public:
    WriteExceptionToLog(ILogPtr pLog, IExceptionPtr pException);

    void Execute() override;
};

#endif