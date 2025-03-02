#ifndef __ICOMMANDQUEUEBUILDER_MOCK_H_INCLUDED__
#define __ICOMMANDQUEUEBUILDER_MOCK_H_INCLUDED__

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <ICommandQueueBuilder.h>

class ICommandQueueBuilderMock: public ICommandQueueBuilder
{
public:
    MOCK_METHOD(void, AddCommand, (ICommandPtr));
};

#endif