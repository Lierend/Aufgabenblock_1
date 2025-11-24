#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <iomanip>
#include <cmath>
#include <limits>

extern double dGlobaleZeit;

class Fahrzeug {
protected:
    const int p_iID = 0;
    std::string p_sName = "";
    static int p_iMaxID;
    const double p_dMaxGeschwindigkeit = 0.0;
    double p_dGesamtStrecke = 0.0;
    double p_dGesamtZeit = 0.0;
    double p_dZeit = 0.0;

public:
    Fahrzeug();
    Fahrzeug(std::string sName);
    Fahrzeug(std::string sName, double dMaxGeschwindigkeit);
    Fahrzeug(const Fahrzeug&) = delete;

    virtual ~Fahrzeug();

    static void vKopf();

    virtual void vAusgeben(std::ostream& os) const;

    virtual void vSimulieren();

    virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());

    bool operator<(const Fahrzeug& f) const;

    Fahrzeug& operator=(const Fahrzeug& f);

    double dGetGesamtStrecke() const {
    	return p_dGesamtStrecke;
    }
    std::string sGetName() const {
    	return p_sName;
    }
    int iGetID() const {
    	return p_iID;
    }
     virtual double dGetGschw() const {
        return p_dMaxGeschwindigkeit;
    }
};
