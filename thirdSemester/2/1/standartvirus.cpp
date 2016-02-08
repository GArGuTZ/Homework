#include "standartvirus.h"

StandartVirus::StandartVirus()
{
    currentThrow_ = -1;
}

StandartVirus::~StandartVirus()
{
}

int StandartVirus::getContagiousness()
{
    int cube;

    if (currentThrow_ < 0)
    {
        cube = qrand() % 100;
        return cube;
    }

    cube = probabilities_[currentThrow_];
    ++currentThrow_;

    if (currentThrow_ == probabilities_.length())
    {
        currentThrow_ = 0;
    }

    return cube;
}

void StandartVirus::setFakeRandomGenerator(QVector<unsigned int> _fake)
{
    probabilities_ = _fake;
    currentThrow_ = 0;
}

void StandartVirus::unsetFakeRandomGenerator()
{
    probabilities_.clear();
    currentThrow_ = -1;

}

