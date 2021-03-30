#include "Character.h"

Character::Character()
{
	bool stunned = false;
}

Character::~Character()
{
}

bool Character::getStunned()
{
	return this->stunned;
}

void Character::setStunned(bool stun)
{
	this->stunned = stun;
}

std::string Character::getName()
{
	return this->name;
}

Room* Character::getRoom()
{
	return this->currentRoom;
}

void Character::setRoom(Room* room)
{
	this->currentRoom = room;
}

void Character::addItem(Item* newItem)
{
	this->inventory.push_back(newItem);
}

void Character::setInventory(std::vector<Item*> newItems)
{
	this->inventory = newItems;
}

void Character::dropInventory()
{
	while (! this->inventory.empty())
	{
		//copy last item character has to room
		this->currentRoom->addItem(this->inventory.back());
		//alert player of change
		std::cout << this->getName() << " dropped " << this->inventory.back()->getName() << std::endl;
		//remove the item from character inventory
		this->inventory.pop_back();
	}
	std::cout << std::endl;
}

void Character::dropItem(std::string item)
{
	//make a copy of the character's inventory
	std::vector<Item*> copy = this->inventory;
	//int keeps track of index
	int y = 1;

	for (auto i : copy)
	{
		//check to make sure it's the right item
		if (item == i->getName())
		{
			//copy item to room
			this->currentRoom->addItem(i);
			//alert player of change
			std::cout << this->getName() << " dropped " << i->getName() << std::endl;
			//remove the item from inventory
			copy.erase(copy.begin() + (y - 1), copy.begin() + y);

			std::cout << std::endl;
			//finally set the modified vector as the new inventory
			this->inventory = copy;

			//return since done
			return;
		}
		y++;
	}
}

void Character::useItem(std::string item, std::vector<Consumable*> consumables)
{
	//make a copy of the character's inventory
	std::vector<Item*> copy = this->inventory;
	//int keeps track of index
	int y = 1;

	for (auto i : copy)
	{
		//check to make sure it's the right item
		if (item == i->getName())
		{
			
			//remove the item from inventory ONLY IF consumable
			if (i->getEdibility() == true)
			{
				copy.erase(copy.begin() + (y - 1), copy.begin() + y);
				//alert player of change
				std::cout << this->getName() << " used " << i->getName() << ", consuming it in the process." << std::endl;

				//apply the item's effect
				for (auto a : consumables)
				{
					if (item == a->getName())
					{
						//see what kind of effect it is
						if (a->getEffect() == "heal")
						{
							this->healDamage(a->getPotency());
						}
						else if (a->getEffect() == "mana")
						{
							this->healMana(a->getPotency());
						}
						else if (a->getEffect() == "strength")
						{
							this->addStrength(a->getPotency());
						}
						else if (a->getEffect() == "dexterity")
						{
							this->addDexterity(a->getPotency());
						}
					}
					
				}

			}
			else
			{
				//if not consumable, do not erase
				std::cout << this->getName() << " gripped the " << i->getName() << " firmly." << std::endl;
			}


			std::cout << std::endl;
			//finally set the modified vector as the new inventory
			this->inventory = copy;

			//return since done
			return;
		}
		y++;
	}
}

int Character::getGold()
{
	return this->gold;
}

void Character::addGold(int gold)
{
	this->gold += gold;
}

void Character::dropGold()
{
	std::cout << this->getName() << " dropped " << this->gold << " gold coins." << std::endl;
	this->currentRoom->addGold(this->gold);
	this->addGold(-1 * (this->gold));
}

void Character::takeDamage(int dmg)
{
	//subtract damage from current health
	this->currHealth -= dmg;

	//print alert
	std::cout << this->getName() << " took " << dmg << " damage." << std::endl;

	//if current health is 0 or lower, the character dies
	if (this->currHealth <= 0)
	{
		this->dies();
	}
}

void Character::dies()
{
	//alert player that a character died
	std::cout << std::endl << this->name << " has been slain!" << std::endl;

	//make sure equipped items are copied to inventory before dropping entire inventory
	if (this->weapon != nullptr) { this->addItem(this->weapon); }

	//that character drops his entire inventory
	this->dropInventory();
	//that character drops all his gold
	this->dropGold();

}

int Character::getHealth()
{
	return this->currHealth;
}

void Character::healDamage(int heal)
{
	//add to current health
	this->currHealth += heal;

	//print alert
	std::cout << this->getName() << " regained " << heal << " health." << std::endl;

	//don't let current health exceed max health
	if (this->currHealth > this->maxHealth)
	{
		this->currHealth = this->maxHealth;
	}
}

