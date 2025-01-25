#ifndef __ACTION_H_INCLUDED__
#define __ACTION_H_INCLUDED__

class Action
{
protected:
    virtual ~Action() = default;

public:
    virtual void execute(void) = 0;
};

#endif