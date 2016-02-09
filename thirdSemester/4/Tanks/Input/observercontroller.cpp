#include "observercontroller.h"

#include "controller.h"
#include "Game/tank.h"
#include "Game/gamecore.h"

ObserverController::ObserverController(QObject* _parent, Tank* _tank) :
    QObject(_parent),
    tank_(_tank)
{
    Controller* controller = _tank->getController();
    connect(controller, SIGNAL(gunDownPressed()), this, SLOT(gunDownPressed()));
    connect(controller, SIGNAL(gunUpPressed()), this, SLOT(gunUpPressed()));
    connect(controller, SIGNAL(moveRightPressed()), this, SLOT(moveRightPressed()));
    connect(controller, SIGNAL(moveLeftPressed()), this, SLOT(moveLeftPressed()));
    connect(controller, SIGNAL(changeGunPressed()), this, SLOT(changeGunPressed()));
    connect(controller, SIGNAL(shootPressed()), this, SLOT(shootPressed()));
}

void ObserverController::moveRightPressed()
{
    emit emitInput(QString("KR"));
}

void ObserverController::moveLeftPressed()
{
    emit emitInput(QString("KL"));
}

void ObserverController::gunUpPressed()
{
    emit emitInput(QString("KU"));
}

void ObserverController::gunDownPressed()
{
    emit emitInput(QString("KD"));
}

void ObserverController::shootPressed()
{
    emit emitInput(QString("KS"));
}

void ObserverController::changeGunPressed()
{
    emit emitInput(QString("KC"));
}
