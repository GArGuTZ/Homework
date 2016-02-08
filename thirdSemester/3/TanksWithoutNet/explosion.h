#pragma once

#include <QGraphicsItem>
#include <QPainter>

/** @brief Explosion describe an explosion */

class Explosion : public QGraphicsItem
{
public:
    Explosion(QPointF _position, double _radius);
    ~Explosion();

    /** @brief Function for drawing */
    void paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget = 0);

    /** @brief Functions for detecting collisions */
    QRectF boundingRect() const;
    QPainterPath shape() const;

protected:
    double radius_;
};

