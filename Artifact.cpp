#include "Artifact.h"

Artifact::Artifact(std::string name, int value)
{
	this->name = name;
	this->value = value;
	this->consumable = false;
	this->equipable = false;
}

Artifact::~Artifact()
{
}
