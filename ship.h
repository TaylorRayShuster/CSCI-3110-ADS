/*
Taylor Ray Shuster
CSCI 3110-001
Project #3
Due: 10/05/2018
*/
#ifndef SHIP_H
#define SHIP_H

#include <string>

class Ship
{
protected:
	std::string name;
	double fuelOnBoard;
public:
	Ship(std::string, double);
	void fuel();
	virtual void sail();
	virtual void load(int) = 0;
};
#endif