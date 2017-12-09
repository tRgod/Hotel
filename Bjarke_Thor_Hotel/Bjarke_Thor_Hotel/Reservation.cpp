#include "Reservation.h"
#include <string>
#include <iostream>
#include "Dato.h"
#include <iomanip>


Reservation::Reservation()
{
}

int Reservation::makeReservation(Gaest& gaestIn, char prisIn, int datoFraIn, int datoTilIn)
{
	/*
	Opgaver:

	Sorter i X forskellige prisklasser.

	Tjek også for om fra og til datoer er på hver side af en eksisterende booking.

	Gør listen med værelser tilgængelige i reservationer uden at tilføje til makeReservation().
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
			reservationer.push_back({ gaestIn.getId(), (*prisklasseV)[i].getVnummer(), datoFraIn, datoTilIn, resNum });
			bookSuccess = true;
			break;
		}
	}

	if (bookSuccess)
	{
		resNum++;
		return resNum -1;
	}
	else 
	{
		return 0;
	}
}

void Reservation::cancleRes(int resNr)
{
	
	for (int i = 0; i < reservationer.size(); i++)
	{
		
		if (reservationer[i][4] == resNr)
		{
			reservationer.erase(reservationer.begin() + delNum);
			std::cout << "Reservation Nr. " << resNr << " er anulleret."<< std::endl;
			std::cout << std::endl;
		}
		else
		{
			delNum++;
			//std::cout << "Ingen Reservation med Resvertions nummer #" << resNr << std::endl;
			//std::cout << std::endl;
		}
		
	}
	delNum = 0;
}

void Reservation::addPrisklasser(Vaerelser& vIn)
{
	prisKlasseA = vIn.getKlasseA();
	prisKlasseB = vIn.getKlasseB();
	prisKlasseC = vIn.getKlasseC();
	prisKlasseD = vIn.getKlasseD();
	prisKlasseE = vIn.getKlasseE();
}

void Reservation::printRes()
{
	for (int i = 0; i < reservationer.size(); i++)
	{
		Dato datoFra(reservationer[i][2]);
		Dato datoTil(reservationer[i][3]);

		std::cout << "Vaerelse nr: " << reservationer[i][1] << std::endl;
		std::cout << "Udlejet fra den ";
		datoFra.print();
		std::cout << "Til den ";
		datoTil.print();
		std::cout << std::endl;
	}
}

void Reservation::printPrisklasser()
{
	std::cout << "Prisklasse A:" << std::endl << "(100 - 499)" << std::endl;
	for (int i = 0; i < prisKlasseA.size(); i++)
	{
		std::cout << "Vaerelse nr. " << setw(3) << prisKlasseA[i].getVnummer() << " | Pris: " << setw(4) << prisKlasseA[i].getPris() << std::endl;
	}

	cout << endl;

	std::cout << "Prisklasse B:" << std::endl << "(500 - 999)" << std::endl;
	for (int i = 0; i < prisKlasseB.size(); i++)
	{
		std::cout << "Vaerelse nr. " << setw(3) << prisKlasseB[i].getVnummer() << " | Pris: " << setw(4) << prisKlasseB[i].getPris() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Prisklasse C:" << std::endl << "(1000 - 1499)" << std::endl;
	for (int i = 0; i < prisKlasseC.size(); i++)
	{
		std::cout << "Vaerelse nr. " << setw(3) << prisKlasseC[i].getVnummer() << " | Pris: " << setw(4) << prisKlasseC[i].getPris() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Prisklasse D:" << std::endl << "(1500 - 1999)" << std::endl;
	for (int i = 0; i < prisKlasseD.size(); i++)
	{
		std::cout << "Vaerelse nr. " << setw(3) << prisKlasseD[i].getVnummer() << " | Pris: " << setw(4) << prisKlasseD[i].getPris() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Prisklasse E:" << std::endl << "(2000)" << std::endl;
	for (int i = 0; i < prisKlasseE.size(); i++)
	{
		std::cout << "Vaerelse nr. " << setw(3) << prisKlasseE[i].getVnummer() << " | Pris: " << setw(4) << prisKlasseE[i].getPris() << std::endl;
	}
}

bool Reservation::isAvailable(int vaerelseIn, int datoFraIn, int datoTilIn)
{
	
	for (int i = 0; i < reservationer.size(); i++)
	{
		if (vaerelseIn == reservationer[i][1])
		{
			if ((datoFraIn <= reservationer[i][3] && datoFraIn >= reservationer[i][2]) || 
				(datoTilIn <= reservationer[i][3] && datoTilIn >= reservationer[i][2]) ||
				(datoFraIn< reservationer[i][3] && datoTilIn>reservationer[i][2]))
			{
				return false;
			}
		}
	}
	return true;
}

std::vector<std::array<int, 5>> Reservation::getReservationer()
{
	return reservationer;
}


Reservation::~Reservation()
{
}
