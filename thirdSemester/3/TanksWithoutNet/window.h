#pragma once

#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QGridLayout>
#include "gamecore.h"

/** @brief Window class create client and server */

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget* _parent = 0);

private slots:
    void startSinglePlayer();

private:
    QPushButton* startButton_;
    QLabel* label_;
    QGridLayout* layout_;

    QWidget* parent_;

    GameCore* core_;

    const unsigned int width_ = 800;
    const unsigned int height_ = 600;
};

