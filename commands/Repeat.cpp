#include <Repeat.h>
#include <FailedRepeat.h>

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
        throw new FailedRepeat(m_pRepeatedCommand, IExceptionPtr(pException));
    }
}