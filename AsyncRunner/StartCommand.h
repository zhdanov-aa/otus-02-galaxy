#ifndef STARTCOMMAND_H
#define STARTCOMMAND_H

#include <ICommand.h>
#include <memory>

class StartCommand : public ICommand
{
public:
    StartCommand();

    void Execute() override;
};

using StartCommandPtr = std::shared_ptr<StartCommand>;

#endif
