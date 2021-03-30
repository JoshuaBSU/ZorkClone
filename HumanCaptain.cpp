#include "HumanCaptain.h"

HumanCaptain::HumanCaptain(std::string name, Room* room)
{
	this->name = name;
	this->currentRoom = room;

	this->xpVal = 50;
	this->gold = 25;

	//default skills
	this->sFighting = 6;
	this->sShooting = 2;

	this->enemyType = "human captain";

	//attributes determined by parent class (Human)
	//health determined by parent class (Human)
}


HumanCaptain::~HumanCaptain()
{
}
