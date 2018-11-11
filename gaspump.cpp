/*
Taylor Ray Shuster
CSCI 3110-001
Project #2
Due: 09/19/18

In this assignment you will create a class representing a gasoline pump. The pump will maintain a running total of the
amount of fuel dispensed and revenues collected. The driver program will simulate fuel demand for a number of
vehicles.
*/
#include <iostream>
#include "gaspump.h"
#include <string>

using std::cout;
using std::endl;

/*
	Constructor for Gaspump. Takes initial values from driver program and initiates all needed variables.
*/

GasPump::GasPump(string type, double capacity, double price)
{
		gasType = type;
		gasCapacity = capacity;
		gasPrice = price;
		gasRemaining = capacity;
		turnAway = false;
		gasMoney = 0;
		gasDispensed = 0;
}

/*
	dispenseFuel is the primary function of the entire program.
*/

void GasPump::dispenseFuel(double purchasePrice)
{
	cout << std::fixed;
	cout.precision(2);
	if (this->turnAway == true)
	{
		cout << " " << this->getType() << " Turned Away (out of gas)";
		replenishFuel();
		this->turnAway = false;
		return;
	}
	this->gasPurchase = ((1 / this->gasPrice) * purchasePrice);
	if ((this->gasPurchase) > this->gasRemaining)
	{
		this->gasPurchase = this->gasRemaining;
		this->turnAway = true;
		cout << " " << this->getType() << " Pumped only $" << (this->gasPurchase * this->gasPrice) << " of $" << purchasePrice << " - " << this->gasPurchase << " gallons" << endl;
	}
	else if (this->gasPurchase <= this->gasRemaining)
	{
		cout << " " << this->gasType << " Purchased $" << purchasePrice << " - " << this->gasPurchase << " gallons" << endl;
	}

	this->gasRemaining -= this->gasPurchase;
	this->gasDispensed += this->gasPurchase;
	this->gasMoney += (this->gasPurchase * this->gasPrice);
	return;
}

/*
	replenishFuel resets the gasRemaining to gasCapacity and prints out a statement of completion.
*/

void GasPump::replenishFuel()
{
	gasRemaining = gasCapacity;
	cout << "...Tank replenished." << endl;
	return;
}