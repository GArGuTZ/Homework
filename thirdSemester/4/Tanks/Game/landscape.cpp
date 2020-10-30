#include "landscape.h"

Landscape::Landscape(unsigned int _sceneWidth, unsigned int _sceneHeight):
    width_(_sceneWidth),
    height_(_sceneHeight)
{
    qsrand(QTime::currentTime().msec());

    surface_ = {QPoint(0, height_ / 2)};

    int cursor = 0;
    int heightOffset = height_ / 2;

    while (cursor < width_)
    {
        int sign = qrand() % 2;
        int increase = qrand() % 10;

        if (sign && (heightOffset < ((3*height_) / 4)))
        {
            heightOffset += increase;
            cursor += 5;
        }
        else if (heightOffset > height_ / 4)
        {
            heightOffset -= increase;
            cursor += 5;
        }

        surface_.append(QPoint(cursor, heightOffset));
    }

    numOfFlexures_ = surface_.length();

    surface_.append(QPoint(width_, height_));
    surface_.append(QPoint(0, height_));
    surface_.append(QPoint(0, height_ / 2));

    path_.moveTo(0, height_ / 2);

    for (unsigned int i = 1; i < numOfFlexures_ + 3; ++i)
    {
        path_.lineTo(surface_[i]);
    }
}

Landscape::Landscape(const Landscape& _land)
{
    if (_land.getLength() < 1)
    {
        return;
    }

    width_ = _land.getWidth();
    height_ = _land.getHeight();
    surface_ = _land.getSurface();
    path_ = _land.getPath();
    numOfFlexures_ = _land.getLength();
}

Landscape::~Landscape()
{
    surface_.clear();
}

QRectF Landscape::boundingRect() const
{
    return QRectF(QPoint(0, 0), QPoint(800, 600));
}

QPainterPath Landscape::shape() const
{
    return path_;
}

QPoint Landscape::getCoordinates(unsigned int _index)
{
    return surface_[_index];
}

unsigned int Landscape::getLength() const
{
    return numOfFlexures_;
}

QVector<QPoint> Landscape::getSurface() const
{
    return surface_;
}

QPainterPath Landscape::getPath() const
{
    return path_;
}

unsigned int Landscape::getWidth() const
{
    return width_;
}

unsigned int Landscape::getHeight() const
{
    return height_;
}

QVector<int> Landscape::getX() const
{
    QVector<int> xCoordinates(numOfFlexures_ + 3);

    for (int i = 0; i < numOfFlexures_ + 3; ++i)
    {
        xCoordinates[i] = surface_[i].x();
    }

    return xCoordinates;
}

QVector<int> Landscape::getY() const
{
    QVector<int> yCoordinates(numOfFlexures_ + 3);

    for (int i = 0; i < numOfFlexures_ + 3; ++i)
    {
        yCoordinates[i] = surface_[i].y();
    }

    return yCoordinates;
}

void Landscape::setSurface(QVector<QPoint> _surface)
{
    surface_ = _surface;
    numOfFlexures_ = surface_.length() - 3;
    path_ = QPainterPath();

    path_.moveTo(0, height_ / 2);

    for (unsigned int i = 1; i < numOfFlexures_ + 3; ++i)
    {
        path_.lineTo(surface_[i]);
    }
}

void Landscape::paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget)
{
    _painter->setBrush(Qt::green);
    _painter->setPen(Qt::green);
    _painter->drawPath(path_);
}

