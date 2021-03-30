#include "OrcWarrior.h"



OrcWarrior::OrcWarrior(std::string name, Room* room)
{
	this->name = name;
	this->currentRoom = room;

	this->xpVal = 25;
	this->gold = 20;

	//default skills
	this->sFighting = 6;
	this->sShooting = 2;

	this->enemyType = "orc warrior";

	//attributes determined by parent class (Orc)
	//health determined by parent class (Orc)
}


OrcWarrior::~OrcWarrior()
{
}
