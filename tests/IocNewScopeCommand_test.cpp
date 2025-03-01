#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <IocNewScopeCommand.h>
#include <IScope_mock.h>

using namespace std;
using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;
using ::testing::InSequence;


TEST(IocNewScopeCommand, SunnyDayTest)
{
    IScopeMockPtr currentScope = make_shared<IScopeMock>();
    string scopeName = "testScope";
    IocNewScopeCommand cmd(currentScope, scopeName);

    EXPECT_CALL(*currentScope, FindChild(scopeName)).WillOnce(Return(nullptr));
    EXPECT_CALL(*currentScope, AddChild(_));

    EXPECT_NO_THROW(cmd.Execute());
}