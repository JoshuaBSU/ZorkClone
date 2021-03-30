#include "HumanGuard.h"



HumanGuard::HumanGuard(std::string name, Room* room)
{
	this->name = name;
	this->currentRoom = room;

	this->xpVal = 10;
	this->gold = 10;

	//default skills
	this->sFighting = 4;
	this->sShooting = 2;

	this->enemyType = "human guard";

	//attributes determined by parent class (Human)
	//health determined by parent class (Human)
}


HumanGuard::~HumanGuard()
{
}
