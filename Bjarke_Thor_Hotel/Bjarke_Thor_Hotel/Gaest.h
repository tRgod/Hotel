#pragma once
/*
Portefoelje 3, C++.
Bjarke Larsen
Thor Moeller Roerdal
*/

#include <string>

class Gaest
{
public:
	Gaest();
	Gaest(std::string, int, int);

	std::string getNavn();
	int getId();
	int getFdag();

	~Gaest();

protected:
	std::string navn;
	int fDag;
	int id;
};

