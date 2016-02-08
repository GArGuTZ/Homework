#include "keyboardcontroller.h"

#include <QKeyEvent>
#include <QGraphicsView>

#include "gamecore.h"

KeyboardController::KeyboardController(QObject* _parent) :
    Controller(_parent)
{
    _parent->installEventFilter(this);
}

bool KeyboardController::eventFilter(QObject* object, QEvent* event)
{
    if (object == parent())
    {
        if (event->type() == QEvent::KeyPress)
        {
            if (pressed_ != Qt::Key_unknown)
            {
                return false;
            }

            QKeyEvent* keyEvent = static_cast<QKeyEvent *>(event);

            if (keyEvent->isAutoRepeat())
            {
                return false;
            }

            if (keyEvent->key() == Qt::Key_Right)
            {
                qDebug("Right");
                pressed_ = Qt::Key_Right;
                emit moveRightPressed();
            }
            else if (keyEvent->key() == Qt::Key_Left)
            {
                qDebug("Left");
                pressed_ = Qt::Key_Left;
                emit moveLeftPressed();
            }
            else if (keyEvent->key() == Qt::Key_Up)
            {
                qDebug("Up");
                pressed_ = Qt::Key_Up;
                emit gunUpPressed();
            }
            else if (keyEvent->key() == Qt::Key_Down)
            {
                qDebug("Down");
                pressed_ = Qt::Key_Down;
                emit gunDownPressed();
            }
            else if (keyEvent->key() == Qt::Key_Space)
            {
                qDebug("Space");
                pressed_ = Qt::Key_Space;
                emit shootPressed();
            }
            else if (keyEvent->key() == Qt::Key_G)
            {
                qDebug("G");
                pressed_ = Qt::Key_G;
                emit changeGunPressed();
            }

            return true;
        }
        else if (event->type() == QEvent::KeyRelease)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent *>(event);
            if (keyEvent->isAutoRepeat())
            {
                return false;
            }
            if (pressed_ == keyEvent->key())
            {
                qDebug("Release");
                pressed_ = Qt::Key_unknown;
            }
            return true;
        }
        else
        {
            return false;
        }

    }

    QObject::eventFilter(object, event);
}
