#pragma once

#include "shell.h"

/** @brief Class describes a shell with doubled radius */

class BigShell : public Shell
{
public:
    BigShell(QPointF _position, TankDirection _direction, const double _angle = 0);
    ~BigShell();

    /** @brief Creates explosion with bigger radius */
    Explosion* blast();
};

