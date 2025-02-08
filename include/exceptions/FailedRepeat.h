#ifndef __FAILEDREPEAT_H_INCLUDED__
#define __FAILEDREPEAT_H_INCLUDED__

#include <memory>
#include <IException.h>
#include <ICommand.h>

class FailedRepeat: public IException
{
    ICommandPtr m_pCommand;
    IExceptionPtr m_pException;

public:
    FailedRepeat(ICommandPtr pCommand, IExceptionPtr pException);

    ICommandPtr getCommand();
    IExceptionPtr getException();

    std::string WhatHappened() override;
};

typedef std::shared_ptr<FailedRepeat> FailedRepeatPtr;

#endif