#pragma once
#include <vector>
#include <array>
#include "Gaest.h"
#include "Vaerelser.h"

class Reservation
{
public:
	Reservation();

	/*
	makeReservation skal return int som er reservationsNr.
	Dette sættes ind på reservationer som 5. element.
	Dette tal gives ved cancel res og finder den på listen og sletter den.
	*/

	void makeReservation(Gaest& gaestIn, char prisIn, int datoFraIn, int datoTilIn);

	void addPrisklasser(Vaerelser& vIn);

	bool isAvailable(int, int, int);

	std::vector<std::array<int, 4>> getReservationer();
	~Reservation();

protected:
	std::vector<std::array<int, 4>> reservationer;
	std::vector<Vaerelse> prisKlasseA;
	std::vector<Vaerelse> prisKlasseB;
	std::vector<Vaerelse> prisKlasseC;
	std::vector<Vaerelse> prisKlasseD;
	std::vector<Vaerelse> prisKlasseE;
};

