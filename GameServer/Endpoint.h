#ifndef ENDPOINT_H
#define ENDPOINT_H

#include <string>
#include <memory>

class Endpoint
{
public:
    Endpoint();

    void HandleMessage(std::string message);
};

using EndpointPtr = std::shared_ptr<Endpoint>;

#endif // ENDPOINT_H
