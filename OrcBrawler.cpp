#include "OrcBrawler.h"



OrcBrawler::OrcBrawler(std::string name, Room* room)
{
	this->name = name;
	this->currentRoom = room;

	this->xpVal = 60;
	this->gold = 40;

	//default skills
	this->sFighting = 12;
	this->sShooting = 2;

	this->enemyType = "orc brawler";

	//attributes determined by parent class (Orc)
	//health determined by parent class (Orc)
}


OrcBrawler::~OrcBrawler()
{
}
