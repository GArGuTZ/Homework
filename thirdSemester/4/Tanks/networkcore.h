#pragma once

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QtNetwork>
#include <QDataStream>
#include <QTcpSocket>

class Tank;
class NetworkController;

/** @brief The Network class is a base class for the Client and Server */
class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject* _parent = 0);

    /** @brief sets the InputObserver for a subject and its input */
    void observeController(Tank* _subject);
    /** @brief initalize NetworkInputManager instance that is connected with a subject */
    void initController(Tank* _subject);

signals:
    void disconnected();
    void connected();

protected slots:
    void sendMessage(const QString& _message);

private slots:
    void newMessage();

protected:
    virtual void decodeMessage(const QString& _message);

    NetworkController *inputManager_;
    QTcpSocket *tcpSocket_;
    QNetworkSession *networkSession_;
    quint16 blockSize_;
};
