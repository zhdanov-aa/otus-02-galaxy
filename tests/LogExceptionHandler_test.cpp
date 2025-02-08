#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <LogExceptionHandler.h>
#include <LogException.h>
#include <IException_mock.h>
#include <ICommandQueueBuilder_mock.h>
#include <ILog_mock.h>

using namespace std;
using ::testing::Return;
using ::testing::_;

TEST(LogExceptionHandler, Check_add_LogException_to_ICommandQueueBuilder)
{
    shared_ptr<ICommandQueueBuilderMock> pBuilder = make_shared<ICommandQueueBuilderMock>();
    shared_ptr<IExceptionMock> pException = make_shared<IExceptionMock>();
    shared_ptr<ILogMock> pLog = make_shared<ILogMock>();
    LogExceptionHandler cmd(pLog, pException, pBuilder);

    EXPECT_CALL(*pBuilder, AddCommand(_));

    EXPECT_NO_THROW(cmd.Execute());
}