/*
Taylor Ray Shuster
CSCI 3110-001
Project #2
Due: 09/19/18

In this assignment you will create a class representing a gasoline pump. The pump will maintain a running total of the
amount of fuel dispensed and revenues collected. The driver program will simulate fuel demand for a number of
vehicles.
*/
#include "gaspump.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int rnd = 0;
	int randAmount = 0;
	GasPump unleaded = GasPump("Unleaded", 200, 2.82);
	GasPump midgrade = GasPump("Midgrade", 125, 2.97);
	GasPump premium = GasPump("Premium+", 100, 3.24);

	GasPump * currentPump = nullptr;

	srand(1000);

	for (int i = 1; i <= 50; i++)
	{
		cout << "Vehicle " << i;
		currentPump = &unleaded;
		rnd = std::rand();
		if ((rnd % 7) == 4 || (rnd % 7) == 5)
		{
			currentPump = &midgrade;
		}
		else if ((rnd % 7) == 6)
		{
			currentPump = &premium;
		}
		randAmount = rand() % 5 + 0;
		switch (randAmount)
		{
		case 0: currentPump->dispenseFuel(30); break;
		case 1: currentPump->dispenseFuel(35); break;
		case 2: currentPump->dispenseFuel(40); break;
		case 3: currentPump->dispenseFuel(45); break;
		case 4: currentPump->dispenseFuel(50); break;
		case 5: currentPump->dispenseFuel(55); break;
		}
	}
	currentPump = &unleaded;
	cout << "Pump " << currentPump->getType() << " dispensed "<< currentPump->getDispensed() << " gallons and collected " << currentPump->getMoney() << endl;
	currentPump = &midgrade;
	cout << "Pump " << currentPump->getType() << " dispensed " << currentPump->getDispensed() << " gallons and collected " << currentPump->getMoney() << endl;
	currentPump = &premium;
	cout << "Pump " << currentPump->getType() << " dispensed " << currentPump->getDispensed() << " gallons and collected " << currentPump->getMoney() << endl;


	return 0;
}