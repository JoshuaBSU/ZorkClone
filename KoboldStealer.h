#pragma once
#include "Kobold.h"
class KoboldStealer :
	public Kobold
{
public:
	KoboldStealer(std::string name, Room* room);
	~KoboldStealer();
};

