#include "ivirus.h"

IVirus::IVirus()
{
}

IVirus::~IVirus()
{
}

int IVirus::getContagiousness()
{
    return contagiousness_;
}

void IVirus::setFakeRandomGenerator(QVector<unsigned int> _fake)
{
}

void IVirus::unsetFakeRandomGenerator()
{
}

