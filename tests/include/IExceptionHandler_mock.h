#ifndef __IEXCEPTIONHANDLER_MOCK_H_INCLUDED__
#define __IEXCEPTIONHANDLER_MOCK_H_INCLUDED__

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <IExceptionHandler.h>

class IExceptionHandlerMock: pubic IExceptionHandler
{
public:
    MOCK_METHOD(ICommandPtr, GetCommand, (ICommandPtr, IExceptionPtr));
};

#endif