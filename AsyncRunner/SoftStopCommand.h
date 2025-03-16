#ifndef SOFTSTOPCOMMAND_H
#define SOFTSTOPCOMMAND_H

#include <ICommand.h>
#include <AsyncRunner.h>
#include <memory>

class SoftStopCommand : public ICommand
{
    AsyncRunnerPtr m_pRunner;

public:
    SoftStopCommand(AsyncRunnerPtr pRunner);

    void Execute() override;
};

using SoftStopCommandPtr = std::shared_ptr<SoftStopCommand>;

#endif
