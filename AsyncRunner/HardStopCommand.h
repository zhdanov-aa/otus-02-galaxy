#ifndef HARDSTOPCOMMAND_H
#define HARDSTOPCOMMAND_H

#include <ICommand.h>
#include <AsyncRunner.h>
#include <memory>

class HardStopCommand : public ICommand
{
    AsyncRunnerPtr m_pRunner;

public:
    HardStopCommand(AsyncRunnerPtr pRunner);

    void Execute() override;
};

using HardStopCommandPtr = std::shared_ptr<HardStopCommand>;

#endif // HARDSTOPCOMMAND_H
