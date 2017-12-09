/*
Portefoelje 3, C++.
Bjarke Larsen
Thor Moeller Roerdal
*/
//
// Created by Bjarke Engsig Larsen on 06/09/2017.
//

#ifndef GENNEMGAAENDEEKSEMPEL_DATO_H
#define GENNEMGAAENDEEKSEMPEL_DATO_H

#include <string>
using namespace std;

class Dato {

public:
    Dato();
    Dato(int);          // Constructor
    int getDatoen();    // Metode
    int getAar();
    int getMaaned();
    int getDag();
    int getKvarta();
    bool getSkudaar();
    bool validate();
    int dagIAaret();
    int restDageIAaret();

    void setDatoPlusEn();
    void setDatoMinusEn();

    int forskelIDage(Dato enD); //F.eks. forskellen imellem en tilfældig dag og i dag. Lav nyt objekt med en dag mere.

    int ugedag();
    string ugedagTekst();

    void print();
    ~Dato();

private:

    int datoen;     //Format YYYYMMDD
    int aar;
    int maaned;
    int dag;
    int nyDatoFrem;
    int nyDatoTilbage;
};


#endif //GENNEMGAAENDEEKSEMPEL_DATO_H
