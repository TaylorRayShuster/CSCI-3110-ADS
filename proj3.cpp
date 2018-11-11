/*
Taylor Ray Shuster
CSCI 3110-001
Project #3
Due: 10/05/2018

In this assignment you will create a class representing a ship, and create two additional classes that inherit from the Ship
class, a CargoShip class and a CruiseShip class. The project is geared to give you practical experience with characteristics
and C++ implementation details of inheritance and polymorphism.
*/
#include "cargoship.h"
#include "cruiseship.h"
#include "ship.h"

void sailShip(Ship&);

int main()
{
	CruiseShip cruise = CruiseShip("Carnival", 300, 0.2, 0.35, 0.45);
	cruise.fuel();
	cruise.load(4000);
	sailShip(cruise);

	CargoShip cargo = CargoShip("Iron Maiden", 650, 1000);
	cargo.fuel(46);
	cargo.load(900);
	sailShip(cargo);

	return 0;
}

void sailShip(Ship& ship)
{
	ship.sail();
	return;
}