#pragma once

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
    /** @brief Create network with vector of computers and adjacency matrix of them */
    Network(const QVector<Computer> &_computersList, bool **_matrix);
    ~Network();

    /** @brief writes network status in console */
    void currentStatus() const;
    int howManyComputers() const;
    int howManyInfected() const;

    /** @brief Try to infect, if possibly */
    void simulationStep();

    /** @brief Setting first infected computer in !pure! network. If (_victim > numberOfComputers), infecting random computer */
    void setFirstVictim(unsigned int _victim);

    /** @brief Default virus - StandartVirus - is random */
    void setVirus(IVirus* _virus);

    /** @brief Set vector with probabilities of infection, replaces qrand() in StandartVirus */
    void setFakeRandomGenerator(QVector<unsigned int> _fake);

    /** @brief Return to qrand() */
    void unsetFakeRandomGenerator();

    const Computer& operator [](int _i) const;

private:
    IVirus* virus_;

    QVector<Computer> listOfComputers_;
    bool **adjacencyMatrix_;
    unsigned int numberOfComputers_;
    unsigned int numberOfVictims_;

};
