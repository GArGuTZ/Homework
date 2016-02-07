#include "shell.h"

Shell::Shell(QPointF _position, TankDirection _direction, const double _angle):
    shellPosition_(_position),
    startAngle_(_angle),
    radius_(4),
    graviAcceleration_(9.8),
    speed_(10),
    timeOfFlight_(0),
    explosion_(nullptr),
    shellDirection_(_direction)
{
    setPos(shellPosition_);
}

Shell::~Shell()
{
    if(explosion_)
    {
        delete explosion_;
    }
}

void Shell::paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget)
{
    _painter->setBrush(Qt::red);
    _painter->setPen(Qt::red);
    _painter->drawEllipse(QPointF(0, 0) , radius_, radius_);
}

QRectF Shell::boundingRect() const
{
    return QRectF(QPoint(-radius_, radius_), QPoint(radius_, -radius_));
}

QPainterPath Shell::shape() const
{
    QPainterPath path;
    path.addEllipse(QPoint(0, 0) , radius_, radius_);
    return path;
}

QPointF Shell::getPosition() const
{
    return shellPosition_;
}

void Shell::frame()
{
    timeOfFlight_ += 0.05;
    shellPosition_.rx() = shellPosition_.x() + shellDirection_*speed_*timeOfFlight_*cos(qDegreesToRadians(startAngle_));
    shellPosition_.ry() = shellPosition_.y() - speed_*timeOfFlight_*sin(qDegreesToRadians(startAngle_)) + (graviAcceleration_*timeOfFlight_*timeOfFlight_)/2;
    setPos(shellPosition_.x(), shellPosition_.y());


}

Explosion* Shell::blast()
{
    if(!explosion_)
    {
        explosion_ = new Explosion(shellPosition_, radius_);
    }

    return explosion_;
}

