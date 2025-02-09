#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Runner.h>
#include <LogExceptionHandler.h>
#include <RepeatHandler.h>
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
ACTION_P(ReturnRepeatHandler, p1) { return make_shared<RepeatHandler>(arg0, p1); }

TEST(Runner, Check_throw_repeat_log)
{
    shared_ptr<ICommandQueueMock> pCommandQueue = make_shared<ICommandQueueMock>();
    shared_ptr<IExceptionHandlerMock> pExceptionHandler = make_shared<IExceptionHandlerMock>();
    shared_ptr<ICommandQueueBuilderMock> pBuilder = make_shared<ICommandQueueBuilderMock>();
    shared_ptr<ILogMock> pLog = make_shared<ILogMock>();
    shared_ptr<ICommandMock> pCommand = make_shared<ICommandMock>();
    IExceptionMock *pException1 = new IExceptionMock();
    IExceptionMock *pException2 = new IExceptionMock();
    ICommandPtr pLogCmd = nullptr;
    ICommandPtr pRepeatCmd = nullptr;
    Runner runner(pCommandQueue, pExceptionHandler);

    EXPECT_CALL(*pException2, WhatHappened())
        .WillOnce(Return("exception2"));

    EXPECT_CALL(*pCommand, Execute())
        .WillOnce(Throw(pException1))
        .WillOnce(Throw(pException2));
    
    EXPECT_CALL(*pCommandQueue, GetCommand())
        .WillOnce(Return(pCommand))
        .WillOnce( [&pRepeatCmd](){ return pRepeatCmd; })
        .WillOnce( [&pLogCmd](){ return pLogCmd; })
        .WillOnce(Return(nullptr));
    
    EXPECT_CALL(*pExceptionHandler, GetCommand(_,_))
        .WillOnce(ReturnRepeatHandler(pBuilder))
        .WillOnce(ReturnLogExceptionHandler(pLog, pBuilder));

    EXPECT_CALL(*pBuilder, AddCommand(_))
        .WillOnce(SaveArg<0>(&pRepeatCmd))
        .WillOnce(SaveArg<0>(&pLogCmd));

    EXPECT_CALL(*pLog, Write(_));

    runner.Execute();
}