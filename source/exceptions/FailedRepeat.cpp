#include <FailedRepeat.h>

FailedRepeat::FailedRepeat(ICommandPtr pCommand, IExceptionPtr pException)
    : m_pCommand(pCommand), m_pException(pException)
{
}

ICommandPtr FailedRepeat::getCommand()
{
    return m_pCommand;
}

IExceptionPtr FailedRepeat::getException()
{
    return m_pException;
}

std::string FailedRepeat::WhatHappened()
{
    return std::string("Repeat command failed with exception: ") + m_pException->WhatHappened();
}