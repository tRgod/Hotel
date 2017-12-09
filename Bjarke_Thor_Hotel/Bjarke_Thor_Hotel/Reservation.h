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

