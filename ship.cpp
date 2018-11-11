/*
Taylor Ray Shuster
CSCI 3110-001
Project #3
Due: 10/05/2018
*/
#include "ship.h"
#include <iostream>

Ship::Ship(std::string name, double fuel)
{
	this->name = name;
	this->fuelOnBoard = fuel;
}

void Ship::fuel()
{
	std::cout << this->name << " fuel: " << this->fuelOnBoard << " tons" << std::endl;
}

void Ship::sail()
{
	std::cout << "Ship sailing" << std::endl;
}