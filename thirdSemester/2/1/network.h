#pragma once

#include <QVector>
#include "computer.h"
#include "goodvirus.h"
#include "killervirus.h"
#include "standartvirus.h"

/**
 * @brief The Network class
 * Simulates the working of defined local network and concrete virus
 */

class Network
{
public:
    /// @brief Create network with vector of computers and adjacency matrix of them
    Network(const QVector<Computer> &computersList, bool **matrix);
    ~Network();

    /// @brief writes network status in console
    void currentStatus() const;
    int howManyComputers() const;
    int howManyInfected() const;

    /// @brief Try to infect, if possibly;
    void SimulationStep();
    /// @brief Setting first infected computer in !pure! network. If (_victim > numberOfComputers), infecting random computer
    void SetFirstVictim(unsigned int _victim);

    void setVirus(IVirus* _virus);

    const Computer& operator [](int i) const;
private:
    IVirus* virus_;
    QVector<Computer> listOfComputers;
    bool **adjacencyMatrix;
    unsigned int numberOfComputers;
    unsigned int numberOfVictims;

};
