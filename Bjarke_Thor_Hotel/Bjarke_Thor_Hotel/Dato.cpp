/*
Portefoelje 3, C++.
Bjarke Larsen
Thor Moeller Roerdal
*/
//
// Created by Bjarke Engsig Larsen on 06/09/2017.
//

#include "Dato.h"
#include <string>
#include <iostream>

using namespace std;

Dato::Dato(){

}

Dato::Dato(int enD) {
    datoen = enD;
    dag = datoen%100;
    maaned = (datoen%10000)/100;
    aar = datoen/10000;
}

int Dato::getDatoen() {
    return datoen;
}

Dato::~Dato() {

}

int Dato::getAar() {
    return aar;
}

int Dato::getMaaned() {
    return maaned;
}

int Dato::getDag() {
    return dag;
}

int Dato::getKvarta() {
    if (getMaaned() < 4)
        return 1;
    else if (getMaaned() < 7)
        return 2;
    else if (getMaaned() < 10)
        return 3;
    else
        return 4;
}

bool Dato::getSkudaar() {
    if ((getAar() % 4))
        return false;
    else if (getAar() % 100)
        return true;
    else if (getAar() % 400)
        return false;
    else
        return true;
}   //Ikke nødvendigt med så mange funktioner. F.eks. sidste else og to else if's.

bool Dato::validate() {
    if (aar > 0 && aar <= 9999) {
        if (maaned == 2) {
            if (getSkudaar()) {
                if (dag > 0 && dag <= 29)
                    return true;
                else
                    return false;
            } else if (dag > 0 && dag <= 28)
                    return true;
                else
                    return false;
            } else if (maaned == 1 || maaned == 3 || maaned == 5 || maaned == 7 || maaned == 8 || maaned == 10 || maaned == 12) {
            if (dag > 0 && dag <= 31)
                return true;
            else
                return false;
        } else if (maaned > 0 && maaned <= 12) {
            if (dag > 0 && dag <= 30)
                return true;
            else
                return false;
        } else
            return false;
    } else
        return false;
}       //Idé til metode: Test på alt hvad der skal return false og så kun lav en return true til sidst. Altså tjek om man skal return false før true.

//Når man bruger return i en if vil det nok være overflødigt med else.

int Dato::dagIAaret() {

    int optaelling = 0;

    for (int i = maaned - 1; i > 0; i--) {
        if (i == 2)
            (getSkudaar()) ? optaelling += 29 : optaelling += 28;   //Ternary operator (? og :) ... (Ikke en god idé)...
        else
            (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) ? optaelling += 31 : optaelling += 30;
    }

    int dagNummer = dag + optaelling;

    return dagNummer;
}

void Dato::print() {

    switch (maaned) {
        case 1:
            cout << to_string(dag) + ". Januar " + to_string(aar) << "." << endl;
            break;
        case 2:
            cout << to_string(dag) + ". Februar " + to_string(aar) << "." << endl;
            break;
        case 3:
            cout << to_string(dag) + ". Marts " + to_string(aar) << "." << endl;
            break;
        case 4:
            cout << to_string(dag) + ". April " + to_string(aar) << "." << endl;
            break;
        case 5:
            cout << to_string(dag) + ". Maj " + to_string(aar) << "." << endl;
            break;
        case 6:
            cout << to_string(dag) + ". Juni " + to_string(aar) << "." << endl;
            break;
        case 7:
            cout << to_string(dag) + ". Juli " + to_string(aar) << "." << endl;
            break;
        case 8:
            cout << to_string(dag) + ". August " + to_string(aar) << "." << endl;
            break;
        case 9:
            cout << to_string(dag) + ". September " + to_string(aar) << "." << endl;
            break;
        case 10:
            cout << to_string(dag) + ". Oktober " + to_string(aar) << "." << endl;
            break;
        case 11:
            cout << to_string(dag) + ". November " + to_string(aar) << "." << endl;
            break;
        case 12:
            cout << to_string(dag) + ". December " + to_string(aar) << "." << endl;
            break;
    }
}

int Dato::restDageIAaret() {
    int dageTilbage;
    (getSkudaar()) ? dageTilbage = 366 - dagIAaret() : dageTilbage = 365 - dagIAaret();
    return dageTilbage;
}

