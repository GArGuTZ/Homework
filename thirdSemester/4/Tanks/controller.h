#pragma once

#include <QObject>

/** @brief Base class for the KeyboardController and NetworkController, describes input of the tank */
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
