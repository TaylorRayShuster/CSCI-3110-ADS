/*
Taylor Ray Shuster
CSCI 3110-001
Project #3
Due: 10/05/2018
*/
#include "cruiseship.h"
#include <iostream>

CruiseShip::CruiseShip(std::string name, double fuel, double lux, double up, double low)
	: Ship(name, fuel)
{
	this->perLuxury = lux;
	this->perUpper = up;
	this->perLower = low;
}

void CruiseShip::sail()
{
	std::cout << this->name << " sailing: " << this->luxury << " in Luxury, " << this->upper << " in Upper Deck, and " << this->lower << " in Lower Deck" << std::endl;
}

void CruiseShip::load(int passengers)
{
	this->luxury = (this->perLuxury * passengers);
	this->upper = (this->perUpper * passengers);
	this->lower = (this->perLower * passengers);
}