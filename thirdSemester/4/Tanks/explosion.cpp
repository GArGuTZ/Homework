#include "explosion.h"

Explosion::Explosion(QPointF _position, double _radius):
    radius_(_radius)
{
    setPos(_position);
}

Explosion::~Explosion()
{
}

void Explosion::paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget)
{
    _painter->setBrush(QColor(128, 0, 128));
    _painter->setPen(QColor(64, 0, 128));
    _painter->drawEllipse(QPointF(0, 0) , radius_, radius_);

}

QRectF Explosion::boundingRect() const
{
    return QRectF(QPointF(-radius_, radius_), QPointF(radius_, -radius_));
}

QPainterPath Explosion::shape() const
{
    QPainterPath path;
    path.addEllipse(QPointF(0, 0) , radius_, radius_);
    return path;
}

