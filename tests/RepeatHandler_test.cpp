#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <RepeatHandler.h>
#include <Repeat.h>
#include <ICommand_mock.h>
#include <ICommandQueueBuilder_mock.h>

using namespace std;
using ::testing::Return;
using ::testing::_;

MATCHER(IsRepeat, "") { return std::dynamic_pointer_cast<Repeat>(arg) != nullptr; }

TEST(RepeatHandler, Check_add_Repeat_command_to_ICommandQueueBuilder)
{
    shared_ptr<ICommandQueueBuilderMock> pBuilder = make_shared<ICommandQueueBuilderMock>();
    shared_ptr<ICommandMock> pCommand = make_shared<ICommandMock>();
    RepeatHandler cmd(pCommand, pBuilder);

    EXPECT_CALL(*pBuilder, AddCommand(IsRepeat()));

    EXPECT_NO_THROW(cmd.Execute());
}