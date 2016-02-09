#pragma once

#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QHostAddress>
#include <QRegExpValidator>

#include "networkclient.h"

class ConnectServerDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ConnectServerDialog(Client* _client);
    ~ConnectServerDialog() Q_DECL_OVERRIDE;

private slots:
    void tryToConnect();

private:
    QLineEdit* portLineEdit_;

    Client* client_;
};
