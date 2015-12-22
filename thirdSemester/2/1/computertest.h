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
    void DefaultConsctructor()
    {
        computer = new Computer();
        QVERIFY(computer->getProbability() == 0);
        QVERIFY(computer->isInfected() == false);
    }

    void ProbabilityConstructor1()
    {
        computer = new Computer(0);
        QVERIFY(computer->getProbability() == 0);
        QVERIFY(computer->isInfected() == false);
    }

    void ProbabilityConstructor2()
    {
        computer = new Computer(100);
        QVERIFY(computer->getProbability() == 100);
        QVERIFY(computer->isInfected() == false);
    }

    void ProbabilityConstructor3()
    {
        computer = new Computer(70);
        QVERIFY(computer->getProbability() == 70);
        QVERIFY(computer->isInfected() == false);
    }

    void InfectedConstructor()
    {
        computer = new Computer(true);
        QVERIFY(computer->getProbability() == 0);
        QVERIFY(computer->isInfected());
    }

    void UnInfectedConstructor()
    {
        computer = new Computer(false);
        QVERIFY(computer->getProbability() == 0);
        QVERIFY(computer->isInfected() == false);
    }

    void CopyConstruction()
    {
        Computer kompukter(31);
        computer = new Computer(kompukter);
        //qDebug() << "Original: " << kompukter.getProbability() << "\nCopy: " << computer->getProbability();
        QVERIFY(computer->getProbability() == 31);
        QVERIFY(computer->isInfected() == false);
    }

    void CopyOperator()
    {
        Computer kompukter1(42);
        Computer kompukter2(66);
        kompukter2 = kompukter1;
        QVERIFY(kompukter2.getProbability() == 42);
        QVERIFY(kompukter2.isInfected() == false);
    }

    void EqualityOperator()
    {
        Computer kompukter1(42);
        Computer kompukter2(42);
        QVERIFY(kompukter1 == kompukter2);
        kompukter2.infect();
        QVERIFY(!(kompukter1 == kompukter2));
        kompukter1.infect();
        QVERIFY(kompukter1 == kompukter2);
    }

    void InequalityOperator()
    {
        Computer kompukter1(42);
        Computer kompukter2(66);
        QVERIFY(kompukter1 != kompukter2);
        kompukter2.infect();
        QVERIFY(kompukter1 != kompukter2);
        kompukter1.infect();
        QVERIFY(!(kompukter1 != kompukter2));
    }

private:
    Computer *computer;
};

