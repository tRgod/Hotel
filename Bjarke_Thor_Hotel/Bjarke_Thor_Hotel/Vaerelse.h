#pragma once
/*
Portefoelje 3, C++.
Bjarke Larsen
Thor Moeller Roerdal
*/

class Vaerelse
{
public:
	Vaerelse();
	Vaerelse(int, float);

	int getVnummer();
	float getPris();

	~Vaerelse();

protected:
	int		vNummer;
	float	pris;
};

