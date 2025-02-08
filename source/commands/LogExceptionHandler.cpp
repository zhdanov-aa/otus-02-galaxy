#include <LogExceptionHandler.h>

LogExceptionHandler::LogExceptionHandler(ILogPtr log, IExceptionPtr exception, ICommandQueueBuilderPtr builder)
    : m_pLog(log), m_pException(exception), m_pBuilder(builder)
{
}

void LogExceptionHandler::Execute()
{
    m_pBuilder->AddCommand( make_shared<LogException>(m_pLog, m_pException) );
}