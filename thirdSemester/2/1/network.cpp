#include "network.h"


Network::Network(const QVector<Computer> &_computersList, bool **_matrix)
{
    adjacencyMatrix_ = _matrix;
    numberOfComputers_ = _computersList.length();
    numberOfVictims_ = 0;
    listOfComputers_ = _computersList;

    for (unsigned int i = 0; i < numberOfComputers_; ++i)
    {
        if (listOfComputers_[i].isInfected())
        {
            ++numberOfVictims_;
        }
    }

    virus_ = new StandartVirus();
}

Network::~Network()
{
    listOfComputers_.clear();

    for (unsigned int i = 0; i < numberOfComputers_; ++i)
    {
        delete [] adjacencyMatrix_[i];
    }

    delete [] adjacencyMatrix_;

    numberOfComputers_ = 0;
    numberOfVictims_ = 0;

    if (virus_)
    {
        delete virus_;
    }
}

void Network::currentStatus() const
{
    for (unsigned int i = 0; i < numberOfComputers_; ++i)
    {
        std::cout << i << ": " << listOfComputers_[i];
        std::cout << ", connected with";

        bool f = true;

        for (unsigned int j = 0; j < numberOfComputers_; ++j)
        {
            if ((i != j) && (adjacencyMatrix_[i][j]))
            {
                std::cout << ' ' << j;
                f = false;
            }
        }

        if (f)
        {
            std::cout << " nobody";
        }

        std::cout << std::endl;
    }
}

int Network::howManyComputers() const
{
    return numberOfComputers_;
}

int Network::howManyInfected() const
{
    return numberOfVictims_;
}

void Network::simulationStep()
{
    int cube = virus_->getContagiousness();

    for (unsigned int i = 0; i < numberOfComputers_; ++i)
    {

        if (listOfComputers_[i].isInfected())
        {

            for (unsigned int j = 0; j < numberOfComputers_; ++j)
            {
                if ((adjacencyMatrix_[i][j]) && (!listOfComputers_[j].isInfected()))
                {
                    if (listOfComputers_[j].getProbability() > cube)
                    {
                        listOfComputers_[j].infect();
                        ++numberOfVictims_;
                    }

                    return;
                }
            }

        }

    }
}

void Network::setFirstVictim(unsigned int _victim)
{
    if (numberOfVictims_)
    {
        return;
    }

    if (_victim < numberOfComputers_)
    {
        listOfComputers_[_victim].infect();
    }
    else
    {
        int first = qrand() % numberOfComputers_;
        listOfComputers_[first].infect();
    }

    ++numberOfVictims_;
}

void Network::setVirus(IVirus *_virus)
{
    virus_ = _virus;
}

const Computer& Network::operator [](int _i) const
{
    return listOfComputers_[_i];
}
