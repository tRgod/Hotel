#pragma once


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

