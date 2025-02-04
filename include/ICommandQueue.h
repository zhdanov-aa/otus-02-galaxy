#ifndef __ICOMMANDQUEUE_H_INCLUDED__
#define __ICOMMANDQUEUE_H_INCLUDED__

#include <memory>
#include <ICommand.h>

class ICommandQueue
{
public:
    virtual ~ICommandQueue() = default;

    /*!
        \return Первую команду из очереди. Если очередь пуста, то возвращает nullptr.
    */
    virtual ICommandPtr GetCommand() = 0;
};

typedef std::shared_ptr<ICommandQueue> ICommandQueuePtr;

#endif