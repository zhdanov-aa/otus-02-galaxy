#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <LogExceptionHandler.h>
#include <IException_mock.h>
#include <ICommandQueueBuilder_mock.h>
#include <ILog_mock.h>

using namespace std;
using ::testing::Return;
using ::testing::_;
using ::testing::A;

TEST(LogExceptionHandler, CheckExecute)
{
    shared_ptr<ICommandQueueBuilderMock> pBuilder = make_shared<ICommandQueueBuilderMock>();
    shared_ptr<IExceptionMock> pException = make_shared<IExceptionMock>();
    shared_ptr<ILogMock> pMock = make_shared<ILogMock>();
    LogExceptionHandler cmd(pLog, pException, pBuilder);

    EXPECT_CALL(*pBuilder, AddCommand(_));

    EXPECT_NO_THROW(cmd.Execute());
}