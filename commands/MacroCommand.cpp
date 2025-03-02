#include <MacroCommand.h>
#include <CommandException.h>

MacroCommand::MacroCommand(ICommandQueuePtr commands)
    : m_pCommands(commands)
{
}

void MacroCommand::Execute()
{
    if (m_pCommands == nullptr)
        return;

    ICommandPtr pCmd = nullptr;
    while (pCmd = m_pCommands->GetCommand())
    {
        try
        {
            pCmd->Execute();
        }
        catch(IException *e)
        {
            throw new CommandException(pCmd, IExceptionPtr(e));    
        }
    }
}