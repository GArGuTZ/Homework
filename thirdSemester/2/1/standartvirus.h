#pragma once

#include <QtGlobal>
#include "ivirus.h"

/**
 * @brief StandartVirus class
 * Infects randomly
 */

class StandartVirus : public IVirus
{
public:
    StandartVirus();
    ~StandartVirus();

    int getContagiousness();

    /** @brief Set vector with probabilities of infection, replaces qrand() */
    void setFakeRandomGenerator(QVector<unsigned int> _fake);

    /** @brief Return to qrand() */
    void unsetFakeRandomGenerator();
};

