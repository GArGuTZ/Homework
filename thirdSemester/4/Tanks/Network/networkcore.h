#pragma once

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QtNetwork>
#include <QDataStream>
#include <QTcpSocket>

class Tank;
class NetworkController;

/** @brief Base class for the Client and Server */

class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject* _parent = 0);

    /** @brief Sets the ObserverController for a tank and his input */
    void observeController(Tank* _tank);

    /** @brief Initalize NetworkController instance connected with a tank */
    void initController(Tank* _tank);

signals:
    void disconnected();
    void connected();

protected slots:
    void sendMessage(const QString& _message);

private slots:
    void newMessage();

protected:
    virtual void decodeMessage(const QString& _message);

    NetworkController* networkController_;
    QTcpSocket* tcpSocket_;
    QNetworkSession* networkSession_;
    quint16 blockSize_;
};
