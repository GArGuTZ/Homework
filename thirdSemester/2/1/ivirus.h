#pragma once

/**
 * @brief IVirus class
 * Interface for the viruses
 */

class IVirus
{
public:
    IVirus();
    ~IVirus();
    virtual int getContagiousness();
protected:
    int contagiousness_;
};

