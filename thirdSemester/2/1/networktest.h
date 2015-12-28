#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "network.h"

class NetworkTest: public QObject
{
    Q_OBJECT
public:
   explicit NetworkTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        Computer computer1(31);
        Computer computer2(13);
        Computer computer3(78);
        Computer computer4(88);
        Computer computer5(56);
        Computer computer6(27);

        QVector<Computer> computers(numberOfTestingComputers);
        computers[0] = computer1;
        computers[1] = computer2;
        computers[2] = computer3;
        computers[3] = computer4;
        computers[4] = computer5;
        computers[5] = computer6;

        QVERIFY(computers[0].getProbability() == 31);
        QVERIFY(computers[1].getProbability() == 13);
        QVERIFY(computers[2].getProbability() == 78);
        QVERIFY(computers[3].getProbability() == 88);
        QVERIFY(computers[4].getProbability() == 56);
        QVERIFY(computers[5].getProbability() == 27);

        bool allConnected[numberOfTestingComputers][numberOfTestingComputers] = {{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1}};

        bool **all = new bool *[numberOfTestingComputers];

        for (int i = 0; i < numberOfTestingComputers; ++i)
        {
            all[i] = new bool[numberOfTestingComputers];
            for (int j = 0; j < numberOfTestingComputers; ++j)
                all[i][j] = allConnected[i][j];
        }

        testingWeb = new Network(computers, all);
    }

    void pureNetworkSimulation()
    {
        for (int i = 0; i < simulationSteps; ++i)
        {
            testingWeb->simulationStep();
        }

        QVERIFY(testingWeb->howManyInfected() == 0);
    }

    void allInfectedNetworkSimulation()
    {
        delete testingWeb;

        bool allConnected[numberOfTestingComputers][numberOfTestingComputers] = {{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1}};

        bool **all = new bool *[numberOfTestingComputers];

        for (int i = 0; i < numberOfTestingComputers; ++i)
        {
            all[i] = new bool[numberOfTestingComputers];
            for (int j = 0; j < numberOfTestingComputers; ++j)
                all[i][j] = allConnected[i][j];
        }

        QVector<Computer> computers;
        computers += Computer(true);
        computers += Computer(true);
        computers += Computer(true);
        computers += Computer(true);
        computers += Computer(true);
        computers += Computer(true);

        testingWeb = new Network(computers, all);

        for (int i = 0; i < simulationSteps; ++i)
        {
            testingWeb->simulationStep();
        }

        QVERIFY(testingWeb->howManyInfected() == numberOfTestingComputers);
    }

    void deleteTest()
    {
        delete testingWeb;

        QVERIFY(testingWeb->howManyComputers() == 0);
    }

    void DisconnectedNetworkSimulation()
    {
        delete testingWeb;

        bool allDisconnected[numberOfTestingComputers][numberOfTestingComputers] = {{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1}};

        bool **all = new bool *[numberOfTestingComputers];

        for (int i = 0; i < numberOfTestingComputers; ++i)
        {
            all[i] = new bool[numberOfTestingComputers];
            for (int j = 0; j < numberOfTestingComputers; ++j)
                all[i][j] = allDisconnected[i][j];
        }

        QVector<Computer> computers;
        computers += Computer(true);
        computers += Computer(true);
        computers += Computer(true);
        computers += Computer(23);
        computers += Computer(31);
        computers += Computer(44);

        testingWeb = new Network(computers, all);

        for (int i = 0; i < simulationSteps; ++i)
        {
            testingWeb->simulationStep();
        }

        QVERIFY(testingWeb->howManyInfected() == 3);
    }

    void accessOperator()
    {
        Computer computer(56);

        QVERIFY(computer == (*testingWeb)[4]);
    }

    void infecting()
    {
        Computer computer(true);
        testingWeb->setFirstVictim(1);

        QVERIFY(computer == (*testingWeb)[1]);
    }

    void testKillerVirus()
    {
        testingWeb->setFirstVictim(4);

        IVirus* killer = new KillerVirus;

        testingWeb->setVirus(killer);

        for (int i = 0; i < simulationSteps; ++i)
        {
            testingWeb->simulationStep();
        }

        delete killer;

        QVERIFY(testingWeb->howManyInfected() == numberOfTestingComputers);
    }

    void testGoodVirus()
    {
        testingWeb->setFirstVictim(4);

        IVirus* gentle = new GoodVirus;

        testingWeb->setVirus(gentle);

        for (int i = 0; i < simulationSteps; ++i)
        {
            testingWeb->simulationStep();
        }

        delete gentle;

        QVERIFY(testingWeb->howManyInfected() == 1);

    }

    void testStandartVirus1()
    {
        delete testingWeb;

        bool allConnected[numberOfTestingComputers][numberOfTestingComputers] = {{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1}};

        bool **all = new bool *[numberOfTestingComputers];

        for (int i = 0; i < numberOfTestingComputers; ++i)
        {
            all[i] = new bool[numberOfTestingComputers];
            for (int j = 0; j < numberOfTestingComputers; ++j)
                all[i][j] = allConnected[i][j];
        }

        QVector<Computer> computers;
        computers += Computer(100);
        computers += Computer(100);
        computers += Computer(100);
        computers += Computer(100);
        computers += Computer(100);
        computers += Computer(100);

        testingWeb = new Network(computers, all);

        testingWeb->setFirstVictim(5);

        for (int i = 0; i < simulationSteps; ++i)
        {
            testingWeb->simulationStep();
        }

        QVERIFY(testingWeb->howManyInfected() == numberOfTestingComputers);
    }

    void testStandartVirus2()
    {
        delete testingWeb;

        bool allConnected[numberOfTestingComputers][numberOfTestingComputers] = {{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1}};

        bool **all = new bool *[numberOfTestingComputers];

        for (int i = 0; i < numberOfTestingComputers; ++i)
        {
            all[i] = new bool[numberOfTestingComputers];
            for (int j = 0; j < numberOfTestingComputers; ++j)
                all[i][j] = allConnected[i][j];
        }

        QVector<Computer> computers;
        computers += Computer(0);
        computers += Computer(0);
        computers += Computer(0);
        computers += Computer(0);
        computers += Computer(0);
        computers += Computer(0);

        testingWeb = new Network(computers, all);

        testingWeb->setFirstVictim(0);

        for (int i = 0; i < simulationSteps; ++i)
        {
            testingWeb->simulationStep();
        }

        QVERIFY(testingWeb->howManyInfected() == 1);
    }

private:
    Network *testingWeb;
    int numberOfTestingComputers = 6;
    int simulationSteps = 1000;
};
