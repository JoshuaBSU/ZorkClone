#pragma once
#include <string>
#include <iostream>

#include "Room.h"

#include "Consumable.h"
#include "Spell.h"

//include the various types of equipment that a character can have equipped
#include "Weapon.h"

class Character
{
public:
	Character();
	~Character();
	std::string getName();

	Room* getRoom();
	void setRoom(Room* room);

	void dropInventory();
	void dropItem(std::string item);
	void addItem(Item* newItem);
	void setInventory(std::vector<Item*> newItems);
	
	void useItem(std::string item, std::vector<Consumable*> consumables);

	int getGold();
	void addGold(int gold);
	void dropGold();

	int getHealth();
	void attack(Character* target, int attack);
	void takeDamage(int dmg);
	void healDamage(int heal);
	void dies();

	void loseMana(int dmg);
	void healMana(int heal);

	void addStrength(int strength);
	void addDexterity(int dex);

	bool getStunned();
	void setStunned(bool stun);

//METHODS FOR EQUIPPING ITEMS
	//hand (primary)
	void equipWeapon(Weapon* weapon);
	//hand (secondary)
	//
	//head
	//
	//torso
	//
	//legs
	//

//GETTERS FOR EQUIPPED ITEMS
	//hand (primary)
	Weapon* getWeapon();
	//hand (secondary)
	//Shield* getShield();
	//head
	//Helmet* getHelm();
	//torso
	//Cuirass* getCuirass();
	//legs
	//Greaves* getGreaves();

//spell-related methods
	//adds spell to character's vector of spells
	void addSpell(Spell* spell);
	//triggers addSpell only if character does not already have that spell (i.e. no duplicates allowed)
	void learnSpell(Spell* spell);
	//tries to match string to name of spell in character's vector of spells ...
	//if there is a match, trigger the spell's effect
	void castSpell(Spell* temp, Character* target);

protected:
	std::string name;
	int maxHealth;
	int currHealth;

	int maxMana;
	int currMana;

	Room* currentRoom;

	std::vector<Item*> inventory;
	std::vector<Spell*> spells;

	int gold;
	bool stunned;

	//ATTRIBUTES
	int aStrength;
	int aDexterity;

	//SKILLS
	int sFighting;
	int sShooting;

//EQUIPPED ITEMS
	//hand (primary)
	Weapon* weapon;
	//hand (secondary)
	//Shield* shield;
	//head
	//Helmet* helm;
	//torso
	//Cuirass* cuirass;
	//legs
	//Greaves* greaves;
};

