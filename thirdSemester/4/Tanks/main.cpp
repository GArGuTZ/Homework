#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;

    if (!w.initNetwork())
    {
        return 0;
    }

    w.show();

    return a.exec();
}
