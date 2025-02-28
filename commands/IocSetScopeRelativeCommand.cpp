#include <IocSetScopeRelativeCommand.h>
#include <RuntimeError.h>

IocSetScopeRelativeCommand::IocSetScopeRelativeCommand(IScopePtr current, IScopeChangerPtr changer, string targetScope)
    : m_pCurrent(current), m_pChanger(changer), m_sTargetScope(targetScope)
{
}

void IocSetScopeRelativeCommand::Execute()
{
    auto scope = m_pCurrent->FindChild(m_sTargetScope);

    if (scope != nullptr)
    {
        m_pChanger->Change(scope);
    }
    else
        throw new RuntimeError("IocSetScopeRelativeCommand::Execute(): wrong scope name");
}
