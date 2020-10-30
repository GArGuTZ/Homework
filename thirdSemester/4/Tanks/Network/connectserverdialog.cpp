#include "connectserverdialog.h"

ConnectServerDialog::ConnectServerDialog(Client* _client) :
    QDialog(nullptr),
    portLineEdit_(new QLineEdit),
    client_(_client)
{
    setAttribute(Qt::WA_DeleteOnClose);
    QPushButton* connectButton = new QPushButton("Connect");
    connect(connectButton, SIGNAL(clicked()), this, SLOT(tryToConnect()));
    portLineEdit_->setValidator(new QRegExpValidator(QRegExp("\\d+"), this));
    portLineEdit_->setPlaceholderText("Port");

    QGridLayout* layout = new QGridLayout;
    layout->addWidget(portLineEdit_, 1, 0);
    layout->addWidget(connectButton, 2, 0);
    setLayout(layout);

    connect(client_, SIGNAL(connected()), this, SLOT(accept()));
}

ConnectServerDialog::~ConnectServerDialog()
{
}

void ConnectServerDialog::tryToConnect()
{
    client_->connectToServer(portLineEdit_->text().toInt());
}
