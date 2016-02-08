#include "tank.h"

#include "landscape.h"
#include "gamecore.h"

unsigned int Tank::numberOfTanks_ = 0;

Tank::Tank(GameCore *_gamecore, Landscape *_land):
    gamecore_(_gamecore),
    land_(_land),
    currentDirection_(leftDirection),
    gunAngle_(0),
    currentGun_(standardGun)
{
    ++numberOfTanks_;
    numberOfTank_ = numberOfTanks_ % 2 + 1;

    gunPosition_.rx() = -35;
    gunPosition_.ry() = 0;

    if (numberOfTanks_ % 2)
    {
        currentVertex_ = land_->getLength() / 4;
        currentDirection_ = rightDirection;
        gunPosition_.rx() = 35;
    }
    else
    {
        currentVertex_ = 3 * land_->getLength() / 4;
    }

    position_ = land_->getCoordinates(currentVertex_);

    setPos(position_.x(), position_.y());
}

Tank::~Tank()
{
    --numberOfTanks_;
}

void Tank::paint(QPainter *_painter, const QStyleOptionGraphicsItem *_option, QWidget *_widget)
{
    if (numberOfTank_ % 2)
    {
        _painter->setBrush(QColor(0, 0, 0));
        _painter->setPen(QColor(0, 0, 0));
    }
    else
    {
        _painter->setBrush(QColor(255, 0, 0));
        _painter->setPen(QColor(255, 0, 0));
    }

    _painter->drawRect(-15, -10, 30, 20);
    _painter->drawLine(QPointF(0, 0), QPointF(gunPosition_.x(), gunPosition_.y()));
}

QRectF Tank::boundingRect() const
{
    return QRectF(-15, -10, 30, 20);
}

QPainterPath Tank::shape() const
{
    QPainterPath path;
    path.addRect(QRectF(boundingRect()));
    path.moveTo(0, 0);
    path.lineTo(gunPosition_.x(), gunPosition_.y());
    return path;
}

QPoint Tank::getPosition() const
{
    return position_;
}

QPointF Tank::getGunPosition() const
{
    QPointF barrelPosition;
    barrelPosition.rx() = position_.x() + gunPosition_.x();
    barrelPosition.ry() = position_.y() + gunPosition_.y();

    return barrelPosition;
}

double Tank::getAngle() const
{
    return gunAngle_;
}

void Tank::moveLeft()
{
    currentDirection_ = leftDirection;

    if (currentVertex_ == 0)
    {
        return;
    }

    --currentVertex_;
    position_ = land_->getCoordinates(currentVertex_);

    if (gunPosition_.x() > 0)
    {
        gunPosition_.rx() = -gunPosition_.x();
    }

    setPos(position_.x(), position_.y());
}

void Tank::moveRight()
{
    currentDirection_ = rightDirection;

    if (currentVertex_ == (land_->getLength() - 1))
    {
        return;
    }

    ++currentVertex_;
    position_ = land_->getCoordinates(currentVertex_);

    if (gunPosition_.x() < 0)
    {
        gunPosition_.rx() = -gunPosition_.x();
    }

    setPos(position_.x(), position_.y());
}

void Tank::upGun()
{
    if (gunAngle_ >= 90)
    {
        return;
    }

    gunAngle_ += 5;

    gunPosition_.rx() = 35*currentDirection_*cos(qDegreesToRadians(gunAngle_));
    gunPosition_.ry() = -35*sin(qDegreesToRadians(gunAngle_));
}

void Tank::downGun()
{
    if (gunAngle_ <= 0)
    {
        return;
    }

    gunAngle_ -= 5;

    gunPosition_.rx() = 35*currentDirection_*cos(qDegreesToRadians(gunAngle_));
    gunPosition_.ry() = -35*sin(qDegreesToRadians(gunAngle_));

}

void Tank::switchGun()
{
    if (currentGun_ == standardGun)
    {
        currentGun_ = bigGun;
    }
    else
    {
        currentGun_ = standardGun;
    }
}

void Tank::shoot()
{
    gamecore_->nextStep(currentGun_ == bigGun);
}

Gun Tank::getGun() const
{
    return currentGun_;
}

TankDirection Tank::getDirection() const
{
    return currentDirection_;
}

