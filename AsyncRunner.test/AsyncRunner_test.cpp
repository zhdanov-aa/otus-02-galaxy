#include <IoC.h>
#include <ICommand.h>
#include <StartCommand.h>
#include <BlockingQueue.h>
#include <AsyncRunner.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

using namespace std;
using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;
using ::testing::InSequence;

TEST(AsyncRunner, CheckStartCommand)
{
    IoC::Resolve<ICommandPtr>("IoC.Scope.New", "CheckThreadRunning")->Execute();
    IoC::Resolve<ICommandPtr>("IoC.Scope.Current.Set", "CheckThreadRunning")->Execute();

    StartCommandPtr startCommand = std::make_shared<StartCommand>();
    startCommand->Execute();

    BlockingQueuePtr q;
    AsyncRunnerPtr r;

    EXPECT_NO_THROW(q = IoC::Resolve<BlockingQueuePtr>("AsyncRunner.Queue.Get"));
    EXPECT_NO_THROW(r = IoC::Resolve<AsyncRunnerPtr>("AsyncRunner.Instance.Get"));

    EXPECT_NE(q, nullptr);
    EXPECT_NE(r, nullptr);

    //TODO: проверить, что поток запущен
}
