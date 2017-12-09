#include <iostream>
#include "Vaerelser.h"
//#include "Vaerelse.h"
#include "Reservation.h"

using namespace std;


int main() {

	// Opret hotel
	Reservation hotel;
	Vaerelser vaerelser;

	// Opret værelser
	Vaerelse v1(1, 1000);
	vaerelser.addRoom(v1);
	Vaerelse v2(2, 280);
	vaerelser.addRoom(v2);
	Vaerelse v3(3, 330);
	vaerelser.addRoom(v3);
	Vaerelse v4(4, 700);
	vaerelser.addRoom(v4);
	Vaerelse v5(5, 860);
	vaerelser.addRoom(v5);
	Vaerelse v6(6, 940);
	vaerelser.addRoom(v6);
	Vaerelse v7(7, 1120);
	vaerelser.addRoom(v7);
	Vaerelse v8(8, 940);
	vaerelser.addRoom(v8);
	Vaerelse v9(9, 1565);
	vaerelser.addRoom(v9);
	Vaerelse v10(10, 1700);
	vaerelser.addRoom(v10);
	Vaerelse v11(11, 375);
	vaerelser.addRoom(v11);
	Vaerelse v12(12, 2000);
	vaerelser.addRoom(v12);
	Vaerelse v13(13, 2000);
	vaerelser.addRoom(v13);
	Vaerelse v14(14, 1780);
	vaerelser.addRoom(v14);
	Vaerelse v15(15, 990);
	vaerelser.addRoom(v15);
	
	hotel.addPrisklasser(vaerelser);
	
	// Gæster
	Gaest john("John", 19741209, 100);
	Gaest jared("Jared", 19720412, 101);

	// Se priser
	hotel.printPrisklasser();

	int res1 = hotel.makeReservation(john, 'A', 20171220, 20171224);
	int res2 = hotel.makeReservation(jared, 'A', 20171218, 20171229);
	int res3 = hotel.makeReservation(john, 'B', 20171220, 20171224);
	int res4 = hotel.makeReservation(jared, 'B', 20171222, 20171228);
	int res5 = hotel.makeReservation(john, 'C', 20171220, 20171224);
	int res6 = hotel.makeReservation(jared, 'E', 20171222, 20171228);
	int res7 = hotel.makeReservation(john, 'B', 20171220, 20171224);
	int res8 = hotel.makeReservation(jared, 'A', 20171229, 20171231);
	
	cout << endl << std::string(50, '*') << endl << endl;

	hotel.printRes();

	cout << std::string(50, '*') << endl << endl;

	hotel.cancleRes(res1);
	hotel.cancleRes(res2);
	hotel.cancleRes(res2);
	hotel.cancleRes(res7);
	hotel.cancleRes(res5);

	cout << std::string(50, '*') << endl << endl;

	hotel.printRes();

	cout << std::string(50, '*') << endl << endl;
	
	hotel.makeReservation(john, 'B', 20171220, 20171224);
	hotel.makeReservation(jared, 'B', 20171222, 20171228);
	hotel.makeReservation(john, 'C', 20171220, 20171224);
	hotel.makeReservation(jared, 'E', 20171222, 20171228);
	hotel.makeReservation(john, 'B', 20171220, 20171224);
	hotel.makeReservation(jared, 'A', 20171229, 20171231);

	hotel.printRes();

	return 0;
}