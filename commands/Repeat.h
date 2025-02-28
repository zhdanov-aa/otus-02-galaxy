#ifndef __REPEAT_H_INCLUDED__
#define __REPEAT_H_INCLUDED__

#include <memory>
#include <ICommand.h>

class Repeat: public ICommand
{
    ICommandPtr m_pRepeatedCommand;

public:
    Repeat(ICommandPtr pCommand);

    void Execute() override;
};

typedef std::shared_ptr<Repeat> RepeatPtr;

#endif