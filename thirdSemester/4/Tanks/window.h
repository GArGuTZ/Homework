#pragma once

#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QMessageBox>
#include <QStatusBar>

#include "Input/controller.h"
#include "Game/gamecore.h"
#include "Game/landscape.h"
#include "Game/tank.h"
#include "Network/connectserverdialog.h"
#include "Network/networkclient.h"
#include "Network/networkserver.h"

class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QWidget* _parent = 0);

    bool initNetwork();

private slots:
    void connected();
    void disconnected();
    void gameOver(const QString& _string);

private:
    QWidget* parent_;

    Network *network_;

    const unsigned int width_ = 800;
    const unsigned int height_ = 600;
};
