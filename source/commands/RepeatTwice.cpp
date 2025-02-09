#include <RepeatTwice.h>
#include <FailedRepeat.h>

RepeatTwice::RepeatTwice(ICommandPtr pCommand)
    : m_pRepeatedCommand(pCommand)
{

}

void RepeatTwice::Execute()
{
    IExceptionPtr pExecuteException = nullptr;
    int repeatCount = 2;

    do 
    {
        pExecuteException = nullptr;
        try
        {
            m_pRepeatedCommand->Execute();
        }
        catch(IException *pException)
        {
            pExecuteException = IExceptionPtr(pException);
        }
    }
    while ((pExecuteException != nullptr) && (repeatCount--) );

    if (pExecuteException != nullptr)
    {
        throw new FailedRepeat(m_pRepeatedCommand, pExecuteException);
    }
}