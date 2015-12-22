#pragma once
#include <iostream>

/**
 * @brief The Computer class
 * Imitate computer in network
 */

class Computer
{
public:
    /// @brief Create uninfected computer with 0 morbidity
    Computer();
    Computer(int probabilityOfInfection);

    /// @brief Infected Computers has 0 morbidity
    Computer(bool infectedOrNot);

    /// @brief Copy constructor
    Computer(const Computer &obj);
    Computer &operator =(const Computer &obj);
    bool operator ==(const Computer &second) const;
    bool operator !=(const Computer &second) const;
    ~Computer();
    int getProbability() const;
    bool isInfected() const;
    void infect();
    friend std::ostream &operator <<(std::ostream &stream, const Computer& komp);
private:
    int morbidityPercentage;
    bool Infection;
};
