#pragma once
#include "Vampire.h"
class VampireLord :
	public Vampire
{
public:
	VampireLord(std::string name, Room* room);
	~VampireLord();
};

