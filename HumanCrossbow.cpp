#include "HumanCrossbow.h"



HumanCrossbow::HumanCrossbow(std::string name, Room* room)
{
	this->name = name;
	this->currentRoom = room;

	this->xpVal = 10;
	this->gold = 10;

	//default skills
	this->sFighting = 2;
	this->sShooting = 4;

	this->enemyType = "human crossbowman";

	//attributes determined by parent class (Human)
	//health determined by parent class (Human)
}


HumanCrossbow::~HumanCrossbow()
{
}
