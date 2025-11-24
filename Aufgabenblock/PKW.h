#pragma once
#include "Fahrzeug.h"

class PKW : public Fahrzeug {
protected:
    const double p_dVerbrauch = 0.0;
    double p_dTankinhalt = 0.0;
    const double p_dTankvolumen = 0.0;

public:
    PKW();
    PKW(std::string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen);

    virtual ~PKW();

    virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity()) override;

    virtual void vSimulieren() override;

    virtual void vAusgeben(std::ostream& os) const override;

    static void vKopf();
};
