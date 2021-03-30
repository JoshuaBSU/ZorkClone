#include "SkeletonWarrior.h"



SkeletonWarrior::SkeletonWarrior(std::string name, Room* room)
{
	this->name = name;
	this->currentRoom = room;

	this->xpVal = 5;
	this->gold = 0;

	//default skills
	this->sFighting = 4;
	this->sShooting = 2;

	this->enemyType = "skeleton warrior";
}


SkeletonWarrior::~SkeletonWarrior()
{
}
