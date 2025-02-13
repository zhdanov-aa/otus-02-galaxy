#ifndef __MACROCOMMAND_H_INCLUDED__
#define __MACROCOMMAND_H_INCLUDED__

#include <ICommand.h>
#include <ICommandQueue.h>
#include <memory>

class MacroCommand: public ICommand
{
    ICommandQueuePtr m_pCommands;

public:
    MacroCommand(ICommandQueuePtr commands);

    void Execute() override;
};

typedef std::shared_ptr<MacroCommand> MacroCommandPtr;

#endif