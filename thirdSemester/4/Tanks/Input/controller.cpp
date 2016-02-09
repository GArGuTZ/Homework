#include "controller.h"

Controller::Controller(QObject* _parent) :
    QObject(_parent),
    pressed_(Qt::Key_unknown)
{
}
