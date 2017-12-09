#include "Reservation.h"
#include <string>
#include <iostream>


Reservation::Reservation()
{
}

void Reservation::makeReservation(Gaest& gaestIn, char prisIn, int datoFraIn, int datoTilIn)
{
	/*
	Opgaver:

	Sorter i X forskellige prisklasser.

	Tjek ogs� for om fra og til datoer er p� hver side af en eksisterende booking.

	G�r listen med v�relser tilg�ngelige i reservationer uden at tilf�je til makeReservation().
	*/

	bool bookSuccess = false;
	std::vector<Vaerelse>* prisklasseV = NULL;

	switch (prisIn)
	{
	case 'A':
		prisklasseV = &prisKlasseA;
		break;
	case 'B':
		prisklasseV = &prisKlasseB;
		break;
	case 'C':
		prisklasseV = &prisKlasseC;
		break;
	case 'D':
		prisklasseV = &prisKlasseD;
		break;
	case 'E':
		prisklasseV = &prisKlasseE;
		break;
	default:
		prisklasseV = &prisKlasseA;
		break;
	}


	for (int i = 0; i < prisklasseV->size(); i++)
	{
		if (isAvailable((*prisklasseV)[i].getVnummer(), datoFraIn, datoTilIn))
		{
			reservationer.push_back({ gaestIn.getId(), (*prisklasseV)[i].getVnummer(), datoFraIn, datoTilIn });
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
			if ((datoFraIn <= reservationer[i][3] && datoFraIn >= reservationer[i][2]) || (datoTilIn <= reservationer[i][3] && datoTilIn >= reservationer[i][2]))
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