void Character::attack(Character* target, int attack)
{
	//bool determines whether the attack was a success
	bool hit = false;
	//int determines how much damage the character takes
	int dmg = 0;
	//get random seed
	srand(time(NULL));
	//int keeps track of roll made with d20
	int roll = (rand() % 20) + 1;
	//int keeps track of damage roll made with d6
	int droll = (rand() % 6) + 1;

	//int toHit modified based on type of attack
	int toHit = 0;

	//find out whether the attack was a hit, based on attacker's weapon skill + related attribute

	//if no weapon is equipped, use fists
	if (this->weapon == nullptr)
	{
		toHit = this->sFighting + this->aStrength;
		//calculate damage as d6+ATTRIBUTE
		dmg = (droll + this->aStrength);
	}
	//if using melee weapon, base it off of strength
	else if (this->weapon->getType() == 0)
	{
		toHit = this->sFighting + this->aStrength;
		//calculate damage as d6+ATTRIBUTE+WEAPON
		dmg = (droll + this->aStrength + this->weapon->getDamage());		
	}
	//if using ranged weapon, base it off of dexterity
	else
	{
		toHit = this->sShooting + this->aDexterity;
		//calculate damage as d6+ATTRIBUTE+WEAPON
		dmg = (droll + this->aDexterity + this->weapon->getDamage());
	}


	//modify toHit and dmg based on type of attack selected
	if (attack == 0)
	{
		//standard attack, no change
	}
	else if (attack == 1)
	{
		//less likely to hit but does more damage
		toHit = toHit * (.75);
		dmg = dmg * (1.25);
	}
	else if (attack == 2)
	{
		//no damage but can prevent enemy from acting
		dmg = 0;
	}
	else if (attack == 3)
	{
		//more likely to hit but does less damage
		toHit = toHit * (1.25);
		dmg = dmg * (.75);
	}
	else
	{
		//do nothing
	}


	//if roll is under SKILL+ATTRIBUTE, it's a hit
	if (roll <= (toHit))
	{
		//mark as hit
		hit = true;
	}
	//if hit, apply damage (or stun) and alert player
	if (hit)
	{
		std::cout << this->name << " hit " << target->getName() << std::endl;

		//if stun attack, set target to stunned and alert player
		if (attack == 2) {
			target->setStunned(true);
			std::cout << target->getName() << " was stunned, losing their next turn." << std::endl;
		}
		//otherwise target takes damage
		else { target->takeDamage(dmg); }
	}
	//if miss, alert player
	else
	{
		std::cout << this->name << " failed to hit " << target->getName() << std::endl;
	}
}


void Character::loseMana(int dmg)
{
	this->currMana -= dmg;
	if (currMana < 0)
	{
		currMana = 0;
	}
	std::cout << this->getName() << " used " << dmg << " mana." << std::endl;
}
void Character::healMana(int heal)
{
	this->currMana += heal;
	if (currMana > maxMana)
	{
		currMana = maxMana;
	}
	std::cout << this->getName() << " regained " << heal << " mana." << std::endl;
}
void Character::addStrength(int strength) 
{
	this->aStrength += strength;
	std::cout << this->getName() << " added " << strength << " strength." << std::endl;
}
void Character::addDexterity(int dex)
{
	this->aDexterity += dex;
	std::cout << this->getName() << " added " << dex << " dexterity." << std::endl;
}


//GETTERS FOR EQUIPPED ITEMS
//------------------------//

//hand (primary)
Weapon* Character::getWeapon()
{
	return this->weapon;
}
//hand (secondary)
//Shield* getShield();
//head
//Helmet* getHelm();
//torso
//Cuirass* getCuirass();
//legs
//Greaves* getGreaves();



//SETTERS FOR EQUIPPED ITEMS
//------------------------//

//hand (primary)
void Character::equipWeapon(Weapon* weapon)
{
	this->weapon = weapon;
}
//hand (secondary)
//
//head
//
//torso
//
//legs
//



//SPELL STUFF
//adds spell to character's vector of spells (does so without checking vector or alerting player)
void Character::addSpell(Spell* spell)
{
	this->spells.push_back(spell);
}
//triggers addSpell only if character does not already have that spell (i.e. no duplicates allowed)
void Character::learnSpell(Spell* spell)
{
	bool doesNotHaveSpell = true;
	for (auto i : this->spells)
	{
		//if name matches, break
		if (i->getName() == spell->getName())
		{
			doesNotHaveSpell = false;
			break;
		}
	}
	//add spell only if don't have it already
	if (doesNotHaveSpell)
	{
		this->addSpell(spell);
		std::cout << "You have learned how to cast " << spell->getName() << "." << std::endl;
	}
	else
	{
		std::cout << "You already know that spell." << std::endl;
	}
}
//tries to match string to name of spell in character's vector of spells ...
//if there is a match, trigger the spell's effect
void Character::castSpell(Spell* temp, Character* target)
{
	bool knowSpell = false;
	
	for (auto i : this->spells)
	{
		//if name matches, break
		if (i->getName() == temp->getName())
		{
			knowSpell = true;
			temp = i;
			break;
		}
	}
	//check character's mana then do the effect
	if (knowSpell)
	{
		//if character has enough mana
		if ( (this->currMana - temp->getManaCost()) >= 0 )
		{
			//subtract mana then apply effect
			this->loseMana(temp->getManaCost());

			if (temp->getEffect() == "heal")
			{
				target->healDamage(temp->getPotency());
			}
			else if (temp->getEffect() == "damage")
			{
				target->takeDamage(temp->getPotency());
			}
			else {}
		}
		else
		{
			std::cout << "You do not have enough mana to cast that spell!" << std::endl;
		}
		
	}
	//character does not know spell, so no effect
	else
	{
		std::cout << "You do not know a spell by that name." << std::endl;
	}
}