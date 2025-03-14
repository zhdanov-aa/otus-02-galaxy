#include <StartCommand.h>
#include <IoC.h>
#include <BlockingQueue.h>
#include <AsyncRunner.h>
#include <memory>

StartCommand::StartCommand()
{

}

void StartCommand::Execute()
{
    BlockingQueuePtr q = std::make_shared<BlockingQueue>();
    AsyncRunnerPtr r = std::make_shared<AsyncRunner>(q);

    IoC::Resolve<ICommandPtr>(
        "IoC.Register",
        "AsyncRunner.Queue.Get",
        make_container(std::function<BlockingQueuePtr()>( [=](){ return q; } ))
        )->Execute();

    IoC::Resolve<ICommandPtr>(
        "IoC.Register",
        "AsyncRunner.Instance.Get",
        make_container(std::function<AsyncRunnerPtr()>( [=](){ return r; } ))
        )->Execute();

    r->Start();
}
