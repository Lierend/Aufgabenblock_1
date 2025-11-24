#pragma once
#include "Fahrzeug.h"

class Fahrrad : public Fahrzeug {
public:
    Fahrrad();
    Fahrrad(std::string sName, double dMaxGeschwindigkeit);

    virtual ~Fahrrad();

    //virtual void vSimulieren() override;

    virtual void vAusgeben(std::ostream& os) const override;

    virtual double dGetGschw() const override;
};
