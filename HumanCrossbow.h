#pragma once
#include "Human.h"
class HumanCrossbow :
	public Human
{
public:
	HumanCrossbow(std::string name, Room* room);
	~HumanCrossbow();
};

