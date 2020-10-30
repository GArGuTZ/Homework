#pragma once

#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>

#include "tank.h"
#include "landscape.h"
#include "bigshell.h"
#include "explosion.h"

/** @brief GameCore class controls process of game */

class GameCore : public QGraphicsView
{
    Q_OBJECT
public:
    /** @brief Creates scene according to window size, creates appropriate landscape and places tanks on them */
    GameCore(unsigned int _width, unsigned int _height, QWidget* _parent = 0);
    ~GameCore();

    /** @brief Handle input from keyboard */
    void keyPressEvent(QKeyEvent* _event);

    /** @brief Launch shell and start timer */
    void nextStep(bool _isBigGun);

    /** @brief Creates message box and close the game */
    void checkWinner(Tank* _winner);

private:
    QMessageBox* winnerMessage_;

    QGraphicsScene* scene_;

    QTimer* timer_;

    Landscape* landscape_;

    Tank* firstTank_;
    Tank* secondTank_;
    Tank* currentTank_;
    Tank* victim_;

    Shell* shell_;
    bool shellLaunched_;

    unsigned int windowWidth_;
    unsigned int windowHeight_;

private slots:
    /** @brief Updates game, checks collisions */
    void frame();
};

