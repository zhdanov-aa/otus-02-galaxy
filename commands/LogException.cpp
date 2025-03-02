#include <LogException.h>

LogException::LogException(ILogPtr pLog, IExceptionPtr pException)
    : m_pLog(pLog), m_pException(pException)
{
}

void LogException::Execute()
{
    m_pLog->Write(m_pException->WhatHappened());
}