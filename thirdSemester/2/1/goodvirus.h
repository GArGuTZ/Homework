#pragma once

#include "ivirus.h"

/**
 * @brief GoodVirus class
 * Can't infect
 */

class GoodVirus : public IVirus
{
public:
    GoodVirus();
    ~GoodVirus();

    int getContagiousness();
};

