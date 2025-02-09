#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Runner.h>
#include <LogExceptionHandler.h>
#include <ICommandQueue_mock.h>
#include <IExceptionHandler_mock.h>
#include <ICommand_mock.h>
#include <IException_mock.h>
#include <ILog_mock.h>
#include <ICommandQueueBuilder_mock.h>

using namespace std;
using ::testing::Return;
using ::testing::Throw;
using ::testing::SaveArg;
using ::testing::_;

ACTION_P2(ReturnLogExceptionHandler, p1, p2) { return make_shared<LogExceptionHandler>(p1, arg1, p2); }

TEST(Runner, Check_throw_repeat_log)
{
    shared_ptr<ICommandQueueMock> pCommandQueue = make_shared<ICommandQueueMock>();
    shared_ptr<IExceptionHandlerMock> pExceptionHandler = make_shared<IExceptionHandlerMock>();
    shared_ptr<ICommandQueueBuilderMock> pBuilder = make_shared<ICommandQueueBuilderMock>();
    shared_ptr<ILogMock> pLog = make_shared<ILogMock>();
    shared_ptr<ICommandMock> pCommand = make_shared<ICommandMock>();
    IExceptionMock *pException = new IExceptionMock();
    ICommandPtr pLogCmd = nullptr;
    Runner runner(pCommandQueue, pExceptionHandler);

    EXPECT_CALL(*pException, WhatHappened())
        .WillOnce(Return("exception"));
    
    EXPECT_CALL(*pCommand, Execute())
        .WillOnce(Throw(pException));
    
    EXPECT_CALL(*pCommandQueue, GetCommand())
        .WillOnce(Return(pCommand))
        .WillOnce(ReturnRef(pLogCmd))
        .WillOnce(Return(nullptr));
    
    EXPECT_CALL(*pExceptionHandler, GetCommand(_,_))
        .WillOnce(ReturnLogExceptionHandler(pLog, pBuilder));

    EXPECT_CALL(*pBuilder, AddCommand(_)).WillOnce(SaveArg<0>(&pLogCmd));

    EXPECT_CALL(*pLog, Write(_));

    runner.Execute();
}