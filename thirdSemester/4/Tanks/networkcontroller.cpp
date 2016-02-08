#include "networkcontroller.h"

#include "networkcore.h"
#include "tank.h"
#include "gamecore.h"

NetworkController::NetworkController(Network* _network, Tank* _tank) :
    Controller(_network),
    tank_(_tank)
{
    tank_->setController(this);
}

void NetworkController::handle(const QString& _message)
{
    if (_message.at(1) == QChar('R'))
    {
        emit moveRightPressed();
    }
    else if (_message.at(1) == QChar('L'))
    {
        emit moveLeftPressed();
    }
    else if (_message.at(1) == QChar('U'))
    {
        emit gunUpPressed();
    }
    else if (_message.at(1) == QChar('D'))
    {
        emit gunDownPressed();
    }
    else if (_message.at(1) == QChar('S'))
    {
        emit shootPressed();
    }
    else if (_message.at(1) == QChar('C'))
    {
        emit changeGunPressed();
    }

    tank_->getGame()->viewport()->update();
}
