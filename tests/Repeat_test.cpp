#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Repeat.h>
#include <stdexcept>

using namespace std;
using ::testing::Return;

TEST(Repeat, Check_success_repeated_command_execute)
{
    shared_ptr<ICommandMock> pCommand = make_shared<ICommandMock>();
    Repeat cmd(pCommand);

    EXPECT_CALL(*pCommand, Execute());

    EXPECT_NO_THROW(cmd.Execute());
}

TEST(Repeat, Check_fail_repeated_command_excute)
{
    shared_ptr<ICommandMock> pCommand = make_shared<ICommandMock>();
    Repeat cmd(pCommand);

    EXPECT_CALL(*pCommand, Execute()).WillOnce(Throw(std::runtime_error("ICommand::Execute() failed")));

    EXPECT_ANY_THROW(cmd.Execute());
}