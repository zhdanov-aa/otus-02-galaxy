#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <QueueCommand.h>
#include <ICommand_mock.h>
#include <ICommandQueueBuilder_mock.h>

using namespace std;
using ::testing::Return;

TEST(QueueCommand, CheckExecute)
{
    shared_ptr<ICommandQueueBuilderMock> pBuilder = make_shared<ICommandQueueBuilderMock>();
    shared_ptr<ICommandMock> pCommand = make_shared<ICommandMock>();
    QueueCommand cmd(pBuilder, pCommand);

    EXPECT_CALL(*pBuilder, AddCommand(pCommand));

    le.Execute();
}