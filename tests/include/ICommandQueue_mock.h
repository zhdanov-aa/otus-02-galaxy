#ifndef __ICOMMANDQUEUE_MOCK_H_INCLUDED__
#define __ICOMMANDQUEUE_MOCK_H_INCLUDED__

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <ICommandQueue.h>

class ICommandQueueMock: public ICommandQueue
{
public:
    MOCK_METHOD(ICommandPtr, GetCommand, ());
};

#endif