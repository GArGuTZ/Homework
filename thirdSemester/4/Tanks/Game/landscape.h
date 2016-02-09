#pragma once

#include <QGraphicsItem>
#include <QTime>
#include <QPainter>
#include <QtGlobal>

/** @brief Describes landscape */

class Landscape : public QGraphicsItem
{
public:
    /** @brief Generates landscape according to scene size */
    Landscape(unsigned int _sceneWidth, unsigned int _sceneHeight);
    Landscape(const Landscape& _land);
    ~Landscape();

    /** @brief Function for drawing */
    void paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget = 0);

    /** @brief Functons for detecting collisions */
    QRectF boundingRect() const;
    QPainterPath shape() const;

    QPoint getCoordinates(unsigned int _index);

    /** @brief Returns number of possible for movement flexures in surface */
    unsigned int getLength() const;

    /** @brief Functions for copy */
    QVector<QPoint> getSurface() const;
    QPainterPath getPath() const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;

    QVector<int> getX() const;
    QVector<int> getY() const;

    void setSurface(QVector<QPoint> _surface);

private:
    unsigned int width_;
    unsigned int height_;

    QVector<QPoint> surface_;

    /** @brief Path for painting and collisions */
    QPainterPath path_;

    unsigned int numOfFlexures_;

};
