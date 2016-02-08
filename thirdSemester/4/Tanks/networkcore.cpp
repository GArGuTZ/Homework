#include "networkcore.h"
#include "gamecore.h"
#include "tank.h"
#include "networkcontroller.h"
#include "observercontroller.h"

Network::Network(QObject* _parent) :
    QObject(_parent),
    networkController_(nullptr),
    tcpSocket_(nullptr),
    networkSession_(nullptr),
    blockSize_(0)
{
}

void Network::observeController(Tank* _tank)
{
    ObserverController* observerController = new ObserverController(this, _tank);
    connect(observerController, SIGNAL(emitInput(QString)), this, SLOT(sendMessage(QString)));
}

void Network::initController(Tank* _tank)
{
    networkController_ = new NetworkController(this, _tank);
}

void Network::newMessage()
{
    QDataStream in(tcpSocket_);
    if (!blockSize_)
    {
        if  (tcpSocket_->bytesAvailable() < (int)sizeof(quint16))
        {
            return;
        }
        in >> blockSize_;
    }
    if (tcpSocket_->bytesAvailable() >= blockSize_)
    {
        QString message;
        in >> message;
        blockSize_ = 0;
        decodeMessage(message);
    }
}

void Network::decodeMessage(const QString& _message)
{
    if (networkController_ && (_message.size() > 1) && (_message.at(0) == QChar('K')))
    {
        networkController_->handle(_message);
    }
}

void Network::sendMessage(const QString& _message)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;
    out << _message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    tcpSocket_->write(block);
}
