#pragma once

#include "controller.h"

class Network;
class Tank;

/** @brief The NetworkInputManager class handles the commands from the network. */
class NetworkController : public Controller
{
public:
    explicit NetworkController(Network* _parent, Tank* _subject);

    /** @brief translates messages and invokes the commands. */
    void handle(const QString& _message);

private:
    Tank *subject_;
};
