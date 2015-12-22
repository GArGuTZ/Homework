#pragma once

#include "ivirus.h"

/**
 * @brief KillerVirus class
 * Infect any computer except already infected and computers with probability = 0
 */

class KillerVirus : public IVirus
{
public:
    KillerVirus();
    ~KillerVirus();
    int getContagiousness();
};

