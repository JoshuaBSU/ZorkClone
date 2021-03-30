#pragma once
#include "Human.h"

class HumanCaptain :
	public Human
{
public:
	HumanCaptain(std::string name, Room* room);
	~HumanCaptain();
};

