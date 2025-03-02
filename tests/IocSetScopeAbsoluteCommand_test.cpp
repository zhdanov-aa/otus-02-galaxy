#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <IocSetScopeAbsoluteCommand.h>
#include <IException_mock.h>
#include <IScope_mock.h>
#include <IScopeChanger_mock.h>
#include <memory>

using namespace std;
using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;
using ::testing::InSequence;


TEST(IocSetScopeAbsoluteCommand, ChangeScopeToRoot)
{
    IScopeMockPtr rootScope = make_shared<IScopeMock>();
    string targetScopeName = "/";
    IScopeChangerMockPtr scopeChanger = make_shared<IScopeChangerMock>();
    IocSetScopeAbsoluteCommand cmd(rootScope, scopeChanger, targetScopeName);

    EXPECT_CALL(*scopeChanger, Change(static_pointer_cast<IScope>(rootScope)));

    EXPECT_NO_THROW(cmd.Execute());
}