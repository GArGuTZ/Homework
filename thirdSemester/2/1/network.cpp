#include "network.h"


Network::Network(const QVector<Computer> &computersList, bool **matrix)
{
    adjacencyMatrix = matrix;
    numberOfComputers = computersList.length();
    numberOfVictims = 0;
    listOfComputers = computersList;

    for(unsigned int i = 0; i < numberOfComputers; ++i)
    {
        if(listOfComputers[i].isInfected())
        {
            ++numberOfVictims;
        }
    }

    virus_ = new StandartVirus();
}

Network::~Network()
{
    listOfComputers.clear();

    for(unsigned int i = 0; i < numberOfComputers; ++i)
    {
        delete adjacencyMatrix[i];
    }

    delete adjacencyMatrix;
    numberOfComputers = 0;
    numberOfVictims = 0;
    if(virus_)
    {
        delete virus_;
    }
}

void Network::currentStatus() const
{
    for(unsigned int i = 0; i < numberOfComputers; ++i)
    {
        std::cout << i << ": " << listOfComputers[i];
        std::cout << ", connected with";
        bool f = true;

        for(unsigned int j = 0; j < numberOfComputers; ++j)
        {
            if((i != j) && (adjacencyMatrix[i][j]))
            {
                std::cout << ' ' << j;
                f = false;
            }
        }

        if(f)
        {
            std::cout << " nobody";
        }
        std::cout << std::endl;
    }
}

int Network::howManyComputers() const
{
    return numberOfComputers;
}

int Network::howManyInfected() const
{
    return numberOfVictims;
}

void Network::SimulationStep()
{
    int cube = virus_->getContagiousness();

    for(unsigned int i = 0; i < numberOfComputers; ++i)
    {

        if(listOfComputers[i].isInfected())
        {

            for(unsigned int j = 0; j < numberOfComputers; ++j)
            {
                if((adjacencyMatrix[i][j]) && (!listOfComputers[j].isInfected()))
                {
                    if(listOfComputers[j].getProbability() > cube)
                    {
                        listOfComputers[j].infect();
                        ++numberOfVictims;
                    }

                    return;
                }
            }

        }

    }
}

void Network::SetFirstVictim(unsigned int _victim)
{
    if(numberOfVictims)
    {
        return;
    }

    if(_victim < numberOfComputers)
    {
        listOfComputers[_victim].infect();
    }
    else
    {
        int first = qrand() % numberOfComputers;
        listOfComputers[first].infect();
    }

    ++numberOfVictims;
}

void Network::setVirus(IVirus *_virus)
{
    virus_ = _virus;
}

const Computer& Network::operator [](int i) const
{/*
    if((i < 0) || (i >= numberOfComputers))
    {
        return;
    }*/
    return listOfComputers[i];
}
