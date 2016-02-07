#include "observercontroller.h"

#include "controller.h"
#include "tank.h"
#include "gamecore.h"

ObserverController::ObserverController(QObject* _parent, Tank* _subject) :
    QObject(_parent),
    subject_(_subject),
    game_(subject_->getGame())
{
    Controller* controller = _subject->getController();
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
    game_->viewport()->update();
}

void ObserverController::moveLeftPressed()
{
    emit emitInput(QString("KL"));
    game_->viewport()->update();
}

void ObserverController::gunUpPressed()
{
    emit emitInput(QString("KU"));
    game_->viewport()->update();
}

void ObserverController::gunDownPressed()
{
    emit emitInput(QString("KD"));
    game_->viewport()->update();
}

void ObserverController::shootPressed()
{
    emit emitInput(QString("KS"));
    game_->viewport()->update();
}

void ObserverController::changeGunPressed()
{
    emit emitInput(QString("KC"));
    game_->viewport()->update();
}
