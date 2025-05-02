#include "Endpoint.h"
#include "InterpretCommand.h"
#include <nlohmann/json.hpp>
#include <RuntimeError.h>
#include <IoC.h>
#include <IOutputCommandStream.h>

using json = nlohmann::json;

Endpoint::Endpoint()
{
}

void Endpoint::HandleMessage(std::string message)
{
    try
    {
        json j = json::parse(message);

        std::string game_id;
        if (j.contains("game_id"))
        {
            game_id = j["game_id"].get<std::string>();
            IoC::Resolve<IOutputCommandStreamPtr>("Game.CommandStream.Output.Get", game_id)->Write(
                std::make_shared<InterpretCommand>(j)
                );
        }
        else
            throw new RuntimeError("Endpoint::HandleMessage(): <game_id> not found");
    }
    catch (const json::parse_error& e)
    {
        throw new RuntimeError(
            std::string("Endpoint::HandleMessage(): json::parse() exception: ") +
            e.what());
    }
}
