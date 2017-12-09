#pragma once
#include <vector>
//#include <array>
#include "Vaerelse.h"

class Vaerelser
{
public:
	Vaerelser();

	void addRoom(Vaerelse&);
	void listRoomClasses();
	std::vector<Vaerelse> getKlasseA();
	std::vector<Vaerelse> getKlasseB();
	std::vector<Vaerelse> getKlasseC();
	std::vector<Vaerelse> getKlasseD();
	std::vector<Vaerelse> getKlasseE();


	~Vaerelser();

protected:
	std::vector<Vaerelse>	roomVec;
	std::vector<Vaerelse>   roomVec2;
	std::vector<int> datoArray[10];
	std::vector<Vaerelse> klasseA;
	std::vector<Vaerelse> klasseB;
	std::vector<Vaerelse> klasseC;
	std::vector<Vaerelse> klasseD;
	std::vector<Vaerelse> klasseE;
};

