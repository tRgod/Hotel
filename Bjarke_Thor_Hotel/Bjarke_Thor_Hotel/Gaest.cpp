#include "Gaest.h"



Gaest::Gaest()
{
}

Gaest::Gaest(std::string navnIn, int dagIn, int idIn)
{
	navn = navnIn;
	fDag = dagIn;
	id = idIn;
}

std::string Gaest::getNavn()
{
	return navn;
}

int Gaest::getId()
{
	return id;
}

int Gaest::getFdag()
{
	return fDag;
}


Gaest::~Gaest()
{
}
