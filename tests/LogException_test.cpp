#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <LogException.h>
#include <ILog_mock.h>
#include <IException_mock.h>

using namespace std;
using ::testing::Return;

TEST(LogException, CheckWriteToLog)
{
    shared_ptr<ILogMock> pLog = make_shared<ILogMock>();
    shared_ptr<IExceptionMock> pException = make_shared<IExceptionMock>();
    LogException le(pLog, pException);

    EXPECT_CALL(*pException, WhatHappened()).WillOnce(Return("test"));
    EXPECT_CALL(*pLog, Write("test"));

    le.Execute();
}