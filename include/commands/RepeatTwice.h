#ifndef __REPEATTWICE_H_INCLUDED__
#define __REPEATTWICE_H_INCLUDED__

#include <memory>
#include <ICommand.h>

class RepeatTwice: public ICommand
{
    ICommandPtr m_pRepeatedCommand;

public:
    RepeatTwice(ICommandPtr pCommand);

    void Execute() override;
};

typedef std::shared_ptr<RepeatTwice> RepeatTwicePtr;

#endif