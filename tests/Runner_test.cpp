#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Runner.h>
#include <ICommandQueue_mock.h>
#include <IExceptionHandler_mock.h>
#include <ICommand_mock.h>

using namespace std;
using ::testing::Return;

TEST(Runner, Check_throw_repeat_log)
{
    shared_ptr<ICommandQueueMock> pCommandQueue = make_shared<ICommandQueueMock>();
    shared_ptr<IExceptionHandlerMock> pExceptionHandler = make_shared<IExceptionHandlerMock>();
    //shared_ptr<ICommandMock> pCommand = make_shared<ICommandMock>();
    Runner runner(pCommandQueue, pExceptionHandler);

    EXPECT_CALL(*pCommandQueue, GetCommand()).WillOnce(Return(nullptr));

    runner.Execute();
}