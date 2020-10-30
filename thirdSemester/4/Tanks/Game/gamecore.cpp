#include "gamecore.h"

#include "tank.h"
#include "landscape.h"
#include "Input/keyboardcontroller.h"

GameCore::GameCore(unsigned int _width, unsigned int _height, QWidget* _parent):
    QGraphicsView(_parent),
    network_(nullptr),
    scene_(nullptr),
    loop_(new QEventLoop(this)),
    timer_(nullptr),
    landscape_(nullptr),
    firstTank_(nullptr),
    secondTank_(nullptr),
    isFirstTankTurn_(false),
    currentTank_(nullptr),
    victim_(nullptr),
    shell_(nullptr),
    shellLaunched_(false),
    isServer_(false),
    windowWidth_(_width),
    windowHeight_(_height)
{
    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &GameCore::frame);
    connect(this, SIGNAL(gameOver(QString)), this, SLOT(whenGameOver()));

    scene_ = new QGraphicsScene(this);
    scene_->setSceneRect(0, 0, windowWidth_, windowHeight_);
}

void GameCore::setLandscape(Landscape* _landscape)
{
    Client* client = static_cast<Client *>(network_);
    disconnect(client, SIGNAL(gotLandscape(Landscape*)), this, SLOT(setLandscape(Landscape*)));
    landscape_ = _landscape;
    loop_->exit();
}

void GameCore::startGame(Network *_network)
{
    network_ = _network;
    setScene(scene_);

    KeyboardController* controller = new KeyboardController(this);

    if (dynamic_cast<Server *>(_network))
    {
        isServer_ = true;

        Server* server = static_cast<Server *>(_network);
        landscape_ = new Landscape(windowWidth_, windowHeight_);
        server->sendLandscape(landscape_);

        firstTank_ = new Tank(this, landscape_, this);
        secondTank_ = new Tank(this, landscape_, this);
        isFirstTankTurn_ = true;
        currentTank_ = firstTank_;
        victim_ = secondTank_;
    }
    else
    {
        Client* client = static_cast<Client *>(_network);
        connect(client, SIGNAL(gotLandscape(Landscape *)), this, SLOT(setLandscape(Landscape*)));
        loop_->exec();

        secondTank_ = new Tank(this, landscape_, this);
        firstTank_ = new Tank(this, landscape_, this);
        isFirstTankTurn_ = false;
        currentTank_ = secondTank_;
        victim_ = firstTank_;
    }

    scene_->addItem(landscape_);
    scene_->addItem(firstTank_);
    scene_->addItem(secondTank_);

    firstTank_->setController(controller);
    _network->initController(secondTank_);
    network_->observeController(firstTank_);

    if (isFirstTankTurn_)
    {
        secondTank_->getController()->blockSignals(true);
    }
    else
    {
        firstTank_->getController()->blockSignals(true);
    }
}

void GameCore::nextStep(bool _isBigGun)
{
    shellLaunched_ = true;

    if (_isBigGun)
    {
        shell_ = new BigShell(currentTank_->getGunPosition(), currentTank_->getDirection(), currentTank_->getAngle());
    }
    else
    {
        shell_ = new Shell(currentTank_->getGunPosition(), currentTank_->getDirection(), currentTank_->getAngle());
    }

    scene_->addItem(shell_);

    firstTank_->getController()->blockSignals(true);
    secondTank_->getController()->blockSignals(true);

    if (isFirstTankTurn_)
    {
        isFirstTankTurn_ = false;
    }
    else
    {
        isFirstTankTurn_ = true;
    }

    timer_->start(20);
}

void GameCore::frame()
{
    if (shell_->collidesWithItem(victim_))
    {
        timer_->stop();
        delete shell_;
        shellLaunched_ = false;

        if (isFirstTankTurn_ ^ isServer_)
        {
            emit gameOver("First Tank Wins!");
        }
        else
        {
            emit gameOver("Second Tank Wins!");
        }

        qDebug("Collide with victim");
    }
    else if (shell_->collidesWithItem(landscape_))
    {
        timer_->stop();

        scene_->addItem(shell_->blast());

        if (shell_->blast()->collidesWithItem(victim_))
        {
            if (isFirstTankTurn_ ^ isServer_)
            {
                emit gameOver("First Tank Wins!");
            }
            else
            {
                emit gameOver("Second Tank Wins!");
            }

            qDebug("Explode");
        }

        delete shell_;
        shellLaunched_ = false;

        if (isFirstTankTurn_)
        {
            firstTank_->getController()->blockSignals(false);
        }
        else
        {
            secondTank_->getController()->blockSignals(false);
        }

        std::swap(currentTank_, victim_);

        qDebug("Collide with surface");
    }
    else if (scene_->sceneRect().contains(shell_->getPosition()))
    {
        shell_->frame();
    }
    else
    {
        timer_->stop();
        delete shell_;
        shellLaunched_ = false;

        if (isFirstTankTurn_)
        {
            firstTank_->getController()->blockSignals(false);
        }
        else
        {
            secondTank_->getController()->blockSignals(false);
        }

        std::swap(currentTank_, victim_);

        qDebug("Out of scene");
    }

    viewport()->update();
}

void GameCore::whenGameOver()
{
    deleteLater();
}

