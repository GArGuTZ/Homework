#include "computer.h"


Computer::Computer():
    morbidityPercentage(0),
    Infection(false)
{
}

Computer::Computer(int probabilityOfInfection):
    Infection(false)
{
    probabilityOfInfection = probabilityOfInfection % 101;
    morbidityPercentage = probabilityOfInfection;
}

Computer::Computer(bool infectedOrNot):
    morbidityPercentage(0),
    Infection(infectedOrNot)
{
}

Computer::Computer(const Computer &obj)
{
    morbidityPercentage = obj.morbidityPercentage;
    Infection = obj.Infection;
}

Computer &Computer::operator =(const Computer &obj)
{
    morbidityPercentage = obj.getProbability();
    Infection = obj.isInfected();
    return *this;
}

bool Computer::operator ==(const Computer &second) const
{
    if((morbidityPercentage == second.getProbability()) && (Infection == second.isInfected()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Computer::operator !=(const Computer &second) const
{
    if((Infection != second.isInfected()) || (morbidityPercentage != second.getProbability()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

Computer::~Computer()
{
}

int Computer::getProbability() const
{
    return morbidityPercentage;
}

bool Computer::isInfected() const
{
    return Infection;
}

void Computer::infect()
{
    Infection = true;
    morbidityPercentage = 0;
}

std::ostream &operator <<(std::ostream &stream, const Computer& komp)
{
    if(komp.isInfected())
    {
        stream << "Infected Computer";
    }
    else
    {
        stream << "Pure Computer, with " << komp.getProbability() << "% probability of infect";
    }

    return stream;
}
