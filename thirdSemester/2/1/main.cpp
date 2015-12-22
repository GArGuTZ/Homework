#include <QCoreApplication>
#include "computertest.h"
#include "networktest.h"

int main(int argc, char *argv[])
{
    ComputerTest test;
    QTest::qExec(&test);
    NetworkTest netTest;
    QTest::qExec(&netTest);
}