void Dato::setDatoPlusEn() {
	/*
	int nyDagFrem = dag;
    int nyMaanedFrem = maaned;
    int nyAarFrem = aar;
    if (!validate()) {
        cout << "Ikke en gyldig dato!" << endl;
        return;
    }
    if (nyMaanedFrem == 2) {
        if (getSkudaar()) {
            if (nyDagFrem < 29) {
                nyDagFrem++;
            } else {
                nyMaanedFrem++;
                nyDagFrem = 1;
            }
        } else {
            if (nyDagFrem < 28) {
                nyDagFrem++;
            } else {
                nyMaanedFrem++;
                nyDagFrem = 1;
            }
        }
    } else {
        if (nyMaanedFrem == 12) {
            if (nyDagFrem < 31) {
                nyDagFrem++;
            } else {
                nyAarFrem++;
                nyDagFrem = 1;
                nyMaanedFrem = 1;
            }
        } else {
            if (nyMaanedFrem == 1 || nyMaanedFrem == 3 || nyMaanedFrem == 5 || nyMaanedFrem == 7 || nyMaanedFrem == 8 || nyMaanedFrem == 10) {
                if (nyDagFrem < 31) {
                    nyDagFrem++;
                } else {
                    nyMaanedFrem++;
                    nyDagFrem = 1;
                }
            } else {
                if (nyDagFrem < 30) {
                    nyDagFrem++;
                } else {
                    nyMaanedFrem++;
                    nyDagFrem = 1;
                }
            }
        }
    }
    cout << "Dagen efter: " << nyAarFrem << " " << nyMaanedFrem << " " << nyDagFrem << endl;

    nyDatoFrem = ((nyAarFrem * 100) + nyMaanedFrem) * 100 + nyDagFrem;
    cout << nyDatoFrem << endl;

    //Problem med at den ikke kan tælle op to gange i træk...
	*/
	datoen++;
	dag = datoen % 100;
	maaned = (datoen % 10000) / 100;
	aar = datoen / 10000;
	while (!validate()) {
		datoen++;
		dag = datoen % 100;
		maaned = (datoen % 10000) / 100;
		aar = datoen / 10000;
	}
}

void Dato::setDatoMinusEn() {
	datoen--;
	dag = datoen % 100;
	maaned = (datoen % 10000) / 100;
	aar = datoen / 10000;
	while (!validate()) {
		datoen--;
		dag = datoen % 100;
		maaned = (datoen % 10000) / 100;
		aar = datoen / 10000;
	}
}

int Dato::forskelIDage(Dato enD) {


    int dageForskel = 0;
	if (enD.getDatoen() > getDatoen()) {
		while (enD.getDatoen() > datoen) {
			enD.setDatoMinusEn();
			dageForskel++;
		}
	}
	else {
		while (enD.getDatoen() < datoen) {
			enD.setDatoPlusEn();
			dageForskel++;
		}
	}
	return dageForskel;
}

int Dato::ugedag() {


    Dato udgDato(17000301);

    return udgDato.forskelIDage(Dato(datoen)) % 7 + 1; //Virker kun til at tælle fremad.



    /*
    //2017 09 11 var en mandag (1).
	int dagIUgen = 1;
	int testDag = 20170911;
	if (testDag > datoen) {
		while (testDag > datoen) {
			setDatoPlusEn();
			dagIUgen--;
			if (dagIUgen < 1)
				dagIUgen = 7;
		}
		return dagIUgen;
	}
	else {
		while (testDag < datoen) {
			testDag++;
			setDatoMinusEn();
			if (dagIUgen > 7)
				dagIUgen = 1;
		}
		dagIUgen--;
		if (dagIUgen < 1)
			dagIUgen = 7;
		return dagIUgen;
	}
	//Går ikke op.
     */
}

string Dato::ugedagTekst() {
	switch (ugedag()) {
	case 1:
		return "mandag";
	case 2:
		return "tirsdag";
	case 3:
		return "onsdag";
	case 4:
		return "torsdag";
	case 5:
		return "fredag";
	case 6:
		return "loerdag";
	case 7:
		return "soendag";
	}
	
}


