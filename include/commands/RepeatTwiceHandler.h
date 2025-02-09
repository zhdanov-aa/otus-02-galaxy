#ifndef __REPEATTWICEHANDLER_H_INCLUDED__
#define __REPEATTWICEHANDLER_H_INCLUDED__

#include <ICommand.h>
#include <ICommandQueueBuilder.h>
#include <memory>

class RepeatTwiceHandler: public ICommand
{
    ICommandPtr m_pCommand;
    ICommandQueueBuilderPtr m_pBuilder;
public:
    RepeatTwiceHandler(ICommandPtr command, ICommandQueueBuilderPtr builder);

    void Execute() override;
};

typedef std::shared_ptr<RepeatTwiceHandler> RepeatTwiceHandlerPtr;

#endif