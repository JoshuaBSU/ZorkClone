#include "KoboldStealer.h"



KoboldStealer::KoboldStealer(std::string name, Room* room)
{
	this->name = name;
	this->currentRoom = room;

	this->xpVal = 10;
	this->gold = 50;

	//default skills
	this->sFighting = 6;
	this->sShooting = 2;

	this->enemyType = "kobold stealer";

	//attributes determined by parent class (Kobold)
	//health determined by parent class (Kobold)
}


KoboldStealer::~KoboldStealer()
{
}
