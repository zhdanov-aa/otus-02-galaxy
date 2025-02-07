#include <RepeatCommand.h>
#include <RepeatFailException.h>

RepeatCommand::RepeatCommand(ICommandPtr pCommand)
    : m_pRepeatedCommand(pCommand)
{

}

void RepeatCommand::Execute()
{
    try
    {
        m_pRepeatedCommand->Execute();
    }
    catch(IException *pException)
    {
        throw new RepeatFailException(m_pRepeatedCommand, IExceptionPtr(pException));
    }
}