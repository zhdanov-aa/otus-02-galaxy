#ifndef __REPEATCOMMAND_H_INCLUDED__
#define __REPEATCOMMAND_H_INCLUDED__

#include <memory>
#include <ICommand.h>

class RepeatCommand: public ICommand
{
public:
    RepeatCommand(ICommandPtr pCommand);

    void Execute() override;
};

typedef std::shared_ptr<RepeatCommand> RepeatCommandPtr;

#endif