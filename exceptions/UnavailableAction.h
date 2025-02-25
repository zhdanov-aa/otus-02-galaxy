#ifndef __UNAVAILABLEACTION_H_INCLUDED__
#define __UNAVAILABLEACTION_H_INCLUDED__

#include <IException.h>
#include <string>
#include <memory>

class UnavailableAction: public IException
{
    std::string m_sMessage;

public:
    UnavailableAction(std::string message);

    std::string WhatHappened() override;
};

typedef std::shared_ptr<UnavailableAction> UnavailableActionPtr;

#endif