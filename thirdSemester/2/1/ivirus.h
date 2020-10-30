#pragma once

#include <QVector>

/**
 * @brief IVirus class
 * Interface for the viruses
 */

class IVirus
{
public:
    IVirus();
    ~IVirus();

    virtual int getContagiousness();

    /** @brief Set vector with probabilities of infection, replaces qrand() in StandartVirus */
    virtual void setFakeRandomGenerator(QVector<unsigned int> _fake);

    /** @brief Return to qrand() */
    virtual void unsetFakeRandomGenerator();

protected:
    int contagiousness_;

    QVector<unsigned int> probabilities_;
    int currentThrow_;
};

