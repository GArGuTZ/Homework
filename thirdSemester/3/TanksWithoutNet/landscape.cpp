#include "landscape.h"

Landscape::Landscape(unsigned int _sceneWidth, unsigned int _sceneHeight)
{
    qsrand(QTime::currentTime().msec());

    surface_ = {QPoint(0, _sceneHeight / 2)};

    int cursor = 0;
    int heightOffset = _sceneHeight / 2;

    while (cursor < _sceneWidth)
    {
        int sign = qrand() % 2;
        int increase = qrand() % 10;

        if (sign && (heightOffset < ((3*_sceneHeight) / 4)))
        {
            heightOffset += increase;
            cursor += 5;
        }
        else if (heightOffset > _sceneHeight / 4)
        {
            heightOffset -= increase;
            cursor += 5;
        }

        surface_.append(QPoint(cursor, heightOffset));
    }

    numOfFlexures_ = surface_.length();

    surface_.append(QPoint(_sceneWidth, _sceneHeight));
    surface_.append(QPoint(0, _sceneHeight));
    surface_.append(QPoint(0, _sceneHeight / 2));

    path_.moveTo(0, _sceneHeight / 2);

    for (unsigned int i = 1; i < numOfFlexures_ + 3; ++i)
    {
        path_.lineTo(surface_[i]);
    }
}

Landscape::~Landscape()
{
    surface_.clear();
}

QRectF Landscape::boundingRect() const
{
    return QRectF(QPoint(0, 0), QPoint(600, 480));
}

QPainterPath Landscape::shape() const
{
    return path_;
}

QPoint Landscape::getCoordinates(unsigned int _index)
{
    return surface_[_index];
}

unsigned int Landscape::getLength()
{
    return numOfFlexures_;
}

void Landscape::paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget)
{
    _painter->setBrush(Qt::green);
    _painter->setPen(Qt::green);
    _painter->drawPath(path_);
}

