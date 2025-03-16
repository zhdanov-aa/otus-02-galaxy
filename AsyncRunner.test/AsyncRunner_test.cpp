#include <IoC.h>
#include <ICommand.h>
#include <StartCommand.h>
#include <BlockingQueue.h>
#include <AsyncRunner.h>
#include <HardStopCommand.h>
#include <SoftStopCommand.h>
#include <ICommand_mock.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>


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

TEST(AsyncRunner, HardStopTest)
{
    std::mutex              mutex;
    std::condition_variable condition;

    BlockingQueuePtr q = std::make_shared<BlockingQueue>();
    AsyncRunnerPtr r = std::make_shared<AsyncRunner>(q);

    std::shared_ptr<ICommandMock> c1 = std::make_shared<ICommandMock>();
    HardStopCommandPtr hs = std::make_shared<HardStopCommand>(r);
    std::shared_ptr<ICommandMock> c2 = std::make_shared<ICommandMock>();

    q->Push(c1);
    q->Push(hs);
    q->Push(c2);

    r->setStopAction([&condition](){ condition.notify_one(); });

    EXPECT_CALL(*c1, Execute());

    EXPECT_NO_THROW(r->Start());

    std::unique_lock<std::mutex> lock(mutex);
    condition.wait(lock);

    EXPECT_EQ(1, q->getSize());
}

TEST(AsyncRunner, SoftStopTest)
{
    std::mutex              mutex;
    std::condition_variable condition;

    BlockingQueuePtr q = std::make_shared<BlockingQueue>();
    AsyncRunnerPtr r = std::make_shared<AsyncRunner>(q);

    std::shared_ptr<ICommandMock> c1 = std::make_shared<ICommandMock>();
    SoftStopCommandPtr ss = std::make_shared<SoftStopCommand>(r);
    std::shared_ptr<ICommandMock> c2 = std::make_shared<ICommandMock>();

    q->Push(c1);
    q->Push(ss);
    q->Push(c2);

    r->setStopAction([&condition](){ condition.notify_one(); });

    EXPECT_CALL(*c1, Execute());
    EXPECT_CALL(*c2, Execute());

    EXPECT_NO_THROW(r->Start());

    std::unique_lock<std::mutex> lock(mutex);
    condition.wait(lock);

    EXPECT_EQ(0, q->getSize());
}
