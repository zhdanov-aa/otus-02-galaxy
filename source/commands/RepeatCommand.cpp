#include <RepeatCommand.h>
#include <RepeatFailException.h>

RepeatCommand::RepeatCommand(ICommandPtr pCommand)
    : m_pCommand(pCommand)
{

}

void RepeatCommand::Execute()
{
    try
    {
        m_pCommand->Execute();
    }
    catch(IException *pException)
    {
        throw new RepeatFailException(m_pCommand, IExceptionPtr(pException));
    }
}