#pragma once

#include <QWidget>
#include <QtWidgets>
#include <QtNetwork>
#include <QNetworkConfigurationManager>
#include <QNetworkSession>
#include <QTcpServer>
#include <QTcpSocket>

#include "networkcore.h"
#include "Game/landscape.h"

/** @brief Describes a server */

class Server : public Network
{
    Q_OBJECT
public:
    explicit Server(QObject* _parent = nullptr);

    bool init();

    QString getPort() const;

    void sendLandscape(Landscape* _landscape);

private slots:
    void sessionOpened();
    void connectClient();

private:
    QTcpServer* tcpServer_;
};
