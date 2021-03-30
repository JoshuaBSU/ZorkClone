#pragma once
#include "Kobold.h"
class KoboldHunter :
	public Kobold
{
public:
	KoboldHunter(std::string name, Room* room);
	~KoboldHunter();
};

