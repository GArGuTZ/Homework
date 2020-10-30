#include "computer.h"


Computer::Computer():
    morbidityPercentage_(0),
    infection_(false)
{
}

Computer::Computer(int _probabilityOfInfection):
    infection_(false)
{
    _probabilityOfInfection = _probabilityOfInfection % 101;
    morbidityPercentage_ = _probabilityOfInfection;
}

Computer::Computer(bool _infectedOrNot):
    morbidityPercentage_(0),
    infection_(_infectedOrNot)
{
}

Computer::Computer(const Computer& _obj)
{
    morbidityPercentage_ = _obj.morbidityPercentage_;
    infection_ = _obj.infection_;
}

Computer::~Computer()
{
}


int Computer::getProbability() const
{
    return morbidityPercentage_;
}

bool Computer::isInfected() const
{
    return infection_;
}

void Computer::infect()
{
    infection_ = true;
    morbidityPercentage_ = 0;
}


Computer &Computer::operator =(const Computer& _obj)
{
    morbidityPercentage_ = _obj.getProbability();
    infection_ = _obj.isInfected();

    return *this;
}

bool Computer::operator ==(const Computer& _second) const
{
    return ((morbidityPercentage_ == _second.getProbability()) && (infection_ == _second.isInfected()));
}

bool Computer::operator !=(const Computer& _second) const
{
    return ((infection_ != _second.isInfected()) || (morbidityPercentage_ != _second.getProbability()));
}

std::ostream &operator <<(std::ostream& _stream, const Computer& _computer)
{
    if (_computer.isInfected())
    {
        _stream << "Infected Computer";
    }
    else
    {
        _stream << "Pure Computer, with " << _computer.getProbability() << "% probability of infect";
    }

    return _stream;
}
