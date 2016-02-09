#pragma once

#include "controller.h"

class Network;
class Tank;

/** @brief Handles network input */

class NetworkController : public Controller
{
public:
    explicit NetworkController(Network* _network, Tank* _tank);

    /** @brief Translates messages and commands tank */
    void handle(const QString& _message);

private:
    Tank *tank_;
};
