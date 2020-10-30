#pragma once

#include <QNetworkConfigurationManager>
#include <QNetworkSession>
#include <QTcpSocket>
#include <QVector>

#include "Game/landscape.h"
#include "networkcore.h"

class Landscape;

/** @brief Describes a client */

class Client : public Network
{
    Q_OBJECT
public:
    explicit Client(QObject* _parent = nullptr);

    void connectToServer(int _port);

signals:

    /** @brief Emitted when the Landscape received by the network */
    void gotLandscape(Landscape* _landscape);

protected:
    void decodeMessage(const QString& _message) Q_DECL_OVERRIDE;
};
