#pragma once

#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>

#include "bigshell.h"
#include "explosion.h"
#include "networkclient.h"
#include "networkserver.h"

class Tank;
class Landscape;
class Controller;

/** @brief GameCore class controls process of game */

class GameCore : public QGraphicsView
{
    Q_OBJECT
public:
    /** @brief Creates scene according to window size, creates appropriate landscape and places tanks on them */
    GameCore(unsigned int _width, unsigned int _height, QWidget* _parent = 0);
    ~GameCore();

    void startGame(Network* _network);

    /** @brief Creates message box and close the game */
    void checkWinner(Tank* _winner);

signals:

    /** @brief Emitted in the end of each frame */
    void updated();

    /** @brief Emitted when the winner detected */
    void gameOver(const QString& _string);

public slots:
    /** @brief Launch shell and start timer */
    void nextStep(bool _isBigGun);

    void setLandscape(Landscape* _landscape);

    /** @brief Updates game, checks collisions */
    void frame();

    void whenGameOver();

private:
    Network* network_;

    QMessageBox* winnerMessage_;

    QGraphicsScene* scene_;
    QEventLoop* loop_;

    QTimer* timer_;

    Landscape* landscape_;

    Tank* firstTank_;
    Tank* secondTank_;

    bool isFirstTankTurn_;

    Tank* currentTank_;
    Tank* victim_;

    Shell* shell_;
    bool shellLaunched_;

    bool isServer_;

    unsigned int windowWidth_;
    unsigned int windowHeight_;
};

