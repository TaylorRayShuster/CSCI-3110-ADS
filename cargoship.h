/*
Taylor Ray Shuster
CSCI 3110-001
Project #3
Due: 10/05/2018
*/
#ifndef CARGOSHIP_H
#define CARGOSHIP_H
#include "ship.h"

class CargoShip : public Ship
{
private:
	double * forward;
	double * aft;
	int maxLoad;
public:
	CargoShip(std::string, double, int);
	~CargoShip();
	void fuel(int);
	void load(int);
};
#endif