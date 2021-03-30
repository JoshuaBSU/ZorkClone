#include "KoboldHunter.h"



KoboldHunter::KoboldHunter(std::string name, Room* room)
{
	this->name = name;
	this->currentRoom = room;

	this->xpVal = 10;
	this->gold = 10;

	//default skills
	this->sFighting = 4;
	this->sShooting = 4;

	this->enemyType = "kobold hunter";

	//attributes determined by parent class (Kobold)
	//health determined by parent class (Kobold)
}


KoboldHunter::~KoboldHunter()
{
}
