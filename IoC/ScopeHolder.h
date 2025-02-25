#ifndef SCOPEHOLDER_H
#define SCOPEHOLDER_H

#include <Scope.h>
#include <InjectedScope.h>
#include <IResolver.h>

class ScopeHolder
{
    IScopePtr m_pRootScope;
    InjectedScopePtr m_pCurrentScope;

public:
    ScopeHolder();

    IResolverPtr getResolver(string dependecy);
};

#endif
