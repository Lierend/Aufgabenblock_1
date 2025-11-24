#include <Fahrzeug.h>

int Fahrzeug::p_iMaxID = 0;

Fahrzeug::Fahrzeug(std::string sName){
	p_iID = ++p_iMaxID;
}
