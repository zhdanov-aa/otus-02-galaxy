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
    shared_ptr<ICommand> cmd1 = make_shared<ICommand>();
    shared_ptr<ICommand> cmd2 = make_shared<ICommand>();
    shared_ptr<ICommand> cmd3 = make_shared<ICommand>();
    MacroCommand cmd(commands);

    EXPECT_CALL(*commands, GetCommand())
        .WillOnce(Return(cmd1))
        .WillOnce(Return(cmd2))
        .WillOnce(Return(cmd3))
        .WillOnce(Return(nullptr));

    auto cmd1_call = EXPECT_CALL(*cmd1, Execute()).Times(1);
    auto cmd2_call EXPECT_CALL(*cmd2, Execute()).Times(1).After(cmd1_call);
    EXPECT_CALL(*cmd3, Execute()).Times(1).After(cmd2_call);
    
    EXPECT_NO_THROW(cmd.Execute());
}