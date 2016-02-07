#pragma once

#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QMessageBox>
#include <QStatusBar>

#include "controller.h"
#include "gamecore.h"
#include "landscape.h"
#include "tank.h"
#include "connectserverdialog.h"
#include "networkclient.h"
#include "networkserver.h"

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
