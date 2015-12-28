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
    Computer(int _probabilityOfInfection);

    /// @brief Infected Computers has 0 morbidity
    Computer(bool _infectedOrNot);

    /// @brief Copy constructor
    Computer(const Computer& _obj);

    ~Computer();


    int getProbability() const;
    bool isInfected() const;
    void infect();


    Computer &operator =(const Computer& _obj);
    bool operator ==(const Computer& _second) const;
    bool operator !=(const Computer& _second) const;

    friend std::ostream &operator <<(std::ostream& _stream, const Computer& _computer);

private:
    int morbidityPercentage_;
    bool infection_;
};
