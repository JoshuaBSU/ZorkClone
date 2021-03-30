#pragma once
#include "Item.h"
class Artifact :
	public Item
{
public:
	Artifact(std::string name, int value);
	~Artifact();
};

