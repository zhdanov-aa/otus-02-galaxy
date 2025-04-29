#ifndef INTERPRETCOMMAND_H
#define INTERPRETCOMMAND_H

#include <memory>
#include <ICommand.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class InterpretCommand : public ICommand
{
    json m_Message;

public:
    InterpretCommand(json message);

    void Execute() override;
};

using InterpretCommandPtr = std::shared_ptr<InterpretCommand>;

#endif // INTERPRETCOMMAND_H
