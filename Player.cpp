#include "Player.h"

Player::Player(std::string name, Room* currentRoom)
{
	this->name = name;
	this->currentRoom = currentRoom;
	this->currXP = 0;
	this->nextXP = 20;
	this->level = 1;

	//give player some starting health
	this->maxHealth = 25;
	this->currHealth = this->maxHealth;

	//give player some starting mana
	this->maxMana = 25;
	this->currMana = 25;

	//default attributes
	this->aDexterity = 5;
	this->aStrength = 5;

	//default skills
	this->sFighting = 10;
	this->sShooting = 10;
}

Player::~Player()
{
}

void Player::checkLevel()
{
	//while loop so end up leveling multiple times, in case player gets a LOT of xp
	while (this->currXP >= this->nextXP)
	{
		std::cout << std::endl << "You leveled up!" << std::endl;
		this->gainLevel();
	}
}

void Player::gainLevel()
{
	this->nextXP += nextXP;
	this->level += 1;

	//increase max health and mana as a result of gaining a level
	this->maxHealth += 1;
	this->maxMana += 1;
	//get healed as a result of gaining a level
	this->currHealth = this->maxHealth;
	this->currMana = this->maxMana;
}

void Player::displayPlayer()
{
	std::cout << std::endl << "Name: " << this->name << '\t' << "Health: " << this->currHealth << "/" << this->maxHealth << '\t' << "Mana: " << this->currMana << "/" << this->maxMana << '\t' << "XP: " << this->currXP << "/" << this->nextXP << '\t' << "Level: " << this->level << '\t' << "Gold Coins: " << this->gold << std::endl;

}

void Player::showStats()
{
	std::cout << std::endl << std::endl << "ATTRIBUTES:" << std::endl
		<< "Dexterity: " << this->aDexterity << std::endl
		<< "Strength: " << this->aStrength << std::endl;
	std::cout << std::endl << std::endl << "SKILLS:" << std::endl
		<< "Fighting: " << this->sFighting << std::endl
		<< "Shooting: " << this->sShooting << std::endl
		<< std::endl;
}

