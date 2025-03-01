#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <FallbackCommand.h>
#include <ICommand_mock.h>
#include <IException_mock.h>
#include <vector>

using namespace std;
using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;
using ::testing::InSequence;

TEST(FallbackCommand, StopOnSuccessCommand)
{
    shared_ptr<ICommandMock> command1 = make_shared<ICommandMock>();
    shared_ptr<ICommandMock> command2 = make_shared<ICommandMock>();
    vector<ICommandPtr> commands = { command1, command2 };
    FallbackCommand cmd(commands);

    EXPECT_CALL(*command1, Execute());
    
    EXPECT_NO_THROW(cmd.Execute());
}

TEST(FallbackCommand, SkipFailedCommands)
{
    shared_ptr<ICommandMock> command1 = make_shared<ICommandMock>();
    shared_ptr<ICommandMock> command2 = make_shared<ICommandMock>();
    vector<ICommandPtr> commands = { command1, command2 };
    FallbackCommand cmd(commands);

    EXPECT_CALL(*command1, Execute()).WillOnce(Throw(new IExceptionMock));
    EXPECT_CALL(*command2, Execute());
    
    EXPECT_NO_THROW(cmd.Execute());

    // shared_ptr<ICommandQueueMock> commands = make_shared<ICommandQueueMock>();
    // shared_ptr<ICommandMock> cmd1 = make_shared<ICommandMock>();
    // shared_ptr<ICommandMock> cmd2 = make_shared<ICommandMock>();
    // MacroCommand cmd(commands);

    // EXPECT_CALL(*commands, GetCommand())
    //     .WillOnce(Return(cmd1))
    //     .WillOnce(Return(cmd2));

    // {
    //     InSequence s;

    //     EXPECT_CALL(*cmd1, Execute());
    //     EXPECT_CALL(*cmd2, Execute()).WillOnce(Throw(new IExceptionMock));
    // }
    
    // try
    // {
    //     cmd.Execute();
    //     FAIL();
    // }
    // catch(IException *exception)
    // {
    //     EXPECT_NE(dynamic_cast<CommandException*>(exception), nullptr);
    //     delete exception;
    // }
}

// TEST(FallbackCommand, SkipFailedCommands)
// {
// }
