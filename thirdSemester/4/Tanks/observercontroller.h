#pragma once

#include <QObject>

class Controller;
class Tank;
class GameCore;

class ObserverController : public QObject
{
    Q_OBJECT
public:
    explicit ObserverController(QObject* _parent, Tank* _tank);

signals:
    void emitInput(const QString& _message);

protected slots:
    void moveRightPressed();
    void moveLeftPressed();
    void gunUpPressed();
    void gunDownPressed();
    void shootPressed();
    void changeGunPressed();

private:
    Tank* tank_;

    /** @brief Need for updating viewport */
    GameCore* game_;
};
