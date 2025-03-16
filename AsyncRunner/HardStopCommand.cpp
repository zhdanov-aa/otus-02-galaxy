#include <HardStopCommand.h>
#include <InvalidArgument.h>

HardStopCommand::HardStopCommand(AsyncRunnerPtr pRunner)
    : m_pRunner(pRunner)
{

}

void HardStopCommand::Execute()
{
    if (m_pRunner == nullptr)
        throw new InvalidArgument("HardStopCommand::Execute(): m_pRunner is nullptr");

    m_pRunner->setCheckContinueAction(
        [](){
            return false;
        });
}
