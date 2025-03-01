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

    EXPACT_CALL(*currentScope, FindChild(scopeName)).WillOnce(Return(nullptr));
    EXPACT_CALL(*currentScope, AddChild(_));

    EXPACT_NO_THROW(cmd.Execute());
}