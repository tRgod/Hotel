#include "Vaerelse.h"



Vaerelse::Vaerelse()
{
}

Vaerelse::Vaerelse(int nummerIn, float prisIn)
{
	pris = prisIn;
	vNummer = nummerIn;
}

int Vaerelse::getVnummer()
{
	return vNummer;
}

float Vaerelse::getPris()
{
	return pris;
}


Vaerelse::~Vaerelse()
{
}
