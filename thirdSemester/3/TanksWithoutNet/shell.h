#pragma once

#include <QGraphicsItem>
#include <QPainter>
#include <QtMath>
#include "tank.h"
#include "explosion.h"

/** @brief Shell class describes a projectile and control his flight */

class Shell : public QGraphicsItem
{
public:
    Shell(QPointF _position, TankDirection _direction, const double _angle = 0);
    ~Shell();

    /** @brief Function for drawing */
    void paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget = 0);

    /** @brief Functions for detecting collisions */
    QRectF boundingRect() const;
    QPainterPath shape() const;

    QPointF getPosition() const;

    /** @brief Updates coordinates of projectile */
    void frame();

    /** @brief Creates explosion */
    virtual Explosion* blast();

protected:
    QPointF shellPosition_;
    double startAngle_;

    /// Size of shell
    double radius_;

    double graviAcceleration_;
    int speed_;

    double timeOfFlight_;

    Explosion* explosion_;

    TankDirection shellDirection_;
};

