#ifndef __ICOMMANDQUEUEBUILDER_H_INCLUDED__
#define __ICOMMANDQUEUEBUILDER_H_INCLUDED__

#include <ICommand.h>
#include <memory>

class ICommandQueueBuilder
{
public:
    virtual ~ICommandQueueBuilder() = default;

    virtual void AddCommand(ICommandPtr pCommand) = 0;
};

typedef shared_ptr<ICommandQueueBuilder> ICommandQueueBuilderPtr;

#endif