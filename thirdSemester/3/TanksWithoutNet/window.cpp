#include "window.h"

Window::Window(QWidget *_parent):
    QWidget(_parent),
    startButton_(new QPushButton("Start Singleplayer")),
    label_(new QLabel("Main Menu")),
    layout_(nullptr),
    parent_(_parent),
    core_(nullptr)
{
    setFixedSize(width_, height_);

    layout_ = new QGridLayout;
    layout_->addWidget(label_, 0, 0, Qt::AlignCenter);
    layout_->addWidget(startButton_, 1, 0, Qt::AlignBaseline);
    setLayout(layout_);

    connect(startButton_, SIGNAL(clicked()), this, SLOT(startSinglePlayer()));
}

void Window::startSinglePlayer()
{
    core_ = new GameCore(width_, height_, parent_);
    core_->show();
}

