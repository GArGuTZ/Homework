#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <QDebug>
#include "computer.h"

class ComputerTest: public QObject
{
    Q_OBJECT
public:
   explicit ComputerTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void defaultConsctructor()
    {
        computer = new Computer();

        QVERIFY(computer->getProbability() == 0);
        QVERIFY(computer->isInfected() == false);
    }

    void probabilityConstructor1()
    {
        computer = new Computer(0);

        QVERIFY(computer->getProbability() == 0);
        QVERIFY(computer->isInfected() == false);
    }

    void probabilityConstructor2()
    {
        computer = new Computer(100);

        QVERIFY(computer->getProbability() == 100);
        QVERIFY(computer->isInfected() == false);
    }

    void probabilityConstructor3()
    {
        computer = new Computer(70);

        QVERIFY(computer->getProbability() == 70);
        QVERIFY(computer->isInfected() == false);
    }

    void infectedConstructor()
    {
        computer = new Computer(true);

        QVERIFY(computer->getProbability() == 0);
        QVERIFY(computer->isInfected());
    }

    void unInfectedConstructor()
    {
        computer = new Computer(false);

        QVERIFY(computer->getProbability() == 0);
        QVERIFY(computer->isInfected() == false);
    }

    void copyConstruction()
    {
        Computer computer2(31);

        computer = new Computer(computer2);

        //qDebug() << "Original: " << kompukter.getProbability() << "\nCopy: " << computer->getProbability();
        QVERIFY(computer->getProbability() == 31);
        QVERIFY(computer->isInfected() == false);
    }

    void copyOperator()
    {
        Computer computer1(42);
        Computer computer2(66);

        computer2 = computer1;

        QVERIFY(computer2.getProbability() == 42);
        QVERIFY(computer2.isInfected() == false);
    }

    void equalityOperator()
    {
        Computer computer1(42);
        Computer computer2(42);

        QVERIFY(computer1 == computer2);

        computer2.infect();

        QVERIFY(!(computer1 == computer2));

        computer1.infect();

        QVERIFY(computer1 == computer2);
    }

    void inequalityOperator()
    {
        Computer computer1(42);
        Computer computer2(66);

        QVERIFY(computer1 != computer2);

        computer2.infect();

        QVERIFY(computer1 != computer2);

        computer1.infect();

        QVERIFY(!(computer1 != computer2));
    }

private:
    Computer *computer;
};

