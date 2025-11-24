#include "PKW.h"

using namespace std;

PKW::PKW():PKW("", 0.0, 0.0, 0.0){}

PKW::PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen):Fahrzeug(sName, dMaxGeschwindigkeit),p_dVerbrauch(dVerbrauch > 0.0 ? dVerbrauch : 0.0),p_dTankvolumen(dTankvolumen > 0.0 ? dTankvolumen : 0.0){
    p_dTankinhalt = p_dTankvolumen;
    cout << endl << "PKW ID: " << iGetID() << ", Name: " << sGetName() << " ist erzeugt " << endl;
}

PKW::~PKW() {
    cout << endl << "PKW ID: " << iGetID() << ", Name: " << sGetName() << " ist gelöscht " << endl;
}

double PKW::dTanken(double dMenge) {
	double dMaxTankbar = p_dTankvolumen - p_dTankinhalt;
	double dtMenge;

	/*if (isinf(dMenge)) {
        dtMenge = dMaxTankbar;
    } else {
        dtMenge = (dMenge < dMaxTankbar) ? dMenge : dMaxTankbar;
    }*/
    dtMenge = (!isinf(dMenge) && dMenge < dMaxTankbar) ? dMenge : dMaxTankbar;
    p_dTankinhalt += dtMenge;
    return dtMenge;

}

void PKW::vSimulieren() {
    if (dGlobaleZeit > p_dZeit) {
        double dDeltaZeit = dGlobaleZeit - p_dZeit;
        double dMaxStrecke = dGetGschw() * dDeltaZeit;
        double dMaxVerbrauch = dMaxStrecke * p_dVerbrauch;

        double dStrecke;
        double dVerbrauch;

        if (p_dTankinhalt <= 0.0) {
            dStrecke = 0.0;
            dVerbrauch = 0.0;
        } else {
            if (dMaxVerbrauch < p_dTankinhalt) {
                dStrecke = dMaxStrecke;
                dVerbrauch = dMaxVerbrauch;
            } else {
                dStrecke = p_dTankinhalt / p_dVerbrauch;
                dVerbrauch = p_dTankinhalt;
            }
        }

        p_dTankinhalt -= dVerbrauch;

        p_dGesamtStrecke += dStrecke;
        p_dGesamtZeit += dDeltaZeit;
        p_dZeit = dGlobaleZeit;
    }
}

void PKW::vKopf() {
	cout << endl
	    		  << setiosflags(ios::left)
	              << setw(4) << "ID"
	              << setw(15) << "Name"
	              << setiosflags(ios::right)
	              << setw(20) << "MaxGeschwindigkeit"
	              << setw(15) << "GesamtStrecke"
	              << setw(15) << "GesamtZeit"
				  << setiosflags(ios::right)
				  << setw(15) << "Tankinhalt"
				  << setw(15) << "Tankvolumen"
				  << setw(15) << "Verbrauch" << endl
				  << setw(115) << setfill('-') << "" << setfill(' ') << endl;
}

void PKW::vAusgeben(ostream& os) const {
    Fahrzeug::vAusgeben(os);
    os << setiosflags(ios::right)
              << fixed << setprecision(2)
              << setw(15) << p_dTankinhalt
              << setw(15) << p_dTankvolumen
              << setw(15) << p_dVerbrauch;
}
