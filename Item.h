#pragma once
#include <string>

class Item
{
public:
	Item();
	~Item();
	std::string getName();
	int getValue();
	bool getEdibility();

	void setDescription(std::string flavortext);
	std::string getDescription();

	bool getEquipable();
	std::string getEquipCat();

	//make it so this item unlocks a specific door
	void setLockID(int lock);
	int getLockID();

protected:
	std::string name;
	bool consumable;
	int value;
	
	bool equipable;
	std::string equipCat;

	std::string description;
	int lockID;

};

