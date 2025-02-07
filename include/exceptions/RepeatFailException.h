#ifndef __REPEATFAILEXCEPTION_H_INCLUDED__
#define __REPEATFAILEXCEPTION_H_INCLUDED__

#include <memory>
#include <IException.h>
#include <ICommand.h>

class RepeatFailException: public IException
{
    ICommandPtr m_pCommand;
    IExceptionPtr m_pException;

public:
    RepeatFailException(ICommandPtr pCommand, IExceptionPtr pException);

    ICommandPtr getCommand();
    IExceptionPtr getException();

    std::string WhatHappened() override;
};

typedef std::shared_ptr<RepeatFailException> RepeatFailExceptionPtr;

#endif