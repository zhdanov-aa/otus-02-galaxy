#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <WriteExceptionToLog.h>

using namespace std;
using ::testing::Return;

class ILogMock: public ILog
{
public:
    MOCK_METHOD(void, Write, (string));
};

class IExceptionMock: public IException
{
public:
    MOCK_METHOD(string, WhatHappened, ());
};

TEST(WriteExceptionToLog, CheckExecute)
{
    shared_ptr<ILogMock> pLog = make_shared<ILogMock>();
    shared_ptr<IExceptionMock> pException = make_shared<IExceptionMock>();
    WriteExceptionToLog we(pLog, pException);

    EXPECT_CALL(*pException, WhatHappened()).WillOnce(Return("test"));
    EXPECT_CALL(*pLog, Write("test"));

    we.Execute();
}