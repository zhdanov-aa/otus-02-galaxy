#ifndef __ILOG_H_INCLUDED__
#define __ILOG_H_INCLUDED__

class ILog
{
public:
    virtual ~ILog() = default;

    virtual Write(std::string message) = 0;
};

#endif