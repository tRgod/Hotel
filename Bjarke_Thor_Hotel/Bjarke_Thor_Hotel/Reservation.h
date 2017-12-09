#pragma once
/*
Portefoelje 3, C++.
Bjarke Larsen
Thor Moeller Roerdal
*/

#include <vector>
#include <array>
#include "Gaest.h"
#include "Vaerelser.h"

class Reservation
{
public:
	Reservation();

	int makeReservation(Gaest& gaestIn, char prisIn, int datoFraIn, int datoTilIn);
	void cancleRes(int);

	void lavKvittering(int resNr);

	void addPrisklasser(Vaerelser& vIn);
	void printRes();
	void printPrisklasser();
	bool isAvailable(int, int, int);

	std::vector<std::array<int, 6>> getReservationer();
	~Reservation();

protected:
	int delNum = 0;
	int resNum = 1;
	std::vector<std::array<int, 6>> reservationer;
	std::vector<Vaerelse> prisKlasseA;
	std::vector<Vaerelse> prisKlasseB;
	std::vector<Vaerelse> prisKlasseC;
	std::vector<Vaerelse> prisKlasseD;
	std::vector<Vaerelse> prisKlasseE;
};

