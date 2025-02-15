#include <UnavailableAction.h>

UnavailableAction::UnavailableAction(std::string message)
    : m_sMessage(message)
{
}

std::string UnavailableAction::WhatHappened()
{
    return m_sMessage;
}