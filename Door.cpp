#include "Door.h"



Door::Door(bool open, bool unlocked, int lockID)
{
	this->open = open;
	this->unlocked = unlocked;
	this->lockID = lockID;
}


Door::~Door()
{
}

void Door::setOpen(bool status)
{
	this->open = status;
}
void Door::setUnlocked(bool status)
{
	this->unlocked = status;
}

bool Door::getOpen()
{
	return this->open;
}
bool Door::getUnlocked()
{
	return this->unlocked;
}

int Door::getLockID()
{
	return this->lockID;
}