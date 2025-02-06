#ifndef __QUEUECOMMAND_H_INCLUDED__
#define __QUEUECOMMAND_H_INCLUDED__

#include <ICommand.h>
#include <ICommandQueueBuilder.h>

class QueueCommand: ICommand
{
    ICommandQueueBuilderPtr m_pBuilder;
    ICommandPtr m_pCommand;
public:
    QueueCommand(ICommandQueueBuilderPtr pBuilder, ICommandPtr pCommand);

    void Execute() override;
};

#endif