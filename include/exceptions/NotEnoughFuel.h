#ifndef __NOTENOUGHFUEL_H_INCLUDED__
#define __NOTENOUGHFUEL_H_INCLUDED__

#include <IException.h>
#include <memory>

class NotEnoughFuel: public IException
{
public:
    std::string WhatHappened() override;
};

typedef std::shared_ptr<NotEnoughFuel> NotEnoughFuelPtr;

#endif