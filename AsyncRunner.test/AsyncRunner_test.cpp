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
#include <mutex>
#include <condition_variable>


using namespace std;
using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;
using ::testing::InSequence;

TEST(AsyncRunner, StartTest)
{
    // Создание scope, где будет проходить проверка
    IoC::Resolve<ICommandPtr>("IoC.Scope.New", "StartTest")->Execute();
    IoC::Resolve<ICommandPtr>("IoC.Scope.Current.Set", "StartTest")->Execute();

    // Создание AsyncRunner в текущем scope
    StartCommandPtr startCommand = std::make_shared<StartCommand>();
    startCommand->Execute();

    BlockingQueuePtr q;
    AsyncRunnerPtr r;

    // Проверка созданных зависимостей
    EXPECT_NO_THROW(q = IoC::Resolve<BlockingQueuePtr>("AsyncRunner.Queue.Get"));
    EXPECT_NO_THROW(r = IoC::Resolve<AsyncRunnerPtr>("AsyncRunner.Instance.Get"));

    EXPECT_NE(q, nullptr);
    EXPECT_NE(r, nullptr);

    // Проверка того, что AsyncRunner запущен (методом выполнения тестовой команды)
    std::mutex              mutex;
    std::condition_variable condition;
    std::shared_ptr<ICommandMock> testCommand = std::make_shared<ICommandMock>();

    EXPECT_CALL(*testCommand, Execute()).WillOnce([&condition](){ condition.notify_one(); });

    q->Push(testCommand);

    std::unique_lock<std::mutex> lock(mutex);
    condition.wait(lock);
    SUCCEED();
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
