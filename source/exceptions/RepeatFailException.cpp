#include <RepeatFailException.h>

RepeatFailException::RepeatFailException(ICommandPtr pCommand, IExceptionPtr pException)
    : m_pCommand(pCommand), m_pException(pException)
{

}

ICommandPtr RepeatFailException::getCommand()
{
    return m_pCommand;
}

IExceptionPtr RepeatFailException::getException()
{
    return m_pException;
}

std::string WhatHappened()
{
    return std::string("Repeat command failed with exception: ") + m_pException->WhatHappened();
}