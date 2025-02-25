#include <ScopeHolder.h>
#include <ICommand.h>
#include <IScope.h>
#include <IocRegisterCommand.h>
#include <IocNewScopeCommand.h>
#include <IocSetScopeRelativeCommand.h>
#include <ScopeChangerAdapter.h>
#include <Resolver.h>
#include <functional>

ScopeHolder::ScopeHolder()
{
    m_pRootScope = std::make_shared<Scope>("root", nullptr);
    m_pCurrentScope = std::make_shared<InjectedScope>();
    m_pCurrentScope->Inject(m_pRootScope);

    m_pCurrentScope->setResolver("IoC.Register",
                      make_resolver(
                          std::function<ICommandPtr(const char *,IResolverPtr)>(
                              [this](const char *dep, IResolverPtr resolver)
                              {
                                  return std::static_pointer_cast<ICommand>(
                                      std::make_shared<IocRegisterCommand>(
                                          m_pCurrentScope,
                                          dep,
                                          resolver));
                              }
                              )
                          )
                      );

    m_pCurrentScope->setResolver("IoC.Scope.New",
                      make_resolver(
                          std::function<ICommandPtr(const char *)>(
                              [this](const char *scopeName)
                              {
                                  return std::static_pointer_cast<ICommand>(
                                      std::make_shared<IocNewScopeCommand>(m_pCurrentScope, scopeName)
                                      );
                              }
                              )
                          )
                      );

    m_pCurrentScope->setResolver("IoC.Scope.Current",
                                 make_resolver(
                                     std::function<ICommandPtr(const char *)>(
                                         [this](const char *scopeName)
                                         {
                                             return std::static_pointer_cast<ICommand>(
                                                 std::make_shared<IocSetScopeRelativeCommand>(
                                                     m_pCurrentScope,
                                                     std::make_shared<ScopeChangerAdapter>(m_pCurrentScope),
                                                     scopeName)
                                                 );
                                         }
                                         )
                                     )
                                 );
}

IResolverPtr ScopeHolder::getResolver(string dependecy)
{
    return m_pCurrentScope->getResolver(dependecy);
}
