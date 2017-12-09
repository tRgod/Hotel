#include "Reservation.h"
#include <string>
#include <iostream>


Reservation::Reservation()
{
}

void Reservation::makeReservation(Gaest& gaestIn, Vaerelser& vIn, int datoFraIn, int datoTilIn)
{
	/*
	Opgaver:

	Sorter i X forskellige prisklasser.

	Tjek også for om fra og til datoer er på hver side af en eksisterende booking.

	Gør listen med værelser tilgængelige i reservationer uden at tilføje til makeReservation().
	*/

	bool bookSuccess = false;

	for (int i = 0; i < vIn.getVvec().size(); i++)
	{
		if (isAvailable(vIn.getVvec()[i].getVnummer(), datoFraIn, datoTilIn))
		{
			reservationer.push_back({ gaestIn.getId(), vIn.getVvec()[i].getVnummer(), datoFraIn, datoTilIn });
			bookSuccess = true;
			break;
		}
	}

	if (bookSuccess)
		std::cout << "Room booked." << std::endl;
	else
		std::cout << "No rooms available." << std::endl;


}

void Reservation::addPrisklasser(Vaerelser& vIn)
{
	prisKlasseA = vIn.getKlasseA();
	prisKlasseB = vIn.getKlasseB();
	prisKlasseC = vIn.getKlasseC();
	prisKlasseD = vIn.getKlasseD();
	prisKlasseE = vIn.getKlasseE();

}

bool Reservation::isAvailable(int vaerelseIn, int datoFraIn, int datoTilIn)
{
	
	for (int i = 0; i < reservationer.size(); i++)
	{
		if (vaerelseIn == reservationer[i][1])
		{
			if ((datoFraIn <= reservationer[i][3] && datoFraIn >= reservationer[i][2]) || 
				(datoTilIn <= reservationer[i][3] && datoTilIn >= reservationer[i][2]) 
				/*(datoFraIn< reservationer[i][3] && datoTilIn>reservationer[i][2])*/)
			{
				return false;	//Tjekker ikke hvis en booking "indeholder" en anden.
			}
		}
	}
	return true;
}

std::vector<std::array<int, 4>> Reservation::getReservationer()
{
	return reservationer;
}


Reservation::~Reservation()
{
}
