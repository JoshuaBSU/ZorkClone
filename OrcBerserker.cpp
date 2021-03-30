#include "OrcBerserker.h"



OrcBerserker::OrcBerserker(std::string name, Room* room)
{
	this->name = name;
	this->currentRoom = room;

	this->xpVal = 35;
	this->gold = 30;

	//default skills
	this->sFighting = 8;
	this->sShooting = 2;

	this->enemyType = "orc berserker";

	//attributes determined by parent class (Orc)
	//health determined by parent class (Orc)
}


OrcBerserker::~OrcBerserker()
{
}
