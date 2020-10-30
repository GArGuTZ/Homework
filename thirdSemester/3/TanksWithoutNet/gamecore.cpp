#include "gamecore.h"

GameCore::GameCore(unsigned int _width, unsigned int _height, QWidget* _parent):
    QGraphicsView(_parent),
    winnerMessage_(nullptr),
    scene_(nullptr),
    timer_(nullptr),
    landscape_(nullptr),
    firstTank_(nullptr),
    secondTank_(nullptr),
    currentTank_(nullptr),
    victim_(nullptr),
    shell_(nullptr),
    shellLaunched_(false),
    windowWidth_(_width),
    windowHeight_(_height)
{
    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &GameCore::frame);

    landscape_ = new Landscape(windowWidth_, windowHeight_);

    firstTank_ = new Tank(this, landscape_);
    secondTank_ = new Tank(this, landscape_);

    currentTank_ = firstTank_;
    victim_ = secondTank_;

    scene_ = new QGraphicsScene(this);
    scene_->setSceneRect(0, 0, windowWidth_, windowHeight_);
    setScene(scene_);
    scene_->addItem(landscape_);
    scene_->addItem(firstTank_);
    scene_->addItem(secondTank_);
}

GameCore::~GameCore()
{
    if (scene_)
    {
        delete scene_;
    }

    if (landscape_)
    {
        delete landscape_;
    }

    if (firstTank_)
    {
        delete firstTank_;
    }

    if (secondTank_)
    {
        delete secondTank_;
    }

    if (currentTank_)
    {
        delete currentTank_;
    }

    if (victim_)
    {
        delete victim_;
    }
}

void GameCore::keyPressEvent(QKeyEvent *_event)
{
    if (_event->key() == Qt::Key_Space && !shellLaunched_)
    {
        currentTank_->shoot();
    }

    if (_event->key() == Qt::Key_G && !shellLaunched_)
    {
        currentTank_->switchGun();
    }

    if (_event->key() == Qt::Key_Left && !shellLaunched_)
    {
        currentTank_->moveLeft();
    }

    if (_event->key() == Qt::Key_Right && !shellLaunched_)
    {
        currentTank_->moveRight();
    }

    if (_event->key() == Qt::Key_Up && !shellLaunched_)
    {
        currentTank_->upGun();
    }

    if (_event->key() == Qt::Key_Down && !shellLaunched_)
    {
        currentTank_->downGun();
    }

    viewport()->update();

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
    timer_->start(20);
}

void GameCore::checkWinner(Tank* _winner)
{
    winnerMessage_ = new QMessageBox;

    if (_winner == firstTank_)
    {
        winnerMessage_->setText("First Tank Wins!");
    }
    else if (_winner == secondTank_)
    {
        winnerMessage_->setText("Second Tank Wins!");
    }

    winnerMessage_->setIcon(QMessageBox::Warning);
    winnerMessage_->exec();

    close();
}

void GameCore::frame()
{
    if (shell_->collidesWithItem(victim_))
    {
        timer_->stop();
        delete shell_;
        shellLaunched_ = false;
        checkWinner(currentTank_);
        qDebug("Collide with victim");
    }
    else if (shell_->collidesWithItem(landscape_))
    {
        timer_->stop();

        scene_->addItem(shell_->blast());

        if (shell_->blast()->collidesWithItem(victim_))
        {
            checkWinner(currentTank_);
            qDebug("Explode");
        }

        delete shell_;
        shellLaunched_ = false;
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
        std::swap(currentTank_, victim_);
        qDebug("Out of scene");
    }

    viewport()->update();
}

