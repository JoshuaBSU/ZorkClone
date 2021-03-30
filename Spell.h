#pragma once
#include <string>

class Spell
{
public:
	Spell(std::string name, std::string effect, int potency, int manaCost);
	~Spell();

	std::string getName();
	std::string getEffect();
	int getPotency();
	int getManaCost();

private:
	std::string name;
	std::string effect;		//ex. heal, damage
	int potency;
	int manaCost;
};

