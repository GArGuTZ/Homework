#include "networkserver.h"

Server::Server(QObject *_parent) :
    Network(_parent),
    tcpServer_(nullptr)
{
}

bool Server::init()
{
    QNetworkConfigurationManager manager;

    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        networkSession_ = new QNetworkSession(manager.defaultConfiguration(), this);
        connect(networkSession_, SIGNAL(opened()), this, SLOT(sessionOpened()));
        networkSession_->open();
    }
    else
    {
        sessionOpened();
    }

    if (!tcpServer_)
    {
        return false;
    }

    connect(tcpServer_, SIGNAL(newConnection()), this, SLOT(connectClient()));
    return true;
}

QString Server::getPort() const
{
    if (tcpServer_ && tcpServer_->isListening())
    {
        return QString::number(tcpServer_->serverPort());
    }
    else
    {
        return QString();
    }
}

void Server::sendLandscape(Landscape *_landscape)
{
    QVector<int> fieldX = _landscape->getX();
    QVector<int> fieldY = _landscape->getY();
    int length = _landscape->getLength() + 3;

    QString message = "L";
    message += QString::number(length);

    const char* x = new char(length);

    qDebug(x);

    for (int i = 0; i < length; ++i)
    {
        message += " " + QString::number(fieldX[i]);
        message += " " + QString::number(fieldY[i]);
    }

    sendMessage(message);

    return;
}

void Server::sessionOpened()
{
    tcpServer_ = new QTcpServer(this);

    if (!tcpServer_->listen())
    {
        if (tcpServer_)
        {
            delete tcpServer_;
        }
    }
    else
    {
        tcpServer_->setMaxPendingConnections(1);
    }
}

void Server::connectClient()
{
    if (!(tcpSocket_ && tcpSocket_->state() != QAbstractSocket::UnconnectedState))
    {
        tcpSocket_ = tcpServer_->nextPendingConnection();
        connect(tcpSocket_, SIGNAL(readyRead()), this, SLOT(newMessage()));
        connect(tcpSocket_, SIGNAL(disconnected()), this, SIGNAL(disconnected()));
        emit connected();
    }
}
