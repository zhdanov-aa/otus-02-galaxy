#ifndef __REPEATHANDLER_H_INCLUDED__
#define __REPEATHANDLER_H_INCLUDED__

#include <ICommand.h>
#include <ICommandQueueBuilder.h>
#include <memory>

class RepeatHandler: public ICommand
{
    ICommandPtr m_pCommand;
    ICommandQueueBuilderPtr m_pBuilder;
public:
    RepeatHandler(ICommandPtr command, ICommandQueueBuilderPtr builder);

    void Execute() override;
};

typedef std::shared_ptr<RepeatHandler> RepeatHandlerPtr;

#endif