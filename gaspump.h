/*
Taylor Ray Shuster
CSCI 3110-001
Project #2
Due: 09/19/18

In this assignment you will create a class representing a gasoline pump. The pump will maintain a running total of the
amount of fuel dispensed and revenues collected. The driver program will simulate fuel demand for a number of
vehicles.
*/

#ifndef GASPUMP_H
#define GASPUMP_H

#include <string>

using std::string;

class GasPump
{
public:
	GasPump(string, double, double);
	string getType()
	{ return gasType; }
	double getDispensed()
	{ return gasDispensed; }
	double getMoney()
	{ return gasMoney; }
	void dispenseFuel(double);
private:
	string gasType;
	double gasRemaining;
	double gasCapacity;
	double gasPrice;
	double gasPurchase;
	double gasDispensed;
	double gasMoney;
	bool turnAway;
	void replenishFuel();
};

#endif GASPUMP_H
