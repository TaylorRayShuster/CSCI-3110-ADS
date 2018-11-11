/*
Taylor Ray Shuster
CSCI 3110-001
Project #3
Due: 10/05/2018
*/
#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include "ship.h"

class CruiseShip : public Ship
{
private:
	double perLuxury;
	double perUpper;
	double perLower;
	int luxury;
	int upper;
	int lower;
public:
	CruiseShip(std::string, double, double, double, double);
	void sail();
	void load(int);
};
#endif