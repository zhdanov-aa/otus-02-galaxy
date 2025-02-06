#include <WriteExceptionToLog.h>

WriteExceptionToLog::WriteExceptionToLog(ILogPtr pLog, IExceptionPtr pException)
    : m_pLog(pLog), m_pException(pException)
{
}

void WriteExceptionToLog::Execute()
{
    m_pLog->Write(m_pException->WhatHappened());
}