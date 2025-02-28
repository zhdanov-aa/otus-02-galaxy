#include <IocNewScopeCommand.h>
#include <Scope.h>
#include <RuntimeError.h>

IocNewScopeCommand::IocNewScopeCommand(IScopePtr pCurrentScope, string name)
    : m_pCurrentScope(pCurrentScope), m_sName(name)
{
}

void IocNewScopeCommand::Execute()
{
    if (m_pCurrentScope == nullptr)
        throw new RuntimeError("IocNewScopeCommand: m_pCurrentScope is nullptr");

    m_pCurrentScope->AddChild( std::make_shared<Scope>(m_sName, m_pCurrentScope) );
}
