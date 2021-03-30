#pragma once
#include "Orc.h"
class OrcWarrior :
	public Orc
{
public:
	OrcWarrior(std::string name, Room* room);
	~OrcWarrior();
};

