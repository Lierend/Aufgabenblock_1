#include "Fahrrad.h"

using namespace std;

Fahrrad::Fahrrad() : Fahrrad("", 0.0) {}

Fahrrad::Fahrrad(std::string sName, double dMaxGeschwindigkeit)
    : Fahrzeug(sName, dMaxGeschwindigkeit) {
    cout << "Fahrrad ID: " << iGetID() << ", Name: " << sGetName() << " ist erzeugt " << endl;
}

Fahrrad::~Fahrrad() {
    cout << "Fahrrad ID: " << iGetID() << ", Name: " << sGetName() << " ist gelöscht " << endl;
}

/*void Fahrrad::vSimulieren() {
	if (dGlobaleZeit > p_dZeit) {
		double dDeltaZeit = dGlobaleZeit - p_dZeit;
	    double dDeltaStrecke = dGetGschw() * dDeltaZeit;
	    p_dGesamtStrecke += dDeltaStrecke;
	    p_dGesamtZeit += dDeltaZeit;
	    p_dZeit = dGlobaleZeit;
	}
}*/

void Fahrrad::vAusgeben(ostream& os) const {
	os << endl
	    		  << setiosflags(ios::left)
	              << setw(4) << p_iID
	              << setw(15) << p_sName
	              << setiosflags(ios::right)
	              << fixed << setprecision(2)
	              << setw(20) << dGetGschw()
	              << setw(15) << p_dGesamtStrecke
	              << setw(15) << p_dGesamtZeit;
}
double Fahrrad::dGetGschw() const{
    double n = p_dGesamtStrecke / 20.0;
    double dFaktor = pow(0.9, n);
    double dGschw = p_dMaxGeschwindigkeit * dFaktor;
    return (dGschw < 12.0)? 12.0 : dGschw;
}
