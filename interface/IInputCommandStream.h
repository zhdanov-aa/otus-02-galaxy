#ifndef IINPUTCOMMANDSTREAM_H
#define IINPUTCOMMANDSTREAM_H

#include <ICommand.h>
#include <memory>

class IInputCommandStream
{
public:
    virtual ~IInputCommandStream() = default;

    virtual int Count() = 0;
    virtual ICommandPtr Read() = 0;
};

using IInputCommandStreamPtr = std::shared_ptr<IInputCommandStream>;

#endif // IINPUTCOMMANDSTREAM_H
