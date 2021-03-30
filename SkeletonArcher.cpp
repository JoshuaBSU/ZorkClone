#include "SkeletonArcher.h"



SkeletonArcher::SkeletonArcher(std::string name, Room* room)
{
	this->name = name;
	this->currentRoom = room;

	this->xpVal = 5;
	this->gold = 0;

	//default skills
	this->sFighting = 2;
	this->sShooting = 4;

	this->enemyType = "skeleton archer";
}


SkeletonArcher::~SkeletonArcher()
{
}
