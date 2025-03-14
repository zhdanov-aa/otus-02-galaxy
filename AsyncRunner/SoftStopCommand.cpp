#include <SoftStopCommand.h>
#include <InvalidArgument.h>

SoftStopCommand::SoftStopCommand(AsyncRunnerPtr pRunner)
    : m_pRunner(pRunner)
{

}

void SoftStopCommand::Execute()
{
    if (m_pRunner == nullptr)
        throw new InvalidArgument("SoftStopCommand::Execute(): m_pRunner is nullptr");

    m_pRunner->setCheckContinueAction(
        [this](){
            return (m_pRunner->getQueue()->getSize() > 0);
        });
}
