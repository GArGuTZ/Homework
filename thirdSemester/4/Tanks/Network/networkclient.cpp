#include "networkclient.h"

Client::Client(QObject* _parent) :
    Network(_parent)
{
    tcpSocket_ = new QTcpSocket(this);
    QNetworkConfigurationManager manager;

    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        networkSession_ = new QNetworkSession(manager.defaultConfiguration(), this);
        networkSession_->opened();
    }

    connect(tcpSocket_, SIGNAL(readyRead()), this, SLOT(newMessage()));
    connect(tcpSocket_, SIGNAL(connected()), this, SIGNAL(connected()));
    connect(tcpSocket_, SIGNAL(disconnected()), this, SIGNAL(disconnected()));
}

void Client::connectToServer(int _port)
{
    tcpSocket_->abort();
    tcpSocket_->connectToHost("localhost", _port);
}

void Client::decodeMessage(const QString& _message)
{
    if (!_message.size())
    {
        return;
    }

    if (_message.at(0) == QChar('L'))
    {
        Landscape* landscape = new Landscape(800, 600);

        QStringList stringList = _message.split(" ");

        stringList.first().remove(0, 1);
        int length = stringList.first().toInt();

        QVector<QPoint> newSurface(length - 1);
        for (int i = 0; i < length - 1; ++i)
        {
            newSurface[i].rx() = stringList.at(1 + 2*i).toInt();
            newSurface[i].ry() = stringList.at(2 + 2*i).toInt();
        }

        landscape->setSurface(newSurface);

        emit gotLandscape(landscape);
    }
    else
    {
        Network::decodeMessage(_message);
    }
}
