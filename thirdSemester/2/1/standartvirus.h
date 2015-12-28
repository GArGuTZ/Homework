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
};

