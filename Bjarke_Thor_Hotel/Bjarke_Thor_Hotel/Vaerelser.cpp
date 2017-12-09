#include "Vaerelser.h"
#include<iostream>


Vaerelser::Vaerelser()
{
}

void Vaerelser::addRoom(Vaerelse& vIn)
{
	const int x = vIn.getPris();


		if (x < 1000 && x>100)
		{
			klasseA.push_back(vIn);
		}
		if (x > 1000 && x < 2000)
		{
			klasseB.push_back(vIn);
		}
		if (x > 2000 && x < 3000)
		{
			klasseC.push_back(vIn);
		}
		if (x > 3000 && x < 4000)
		{
			klasseD.push_back(vIn);
		}
		if (x > 4000)
		{
			klasseE.push_back(vIn);
		}
}


void Vaerelser::listRoomClasses()
{
	
	
		for (int i = 0; i < klasseA.size(); i++)
		{
			std::cout << "Vaerelse Nr." << klasseA[i].getVnummer() << "Prisen:" << klasseA[i].getPris() <<"klasse A" << std::endl;
		}
		for (int i = 0; i < klasseB.size(); i++)
		{
			std::cout << "Vaerelse Nr." << klasseB[i].getVnummer() << "Prisen:" << klasseB[i].getPris() << "Klasse B"<<std::endl;
		}
		for (int i = 0; i < klasseC.size(); i++)
		{
			std::cout << "Vaerelse Nr." << klasseC[i].getVnummer() << "Prisen:" << klasseC[i].getPris()<<"Klasse C" << std::endl;
		}
		for (int i = 0; i < klasseD.size(); i++)
		{
			std::cout << "Vaerelse Nr." << klasseD[i].getVnummer() << "Prisen:" << klasseD[i].getPris() << "Klasse D"<< std::endl;
		}
		for (int i = 0; i < klasseE.size(); i++)
		{
			std::cout << "Vaerelse Nr. " << klasseE[i].getVnummer() << "Prisen: " << klasseE[i].getPris()<< "klasse E" << std::endl;
		}
	
	
}
std::vector<Vaerelse> Vaerelser::getVvec()
{
	return roomVec;
}

std::vector<Vaerelse> Vaerelser::getKlasseA()
{
	return klasseA;
}

std::vector<Vaerelse> Vaerelser::getKlasseB()
{
	return klasseB;
}

std::vector<Vaerelse> Vaerelser::getKlasseC()
{
	return klasseC;
}

std::vector<Vaerelse> Vaerelser::getKlasseD()
{
	return klasseD;
}

std::vector<Vaerelse> Vaerelser::getKlasseE()
{
	return klasseE;
}




Vaerelser::~Vaerelser()
{
}
