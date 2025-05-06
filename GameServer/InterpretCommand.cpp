#include <InterpretCommand.h>
#include <IoC.h>
#include <IGameObject.h>
#include <string>

IGameObjectPtr InterpretCommand::FindObject()
{
    IGameObjectPtr obj;

    if (m_Message.contains("object_id"))
    {
        obj = IoC::Resolve<IGameObjectPtr>(
            "Game.Objects.Get",
            m_Message["object_id"].get<std::string>());

        if (obj == nullptr)
            throw new RuntimeError(
                std::string("Endpoint::HandleMessage(): game object <") +
                m_Message["object_id"].get<std::string>() +
                std::string("> not found"));
    }
    else
        throw new RuntimeError("Endpoint::HandleMessage(): message don`t contains <object_id> property");

    return obj;
}

InterpretCommand::InterpretCommand(json message)
    :m_Message(message)
{
}


void InterpretCommand::Execute()
{
    std::string cmd;
    auto obj = FindObject();

    if (m_Message.contains("command_id"))
        cmd = m_Message["command_id"].get<std::string>();
    else
        throw new RuntimeError("Endpoint::HandleMessage(): message don`t contains <command_id> property");

    IoC::Resolve<ICommandPtr>(
        std::string("Game.Commands.") + cmd + std::string(".Get"),
        obj,
        m_Message)->Execute();
}
