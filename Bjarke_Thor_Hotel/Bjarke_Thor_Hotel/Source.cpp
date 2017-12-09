#include <iostream>
#include "Vaerelser.h"
//#include "Vaerelse.h"
#include "Reservation.h"

using namespace std;


int main() {

	Reservation hotel;

	Gaest john("John", 19741209, 27);
	Gaest jared("Jared", 19720412, 28);

	Vaerelser vaerelser;

	Vaerelse v1(1, 1020);
	vaerelser.addRoom(v1);
	Vaerelse v2(2, 324);
	vaerelser.addRoom(v2);
	Vaerelse v3(3, 200.75);
	vaerelser.addRoom(v3);
	Vaerelse v4(4, 22324.765432);
	vaerelser.addRoom(v4);
	Vaerelse v5(5, 5000);
	vaerelser.addRoom(v5);
	Vaerelse v6(6, 2235);
	vaerelser.addRoom(v6);
	Vaerelse v7(7, 543.5);
	vaerelser.addRoom(v7);
	Vaerelse v8(8, 1323.5);
	vaerelser.addRoom(v8);
	Vaerelse v9(9, 1444);
	vaerelser.addRoom(v9);
	Vaerelse v10(10, 12230.5);
	vaerelser.addRoom(v10);
	Vaerelse v11(11, 100025);
	vaerelser.addRoom(v11);
	Vaerelse v12(12, 1304);
	vaerelser.addRoom(v12);
	Vaerelse v13(13, 13041);
	vaerelser.addRoom(v13);

	hotel.addPrisklasser(vaerelser);


	for (int i = 0; i < vaerelser.getVvec().size(); i++)
	{
		cout << "Varelses nr: " << vaerelser.getVvec()[i].getVnummer() << " | Pris: " << vaerelser.getVvec()[i].getPris() << endl;
	}

	cout << endl;

	hotel.makeReservation(john, 'A', 20171220, 20171224);
	hotel.makeReservation(jared, 'A', 20171222, 20171228);
	
	hotel.makeReservation(john, 'B', 20171220, 20171224);
	hotel.makeReservation(jared, 'B', 20171222, 20171228);
	hotel.makeReservation(john, 'C', 20171220, 20171224);
	hotel.makeReservation(jared, 'E', 20171222, 20171228);
	hotel.makeReservation(john, 'B', 20171220, 20171224);
	hotel.makeReservation(jared, 'A', 20171229, 20171231);

	cout << "Vaerelse: " << hotel.getReservationer()[0][1] << " Fra: " << hotel.getReservationer()[0][2] << " Til: " << hotel.getReservationer()[0][3] << endl;
	cout << "Vaerelse: " << hotel.getReservationer()[1][1] << " Fra: " << hotel.getReservationer()[1][2] << " Til: " << hotel.getReservationer()[1][3] << endl;
	cout << "Vaerelse: " << hotel.getReservationer()[2][1] << " Fra: " << hotel.getReservationer()[2][2] << " Til: " << hotel.getReservationer()[2][3] << endl;
	cout << "Vaerelse: " << hotel.getReservationer()[3][1] << " Fra: " << hotel.getReservationer()[3][2] << " Til: " << hotel.getReservationer()[3][3] << endl;
	cout << "Vaerelse: " << hotel.getReservationer()[4][1] << " Fra: " << hotel.getReservationer()[4][2] << " Til: " << hotel.getReservationer()[4][3] << endl;
	cout << "Vaerelse: " << hotel.getReservationer()[5][1] << " Fra: " << hotel.getReservationer()[5][2] << " Til: " << hotel.getReservationer()[5][3] << endl;
	

	/*
	int datoFraIn = 181;
	int datoTilIn = 181;
	int datoTilFra = std::stoi(std::to_string(datoFraIn) + std::to_string(datoTilIn));
	cout << datoTilFra;
	*/
	


	/*
	string testSt = "Teststring";

	for (int i : testSt)
	{
		cout << (char)i << " ";
	}


	cout << vaerelser.getVvec()[0].getPris() << " " << vaerelser.getVvec()[0].getVnummer() << endl;
	*/
	return 0;
}