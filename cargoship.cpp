/*
Taylor Ray Shuster
CSCI 3110-001
Project #3
Due: 10/05/2018
*/
#include "cargoship.h"
#include <iostream>

CargoShip::CargoShip(std::string name, double fuel, int capacity)
	:Ship(name, fuel)
{
	this->maxLoad = capacity;
	this->aft = new double;
	this->forward = new double;
	*(this->aft) = 0;
	*(this->forward) = 0;
}

CargoShip::~CargoShip()
{
	delete this->aft;
	delete this->forward;
}

void CargoShip::fuel(int flashpoint)
{
	std::cout << this->name << " fuel: " << this->fuelOnBoard << " tons" << std::endl;
	std::cout << this->name << " verified fuel flashpoint > " << flashpoint << " degrees" << std::endl;
}

void CargoShip::load(int load)
{
	if (load > this->maxLoad)
		load = this->maxLoad;

	*(this->forward) = (load * .56);
	*(this->aft) = (load * .44);

	std::cout << this->name << " Loading...Adjusting CG..." << *(this->forward) << " tons in FWD Bay, " << *(this->aft) << " tons in AFT Bay" << std::endl;
}
