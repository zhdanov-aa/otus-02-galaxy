#ifndef __ILOG_H_INCLUDED__
#define __ILOG_H_INCLUDED__

#include <string>
#include <memory>

using namespace std;

class ILog
{
public:
    virtual ~ILog() = default;

    virtual void Write(string message) = 0;
};

typedef shared_ptr<ILog> ILogPtr;

#endif