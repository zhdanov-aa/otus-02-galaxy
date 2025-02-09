#include <RepeatTwiceHandler.h>
#include <RepeatTwice.h>
#include <memory>

RepeatTwiceHandler::RepeatTwiceHandler(ICommandPtr command, ICommandQueueBuilderPtr builder)
    : m_pCommand(command), m_pBuilder(builder)
{
}

void RepeatTwiceHandler::Execute()
{
    m_pBuilder->AddCommand( std::make_shared<RepeatTwice>(m_pCommand) );
}
