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
        Computer kompukter1(31);
        Computer kompukter2(13);
        Computer kompukter3(78);
        Computer kompukter4(88);
        Computer kompukter5(56);
        Computer kompukter6(27);
        QVector<Computer> komputers(numberOfTestingComputers);
        komputers[0] = kompukter1;
        komputers[1] = kompukter2;
        komputers[2] = kompukter3;
        komputers[3] = kompukter4;
        komputers[4] = kompukter5;
        komputers[5] = kompukter6;
        QVERIFY(komputers[0].getProbability() == 31);
        QVERIFY(komputers[1].getProbability() == 13);
        QVERIFY(komputers[2].getProbability() == 78);
        QVERIFY(komputers[3].getProbability() == 88);
        QVERIFY(komputers[4].getProbability() == 56);
        QVERIFY(komputers[5].getProbability() == 27);
        bool allConnected[numberOfTestingComputers][numberOfTestingComputers] = {{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1}};

        bool **All = new bool *[numberOfTestingComputers];

        for(int i = 0; i < numberOfTestingComputers; ++i)
        {
            All[i] = new bool[numberOfTestingComputers];
            for(int j = 0; j < numberOfTestingComputers; ++j)
                All[i][j] = allConnected[i][j];
        }

        testingWeb = new Network(komputers, All);
    }

    void PureNetworkSimulation()
    {
        for(int i = 0; i < simulationSteps; ++i)
        {
            testingWeb->SimulationStep();
        }

        QVERIFY(testingWeb->howManyInfected() == 0);
    }

    void AllInfectedNetworkSimulation()
    {
        delete testingWeb;

        bool allConnected[numberOfTestingComputers][numberOfTestingComputers] = {{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1}};

        bool **All = new bool *[numberOfTestingComputers];

        for(int i = 0; i < numberOfTestingComputers; ++i)
        {
            All[i] = new bool[numberOfTestingComputers];
            for(int j = 0; j < numberOfTestingComputers; ++j)
                All[i][j] = allConnected[i][j];
        }

        QVector<Computer> komputers;
        komputers += Computer(true);
        komputers += Computer(true);
        komputers += Computer(true);
        komputers += Computer(true);
        komputers += Computer(true);
        komputers += Computer(true);

        testingWeb = new Network(komputers, All);

        for(int i = 0; i < simulationSteps; ++i)
        {
            testingWeb->SimulationStep();
        }

        QVERIFY(testingWeb->howManyInfected() == numberOfTestingComputers);

    }

    void DeleteTest()
    {
        delete testingWeb;
        QVERIFY(testingWeb->howManyComputers() == 0);
    }

    void DisconnectedNetworkSimulation()
    {
        delete testingWeb;

        bool allDisconnected[numberOfTestingComputers][numberOfTestingComputers] = {{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1}};

        bool **All = new bool *[numberOfTestingComputers];

        for(int i = 0; i < numberOfTestingComputers; ++i)
        {
            All[i] = new bool[numberOfTestingComputers];
            for(int j = 0; j < numberOfTestingComputers; ++j)
                All[i][j] = allDisconnected[i][j];
        }

        QVector<Computer> komputers;
        komputers += Computer(true);
        komputers += Computer(true);
        komputers += Computer(true);
        komputers += Computer(23);
        komputers += Computer(31);
        komputers += Computer(44);
        testingWeb = new Network(komputers, All);

        for(int i = 0; i < simulationSteps; ++i)
        {
            testingWeb->SimulationStep();
        }

        QVERIFY(testingWeb->howManyInfected() == 3);
    }

    void AccessOperator()
    {
        Computer komputer(56);
        QVERIFY(komputer == (*testingWeb)[4]);
    }

    void Infecting()
    {
        Computer komputer(true);
        testingWeb->SetFirstVictim(1);
        QVERIFY(komputer == (*testingWeb)[1]);
    }

    void TestKillerVirus()
    {
        testingWeb->SetFirstVictim(4);

        IVirus* killer = new KillerVirus;

        testingWeb->setVirus(killer);

        for(int i = 0; i < simulationSteps; ++i)
        {
            testingWeb->SimulationStep();
        }

        delete killer;

        QVERIFY(testingWeb->howManyInfected() == numberOfTestingComputers);
    }

    void TestGoodVirus()
    {
        testingWeb->SetFirstVictim(4);

        IVirus* gentle = new GoodVirus;

        testingWeb->setVirus(gentle);

        for(int i = 0; i < simulationSteps; ++i)
        {
            testingWeb->SimulationStep();
        }

        delete gentle;

        QVERIFY(testingWeb->howManyInfected() == 1);

    }

private:
    Network *testingWeb;
    int numberOfTestingComputers = 6;
    int simulationSteps = 1000;
};
