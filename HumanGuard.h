#pragma once
#include "Human.h"
class HumanGuard :
	public Human
{
public:
	HumanGuard(std::string name, Room* room);
	~HumanGuard();
};

