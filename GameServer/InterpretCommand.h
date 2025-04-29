#ifndef INTERPRETCOMMAND_H
#define INTERPRETCOMMAND_H

#include <memory>
#include <ICommand.h>

class InterpretCommand : public ICommand
{
public:
    InterpretCommand();

    void Execute() override;
};

using InterpretCommandPtr = std::shared_ptr<InterpretCommand>;

#endif // INTERPRETCOMMAND_H
