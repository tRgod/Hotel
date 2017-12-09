#pragma once
#include <vector>
#include <array>
#include "Gaest.h"
#include "Vaerelser.h"

class Reservation
{
public:
	Reservation();

	void makeReservation(Gaest& gaestIn, Vaerelser& vIn, int datoFraIn, int datoTilIn);

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