void Player::showInventory()
{
	if (!inventory.empty())
	{
		std::cout << this->name << "'s Items:" << std::endl;
		for (auto i : this->inventory)
		{
			std::cout << i->getName() << std::endl;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Your inventory is empty!" << std::endl << std::endl;
	}

	//show currently equipped items
	if (this->weapon != nullptr)
	{
		std::cout << "Current Weapon - " << this->weapon->getName() << '\t' << "Damage: " << this->weapon->getDamage() << '\t';
		if (this->weapon->getType() == 0)
		{
			std::cout << "(Melee)";
		}
		else
		{
			std::cout << "(Ranged)";
		}
		std::cout << std::endl;
	}
	
}

void Player::addXP(int xp)
{
	this->currXP += xp;
}

void Player::takeGold()
{
	int gp = this->getRoom()->getGold();
	if (gp > 0)
	{
		this->addGold(gp);
		this->getRoom()->setGold(0);
		std::cout << "You took the " << gp << " gold coins." << std::endl;
	}
}

void Player::takeItem(std::string item)
{
	//make a copy of the current room's item vector
	std::vector<Item*> copy = this->currentRoom->getItems();
	//int keeps track of index
	int y = 1;

	for (auto i : copy)
	{
		//check to make sure it's the right item
		if (item == i->getName())
		{
			//copy item to character's inventory
			this->addItem(i);
			//alert player of change
			std::cout << this->getName() << " took " << this->inventory.back()->getName() << std::endl;

			//remove the item from room
			copy.erase(copy.begin() + (y - 1), copy.begin()+y);

			std::cout << std::endl;
			//finally set the modified vector as the new room vector
			this->currentRoom->setItems(copy);

			//return since done
			return;
		}
		y++;
	}

}

void Player::takeAll()
{
	//make a copy of the current room's item vector
	std::vector<Item*> copy = this->currentRoom->getItems();
	while (!copy.empty())
	{
		//copy last item room has to character
		this->addItem(copy.back());
		//alert player of change
		std::cout << this->getName() << " took " << this->inventory.back()->getName() << std::endl;
		//remove the item from room
		copy.pop_back();
	}
	std::cout << std::endl;
	//finally set the modified vector as the new room vector
	this->currentRoom->setItems(copy);
}

void Player::look(std::string item)
{

	for (auto i : this->inventory)
	{
		//check to make sure it's the right item
		if (item == i->getName())
		{
			//display description
			std::cout << i->getDescription() << std::endl << std::endl;

			//return since done
			return;
		}
	}
	std::cout << "You don't have an item like that to look at." << std::endl;
}

std::string Player::equip(std::string item)
{
	int y = 0;
	for (auto i : this->inventory)
	{
		//check to make sure it's the right item
		if (item == i->getName())
		{
			//do this stuff ONLY IF item is equippable
			if (i->getEquipable())
			{
				//make copy of item
				Item* copy = i;

				//remove from inventory
				this->inventory.erase(this->inventory.begin() + y);

				//return copy's equipCat
				return copy->getEquipCat();
			}
			else
			{
				return "";
			}
		}
		y++;
	}
	return "x";
}

void Player::search()
{

	if (this->currentRoom->getStash() > 0)
	{
		std::cout << "You managed to scrounge up " << this->currentRoom->getStash() << " gold coins in your search, adding them to your purse." << std::endl;
		this->addGold(this->currentRoom->getStash());
		this->currentRoom->setStash(0);
	}
	std::vector<Item*> copy = this->currentRoom->getHidden();
	if (!copy.empty())
	{
		std::cout << "You've found a " <<currentRoom->getHiddenContainer() << std::endl;
	}
	else
	{
		std::cout << "There was no stash or secret containers" << std::endl;
	}
	std::cout << std::endl;
}

void Player::searchHidden()
{
	//make copy of hidden items vector
	std::vector<Item*> copy = this->currentRoom->getHidden();
	if (!copy.empty())
	{
		std::cout << "Your search revealed the following items: ";
		for (auto i : copy)
		{
			//show name of hidden item
			std::cout << copy.back()->getName() << ", ";
			//add hidden item to vector of visible items
			this->currentRoom->addItem(copy.back());
			//remove item from vector of hidden items
			copy.pop_back();
		}
		//set the modified vector as the new hidden items vector for the room
		this->currentRoom->setHidden(copy);
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Your search revealed no new items." << std::endl;
	}
	std::cout << std::endl;
}


void Player::open(std::string noun)
{
	if ((noun == "north") && (this->currentRoom->getNorthDoor() != nullptr))
	{
		if (this->currentRoom->getNorthDoor()->getUnlocked() == false)
		{
			std::cout << std::endl << "Door cannot be opened, it is locked." << std::endl;
		}
		else if ((this->currentRoom->getNorthDoor()->getUnlocked() == true) && (this->currentRoom->getNorthDoor()->getOpen() == false))
		{
			std::cout << std::endl << "Door opened." << std::endl;
			this->currentRoom->openNorthDoor(true);
		}
		else {}
	}
	else if ((noun == "east") && (this->currentRoom->getEastDoor() != nullptr))
	{
		if (this->currentRoom->getEastDoor()->getUnlocked() == false)
		{
			std::cout << std::endl << "Door cannot be opened, it is locked." << std::endl;
		}
		else if ((this->currentRoom->getEastDoor()->getUnlocked() == true) && (this->currentRoom->getEastDoor()->getOpen() == false))
		{
			std::cout << std::endl << "Door opened." << std::endl;
			this->currentRoom->openEastDoor(true);
		}
		else {}
	}
	else if ((noun == "south") && (this->currentRoom->getSouthDoor() != nullptr))
	{
		if (this->currentRoom->getSouthDoor()->getUnlocked() == false)
		{
			std::cout << std::endl << "Door cannot be opened, it is locked." << std::endl;
		}
		else if ((this->currentRoom->getSouthDoor()->getUnlocked() == true) && (this->currentRoom->getSouthDoor()->getOpen() == false))
		{
			std::cout << std::endl << "Door opened." << std::endl;
			this->currentRoom->openSouthDoor(true);
		}
		else {}
	}
	else if ((noun == "west") && (this->currentRoom->getWestDoor() != nullptr))
	{
		if (this->currentRoom->getWestDoor()->getUnlocked() == false)
		{
			std::cout << std::endl << "Door cannot be opened, it is locked." << std::endl;
		}
		else if ((this->currentRoom->getWestDoor()->getUnlocked() == true) && (this->currentRoom->getWestDoor()->getOpen() == false))
		{
			std::cout << std::endl << "Door opened." << std::endl;
			this->currentRoom->openWestDoor(true);
		}
		else {}
	}
	else if ((noun == "up") && (this->currentRoom->getUpDoor() != nullptr))
	{
		if (this->currentRoom->getUpDoor()->getUnlocked() == false)
		{
			std::cout << std::endl << "Door cannot be opened, it is locked." << std::endl;
		}
		else if ((this->currentRoom->getUpDoor()->getUnlocked() == true) && (this->currentRoom->getUpDoor()->getOpen() == false))
		{
			std::cout << std::endl << "Door opened." << std::endl;
			this->currentRoom->openUpDoor(true);
		}
		else{}
	}
	else if ((noun == "down") && (this->currentRoom->getDownDoor() != nullptr))
	{
		if (this->currentRoom->getDownDoor()->getUnlocked() == false)
		{
			std::cout << std::endl << "Door cannot be opened, it is locked." << std::endl;
		}
		else if ((this->currentRoom->getDownDoor()->getUnlocked() == true) && (this->currentRoom->getDownDoor()->getOpen() == false))
		{
			std::cout << std::endl << "Door opened." << std::endl;
			this->currentRoom->openDownDoor(true);
		}
		else{}
	}
	else {}
}

//go through player inventory. if item with same lockID as that of door is found, unlock the door
void Player::unlock(std::string noun)
{
	if ((noun == "north") && (this->currentRoom->getNorthDoor() != nullptr))
	{
		if (this->currentRoom->getNorthDoor()->getUnlocked() == false)
		{
			for (auto i : this->inventory)
			{
				if (i->getLockID() == this->currentRoom->getNorthDoor()->getLockID())
				{
					std::cout << "Door unlocked using " << i->getName() << "." << std::endl;
					this->currentRoom->getNorthDoor()->setUnlocked(true);
					return;
				}
			}
			std::cout << "You do not have a key that fits." << std::endl;
		}
		else
		{
			std::cout << std::endl << "That door is already unlocked." << std::endl;
		}
	}
	else if ((noun == "east") && (this->currentRoom->getEastDoor() != nullptr))
	{
		if (this->currentRoom->getEastDoor()->getUnlocked() == false)
		{
			for (auto i : this->inventory)
			{
				if (i->getLockID() == this->currentRoom->getEastDoor()->getLockID())
				{
					std::cout << "Door unlocked using " << i->getName() << "." << std::endl;
					this->currentRoom->getEastDoor()->setUnlocked(true);
					return;
				}
			}
			std::cout << "You do not have a key that fits." << std::endl;
		}
		else
		{
			std::cout << std::endl << "That door is already unlocked." << std::endl;
		}
	}
	else if ((noun == "south") && (this->currentRoom->getSouthDoor() != nullptr))
	{
		if (this->currentRoom->getSouthDoor()->getUnlocked() == false)
		{
			for (auto i : this->inventory)
			{
				if (i->getLockID() == this->currentRoom->getSouthDoor()->getLockID())
				{
					std::cout << "Door unlocked using " << i->getName() << "." << std::endl;
					this->currentRoom->getSouthDoor()->setUnlocked(true);
					return;
				}
			}
			std::cout << "You do not have a key that fits." << std::endl;
		}
		else
		{
			std::cout << std::endl << "That door is already unlocked." << std::endl;
		}
	}
	else if ((noun == "west") && (this->currentRoom->getWestDoor() != nullptr))
	{
		if (this->currentRoom->getWestDoor()->getUnlocked() == false)
		{
			for (auto i : this->inventory)
			{
				if (i->getLockID() == this->currentRoom->getWestDoor()->getLockID())
				{
					std::cout << "Door unlocked using" << i->getName() << "." << std::endl;
					this->currentRoom->getWestDoor()->setUnlocked(true);
					return;
				}
			}
			std::cout << "You do not have a key that fits." << std::endl;
		}
		else
		{
			std::cout << std::endl << "That door is already unlocked." << std::endl;
		}
	}
	else if ((noun == "up") && (this->currentRoom->getUpDoor() != nullptr))
	{
		if (this->currentRoom->getUpDoor()->getUnlocked() == false)
		{
			for (auto i : this->inventory)
			{
				if (i->getLockID() == this->currentRoom->getUpDoor()->getLockID())
				{
					std::cout << "Door unlocked using " << i->getName() << "." << std::endl;
					this->currentRoom->getUpDoor()->setUnlocked(true);
					return;
				}
			}
			std::cout << "You do not have a key that fits." << std::endl;
		}
		else
		{
			std::cout << std::endl << "That door is already unlocked." << std::endl;
		}
	}
	else if ((noun == "down") && (this->currentRoom->getDownDoor() != nullptr))
	{
		if (this->currentRoom->getDownDoor()->getUnlocked() == false)
		{
			for (auto i : this->inventory)
			{
				if (i->getLockID() == this->currentRoom->getDownDoor()->getLockID())
				{
					std::cout << "Door unlocked using " << i->getName() << "." << std::endl;
					this->currentRoom->getDownDoor()->setUnlocked(true);
					return;
				}
			}
			std::cout << "You do not have a key that fits." << std::endl;
		}
		else
		{
			std::cout << std::endl << "That door is already unlocked." << std::endl;
		}
	}
	else {}
}

void Player::showDoors()
{
	if (this->currentRoom->getNorthDoor() == nullptr) {}
	else if (this->currentRoom->getNorthDoor()->getOpen() == false)
	{
		std::cout << "There is a closed door to the north." << std::endl;
	}
	else { std::cout << "There is an open door to the north." << std::endl; }
	
	if (this->currentRoom->getSouthDoor() == nullptr) {}
	else if (this->currentRoom->getSouthDoor()->getOpen() == false)
	{
		std::cout << "There is a closed door to the south." << std::endl;
	}
	else { std::cout << "There is an open door to the south." << std::endl; }

	if (this->currentRoom->getEastDoor() == nullptr) {}
	else if (this->currentRoom->getEastDoor()->getOpen() == false)
	{
		std::cout << "There is a closed door to the east." << std::endl;
	}
	else { std::cout << "There is an open door to the east." << std::endl; }

	if (this->currentRoom->getWestDoor() == nullptr) {}
	else if (this->currentRoom->getWestDoor()->getOpen() == false)
	{
		std::cout << "There is a closed door to the west." << std::endl;
	}
	else { std::cout << "There is an open door to the west." << std::endl; }

	if (this->currentRoom->getUpDoor() == nullptr) {}
	else if (this->currentRoom->getUpDoor()->getOpen() == false)
	{
		std::cout << "There is a closed trap door above." << std::endl;
	}
	else { std::cout << "There is an open trap door above." << std::endl; }

	if (this->currentRoom->getDownDoor() == nullptr) {}
	else if (this->currentRoom->getDownDoor()->getOpen() == false)
	{
		std::cout << "There is a closed trap door below." << std::endl;
	}
	else { std::cout << "There is an open trap door below." << std::endl; }
}

void Player::showSpells()
{
	if (this->spells.empty())
	{
		std::cout << "You have not yet learned any spells." << std::endl << std::endl;
	}
	else
	{
		std::cout << this->getName() << "'s spells." << std::endl;
		for (auto i : this->spells)
		{
			std::cout << i->getName() << '\t' << "Cost: " << i->getManaCost() << " mana" << std::endl;
		}
	}
	std::cout << std::endl;

}