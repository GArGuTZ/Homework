#include "bigshell.h"

BigShell::BigShell(QPointF _position, TankDirection _direction, const double _angle):
    Shell::Shell(_position, _direction, _angle)
{
    radius_ *= 2;
}

BigShell::~BigShell()
{
}

Explosion *BigShell::blast()
{
    if (!explosion_)
    {
        explosion_ = new Explosion(shellPosition_, radius_*1.5);
    }

    return explosion_;
}
