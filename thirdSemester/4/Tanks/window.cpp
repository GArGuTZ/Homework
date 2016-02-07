#include "window.h"


Window::Window(QWidget *_parent) :
    QMainWindow(_parent),
    parent_(_parent),
    network_(nullptr)
{
}

bool Window::initNetwork()
{
    QMessageBox *networkDialog = new QMessageBox(this);
    networkDialog->setText("Choose network type");

    QPushButton *clientButton = networkDialog->addButton("Client", QMessageBox::ActionRole);
    QPushButton *serverButton = networkDialog->addButton("Server", QMessageBox::ActionRole);
    networkDialog->addButton(QMessageBox::Cancel);

    networkDialog->exec();
    QAbstractButton *clickedButton = networkDialog->clickedButton();
    networkDialog->deleteLater();

    if (clickedButton == serverButton)
    {
        Server *server = new Server(this);
        network_ = server;
        connect(server, SIGNAL(connected()), this, SLOT(connected()));
        connect(server, SIGNAL(disconnected()), this, SLOT(disconnected()));

        if (!server->init())
        {
            return false;
        }

        setWindowTitle("Server");
        QString message = "\t\tPort: " + server->getPort();
        statusBar()->showMessage(message);
    }
    else if (clickedButton == clientButton)
    {
        Client *client = new Client(this);
        connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));
        network_ = client;
        ConnectServerDialog *dialog = new ConnectServerDialog(client);

        if (!dialog->exec())
        {
            return false;
        }
        setWindowTitle("Client");
        connected();
    }
    else
    {
        return false;
    }

    return true;
}

void Window::connected()
{
    GameCore* game = new GameCore(width_, height_, parent_);
    connect(game, SIGNAL(gameOver(QString)), this, SLOT(gameOver(QString)));

    setFixedSize(width_ + 30, height_ + 30);
    setCentralWidget(game);
    game->startGame(network_);
}

void Window::disconnected()
{
    QMessageBox::information(this, tr("Bad news"), tr("Disconnected"));
    close();
}

void Window::gameOver(const QString &_string)
{
    disconnect(network_, SIGNAL(disconnected()), this, SLOT(disconnected()));
    QMessageBox::information(this, tr("Game over"), _string);
    close();
}
