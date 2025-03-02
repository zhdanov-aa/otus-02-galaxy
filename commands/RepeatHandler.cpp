#include <RepeatHandler.h>
#include <Repeat.h>
#include <memory>

RepeatHandler::RepeatHandler(ICommandPtr command, ICommandQueueBuilderPtr builder)
    : m_pCommand(command), m_pBuilder(builder)
{
}

void RepeatHandler::Execute()
{
    m_pBuilder->AddCommand( std::make_shared<Repeat>(m_pCommand) );
}
