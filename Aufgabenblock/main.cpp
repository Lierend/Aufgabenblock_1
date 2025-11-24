#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include <algorithm>
#include <limits>

using namespace std;

ostream& operator<<(std::ostream& o, const Fahrzeug& x){
	x.vAusgeben(o);
	return o;
}

void vAufgabe_1() {
	dGlobaleZeit = 0.0;
    cout << "Aufgabe 1: " << endl;

    Fahrzeug f1_st("Static_1");
    Fahrzeug f2_st("Static_2", 80.0);

    Fahrzeug* f1_d = new Fahrzeug("Dynamic_1");
    Fahrzeug* f2_d = new Fahrzeug("Dynamic_2", 120.0);

    delete f1_d;
    delete f2_d;

    unique_ptr<Fahrzeug> f1_u = make_unique<Fahrzeug>("Unique_1");
    unique_ptr<Fahrzeug> f2_u = make_unique<Fahrzeug>("Unique_2");

    shared_ptr<Fahrzeug> f1_sh = make_shared<Fahrzeug>("Shared_1");
    shared_ptr<Fahrzeug> f2_sh = make_shared<Fahrzeug>("Shared_2");

    cout << endl << "Shared_1 Use Count (davor): " << f1_sh.use_count() << endl;
    shared_ptr<Fahrzeug> f3_sh = f1_sh;
    cout << "Shared_1 Use Count (danach): " << f1_sh.use_count() << endl;

    vector<unique_ptr<Fahrzeug>> vc_u;
    //vc_u.push_back(f1_u);
    vc_u.push_back(move(f1_u));
    vc_u.push_back(move(f2_u));
    if (f1_u == nullptr) {
        cout << "Unique_1: Besitzwechsel ist erfolgreich." << endl;
    }
    if (f2_u == nullptr) {
        cout << "Unique_2: Besitzwechsel ist erfolgreich." << endl;
    }
    vc_u.clear();
    cout << endl << " Vector ist gelöscht " << endl << endl;

    vector<shared_ptr<Fahrzeug>> vc_sh;
    vc_sh.push_back(f1_sh);
    vc_sh.push_back(move(f2_sh));

    cout << "Shared_1 Use Count (Vector Push): " << f1_sh.use_count() << endl;

    vc_sh.clear();
    cout << endl << " Vector ist gelöscht " << endl << endl;
}


void vAufgabe_1a() {
	dGlobaleZeit = 0.0;
    cout << endl << "Simulations Test: " << endl;

    vector<shared_ptr<Fahrzeug>> vc_f;
    cout << endl << "Geben Sie 3 Fahrzeugen und ihre maximale Geschwindigkeit ein" << endl;
    for(int i=0;i<3;i++){
    	string name;
    	double gsch;
    	cin >> name >> gsch;
		vc_f.push_back(make_shared<Fahrzeug>(name, gsch));
    }
    double ant = 0.0;
    do{

    	dGlobaleZeit += ant;
    	cout << endl << "Simulationsschritt: Zeit = " << dGlobaleZeit << endl;
    	PKW::vKopf();
    	for (const auto& f : vc_f) {
    		f->vSimulieren();
    		f->vAusgeben(cout);
    	}
    	cout << endl << endl << "Geben Sie die Anzahl der Takten der Simulation durchzuführen ein(-1.0 = Ende der Simulation)" << endl << endl;

    	do{
    		cin >> ant;
    		if(ant < 0 && ant != -1.0)
    			cout << "Die Anzahl kann nicht negativ sein" << endl;
    	}while(ant < 0 && ant != -1.0);

    }while(ant != -1.0);

    cout << endl << "Ende der Simulation" << endl << endl;
}

void vAufgabe_2() {
	dGlobaleZeit = 0.0;
    cout << endl << " Aufgabe_2: " << endl;

    vector<unique_ptr<Fahrzeug>> vc_f;
    int k_pkw, k_frd;

    cout << endl << "Wie viel PKWs wollen Sie simulieren?" << endl;
    cin >> k_pkw;

    cout << endl << "Wie viel Fahrraden wollen Sie simulieren?" << endl;
    cin >> k_frd;
    for(int i=0;i<k_pkw;i++){
    	cout << endl << "Geben Sie Name, maximale Geschwindigkeit, Verbrauch und Tankvolumen des " << i + 1 << "tes PKWs ein" << endl;
    	string name;
        double gsch;
        double vrb;
        double tvl;
        cin >> name >> gsch >> vrb >> tvl;
        vc_f.push_back(make_unique<PKW>(name, gsch, vrb, tvl));
    }

    for(int i=0;i<k_frd;i++){
        cout << endl << "Geben Sie Name und anfängliche Geschwindigkeit des " << i + 1 << "tes Fahrrades ein" << endl;
        string name;
        double gsch;
        cin >> name >> gsch;
        vc_f.push_back(make_unique<Fahrrad>(name, gsch));
    }

    double ant = 0.0;
    int n = 0;
    do{
        dGlobaleZeit += ant;
        cout << endl << "Simulationsschritt: Zeit = " << dGlobaleZeit << endl << n << endl;
        if(((int)(dGlobaleZeit/3) - n) > 0){
        	n = (int)(dGlobaleZeit/3);
        	for (const auto& f : vc_f) {
        		f->dTanken();
        	}
        }
        PKW::vKopf();
        for (const auto& f : vc_f) {
        	f->vSimulieren();
        	f->vAusgeben(cout);
        }
        cout << endl << endl << "Geben Sie die Anzahl der Takten der Simulation durchzuführen ein(-1.0 = Ende der Simulation)" << endl << endl;

        do{
        	cin >> ant;
        	if(ant < 0 && ant != -1.0)
        		cout << "Die Anzahl kann nicht negativ sein" << endl;
        }while(ant < 0 && ant != -1.0);

     }while(ant != -1.0);

     cout << endl << "Ende der Simulation" << endl << endl;
}

void vAufgabe_4() {
    cout << endl << "Aufgabe 3: " << endl;
    dGlobaleZeit = 0.0;

    PKW f1("BMW",100,0.8,300);
    Fahrrad* f2 = new Fahrrad("BMX", 45);
    PKW::vKopf();
    cout << f1 << endl
    		<< *f2 <<endl << endl;

    delete f2;

    Fahrzeug* frz1 = new Fahrzeug("Audi",90);
    Fahrzeug* frz2 = new Fahrzeug("Mazda",100);

    dGlobaleZeit = 5.0;

    frz1->vSimulieren();
    frz2->vSimulieren();

    bool b =  *frz1<*frz2;

    Fahrzeug::vKopf();
    cout << *frz1 << endl
    		<< *frz2 <<endl
			<< b << endl;

    *frz1 = *frz2;

    Fahrzeug::vKopf();
    cout << *frz1 << endl
        	<< *frz2 << endl << endl;

    delete frz1;
    delete frz2;

}


int main() {
    vAufgabe_1();
    vAufgabe_1a();
    vAufgabe_2();
    vAufgabe_4();

    return 0;
}
