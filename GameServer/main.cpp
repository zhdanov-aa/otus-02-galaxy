#include <IoC.h>
#include <iostream>
#include <Endpoint.h>

int main(int argc, char *argv[])
{
    std::cout << "Game server started." << std::endl;

    Endpoint e;

    std::string message = R"(
    {
        "game_id": "256",
        "age": 25,
        "hobbies": ["чтение", "плавание", "программирование"]
    }
    )";

    try
    {
        e.HandleMessage(message);
    }
    catch(IException *exception)
    {
        std::cout << "Exception: " << exception->WhatHappened() << std::endl;
        delete exception;
    }

    std::cout << "Game server stopped." << std::endl;
    return 0;
}
