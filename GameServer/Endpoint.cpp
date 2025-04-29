#include "Endpoint.h"
#include "InterpretCommand.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

Endpoint::Endpoint()
{
}

void Endpoint::HandleMessage(std::string message)
{
    json j = json::parse(message);
}
