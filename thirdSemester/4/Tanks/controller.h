#pragma once

#include <QObject>

/** @brief The InputManager class is used by the Cannon class to get input. */
class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject* _parent = nullptr);

signals:
    void moveRightPressed();
    void moveLeftPressed();
    void gunUpPressed();
    void gunDownPressed();
    void shootPressed();
    void changeGunPressed();

protected:
    Qt::Key pressed_;
};
