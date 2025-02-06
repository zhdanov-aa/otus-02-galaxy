#ifndef __ILOG_MOCK_H_INCLUDED__
#define __ILOG_MOCK_H_INCLUDED__

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <ILog.h>

class ILogMock: public ILog
{
public:
    MOCK_METHOD(void, Write, (std::string));
};

#endif