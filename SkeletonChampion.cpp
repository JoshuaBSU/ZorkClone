#include "SkeletonChampion.h"



SkeletonChampion::SkeletonChampion(std::string name, Room* room)
{
	this->name = name;
	this->currentRoom = room;

	this->xpVal = 15;
	this->gold = 10;

	//default skills
	this->sFighting = 6;
	this->sShooting = 1;

	this->enemyType = "skeleton champion";
}


SkeletonChampion::~SkeletonChampion()
{
}
