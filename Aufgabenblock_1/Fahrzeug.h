#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

class Fahrzeug{
	protected:
		string p_sName = "";
		const int p_iID;
		static int p_iMaxID;
	public:
		Fahrzeug(std::string sName);
		virtual ~Fahrzeug();
};

