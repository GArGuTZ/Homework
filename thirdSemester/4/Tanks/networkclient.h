#pragma once

#include <QNetworkConfigurationManager>
#include <QNetworkSession>
#include <QTcpSocket>
#include <QVector>

#include "landscape.h"
#include "networkcore.h"

class Landscape;

/** @brief The Client class represents the Client */
class Client : public Network
{
    Q_OBJECT
public:
    explicit Client(QObject* _parent = nullptr);

    void connectToServer(int _port);

signals:
    /** @brief emitted when the Landscape received by the network. */
    void gotLandscape(Landscape* _landscape);

protected:
    void decodeMessage(const QString& _message) Q_DECL_OVERRIDE;
};
