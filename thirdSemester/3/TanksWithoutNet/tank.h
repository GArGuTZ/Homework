#pragma once

#include <QtMath>
#include <QGraphicsItem>

class Landscape;
class GameCore;

/** @brief Enum for current gun */
enum Gun
{
    standardGun,
    bigGun
};

/** @brief Enum for direction of movement */
enum TankDirection
{
    leftDirection = -1,
    rightDirection = 1
};

class Tank : public QGraphicsItem
{
public:
    /** @brief Creates tank in random place of appropriate landscape */
    Tank(GameCore* _gamecore, Landscape* _land);
    ~Tank();

    /** @brief Function for drawing */
    void paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget = 0);

    /** @brief Functions for detecting collisions */
    QRectF boundingRect() const;
    QPainterPath shape() const;

    QPoint getPosition() const;

    /** @brief Returns a coordinates of the end of the barrel */
    QPointF getGunPosition() const;

    /** @brief Return the declination angle of the gun */
    double getAngle() const;

    /** @brief Functions for moving on the surface */
    void moveLeft();
    void moveRight();

    /** @brief Functions for changing the declination angle of the gun */
    void upGun();
    void downGun();

    /** @brief Switches gun */
    void switchGun();

    void shoot();

    /** @brief Returns type of the gun */
    Gun getGun() const;

    /** @brief Returns direction of the movement */
    TankDirection getDirection() const;

private:
    /** @brief This two parameters only for placing and colouration */
    static unsigned int numberOfTanks_;
    unsigned int numberOfTank_;

    GameCore* gamecore_;

    Landscape* land_;

    /** @brief Position for painting on scene */
    QPoint position_;

    /** @brief Position for movement on the flexures of the surface */
    unsigned int currentVertex_;

    TankDirection currentDirection_;

    double gunAngle_;

    /** @brief Position for painting the gun */
    QPointF gunPosition_;

    Gun currentGun_;
};
