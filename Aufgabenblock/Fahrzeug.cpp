#include "Fahrzeug.h"

using namespace std;

int Fahrzeug::p_iMaxID = 0;

double dGlobaleZeit = 0.0;

Fahrzeug::Fahrzeug(){
}

Fahrzeug::Fahrzeug(std::string sName):p_iID(++p_iMaxID),p_sName(sName){
    cout << "Fahrzeug ID: " << p_iID << ", Name: " << p_sName << " ist erzeugt " << endl;
}

Fahrzeug::Fahrzeug(std::string sName, double dMaxGeschwindigkeit):p_iID(++p_iMaxID),p_sName(sName),p_dMaxGeschwindigkeit(dMaxGeschwindigkeit > 0.0 ? dMaxGeschwindigkeit : 0.0){
    cout << "Fahrzeug ID: " << p_iID << ", Name: " << p_sName << " ist erzeugt " << endl;
}

Fahrzeug::~Fahrzeug() {
    cout << "Fahrzeug ID: " << p_iID << ", Name: " << p_sName << " ist gelöscht " <<endl;
}

void Fahrzeug::vKopf() {
    cout << endl
    		  << setiosflags(ios::left)
              << setw(4) << "ID"
              << setw(15) << "Name"
              << setiosflags(ios::right)
              << setw(20) << "MaxGeschwindigkeit"
              << setw(15) << "GesamtStrecke"
              << setw(15) << "GesamtZeit" << endl
			  << setw(115) << setfill('-') << "" << setfill(' ') << endl;
}

void Fahrzeug::vAusgeben(ostream& os) const {
    os << endl
    		  << setiosflags(ios::left)
              << setw(4) << p_iID
              << setw(15) << p_sName
              << setiosflags(ios::right)
              << fixed << setprecision(2)
              << setw(20) << p_dMaxGeschwindigkeit
              << setw(15) << p_dGesamtStrecke
              << setw(15) << p_dGesamtZeit;
}

void Fahrzeug::vSimulieren() {
    if (dGlobaleZeit > p_dZeit) {
        double dDeltaZeit = dGlobaleZeit - p_dZeit;
        double dDeltaStrecke = dGetGschw() * dDeltaZeit;
        p_dGesamtStrecke += dDeltaStrecke;
        p_dGesamtZeit += dDeltaZeit;
        p_dZeit = dGlobaleZeit;
    }
}

double Fahrzeug::dTanken(double dMenge) {
    return 0.0;
}

bool Fahrzeug::operator<(const Fahrzeug& f) const {
    return p_dGesamtStrecke < f.p_dGesamtStrecke;
}

Fahrzeug& Fahrzeug::operator=(const Fahrzeug& f){
	if(this != &f){
		this->p_sName = f.sGetName();
	}
	return *this;
}
