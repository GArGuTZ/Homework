#include "standartvirus.h"

StandartVirus::StandartVirus()
{

}

StandartVirus::~StandartVirus()
{

}

int StandartVirus::getContagiousness()
{
    int cube = qrand() % 100;
    return cube;
}

