#include <Repeat.h>
#include <RepeatFailException.h>

Repeat::Repeat(ICommandPtr pCommand)
    : m_pRepeatedCommand(pCommand)
{

}

void Repeat::Execute()
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