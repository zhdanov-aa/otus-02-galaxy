#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <MacroCommand.h>
#include <ICommandQueue_mock.h>
#include <ICommand_mock.h>

using namespace std;
using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

TEST(MacroCommand, ExecuteCommands)
{
    shared_ptr<ICommandQueueMock> commands = make_shared<ICommandQueueMock>();
    shared_ptr<ICommandMock> cmd1 = make_shared<ICommandMock>();
    shared_ptr<ICommandMock> cmd2 = make_shared<ICommandMock>();
    shared_ptr<ICommandMock> cmd3 = make_shared<ICommandMock>();
    MacroCommand cmd(commands);

    EXPECT_CALL(*commands, GetCommand())
        .WillOnce(Return(cmd1))
        .WillOnce(Return(cmd2))
        .WillOnce(Return(cmd3))
        .WillOnce(Return(nullptr));

    EXPECT_CALL(*cmd1, Execute()).WillOnce();
    EXPECT_CALL(*cmd2, Execute()).WillOnce();
    EXPECT_CALL(*cmd3, Execute()).WillOnce();
    
    EXPECT_NO_THROW(cmd.Execute());
}