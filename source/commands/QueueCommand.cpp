#include <QueueCommand.h>

QueueCommand::QueueCommand(ICommandQueueBuilderPtr pBuilder, ICommandPtr pCommand)
    : m_pBuilder(pBuilder), m_pCommand(pCommand)
{
}

void QueueCommand::Execute()
{
    m_pBuilder->AddCommand(m_pCommand);
}