#pragma once
#include "Kobold.h"
class KoboldStabber :
	public Kobold
{
public:
	KoboldStabber(std::string name, Room* room);
	~KoboldStabber();
};

