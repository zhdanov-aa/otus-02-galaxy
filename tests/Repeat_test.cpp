#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Repeat.h>
#include <stdexcept>
#include <ICommand_mock.h>

using namespace std;
using ::testing::Return;
using ::testing::Throw;

TEST(Repeat, Check_success_repeate)
{
    shared_ptr<ICommandMock> pCommand = make_shared<ICommandMock>();
    Repeat cmd(pCommand);

    EXPECT_CALL(*pCommand, Execute());

    EXPECT_NO_THROW(cmd.Execute());
}

TEST(Repeat, Check_fail_repeate)
{
    shared_ptr<ICommandMock> pCommand = make_shared<ICommandMock>();
    Repeat cmd(pCommand);

    EXPECT_CALL(*pCommand, Execute()).WillOnce(Throw(runtime_error("ICommand::Execute() failed")));

    EXPECT_ANY_THROW(cmd.Execute());
}