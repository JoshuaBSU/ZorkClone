#pragma once
#include "Character.h"
#include "Door.h"

class Player :
	public Character
{
public:
	Player(std::string name, Room* currentRoom);
	~Player();
	void checkLevel();
	void displayPlayer();
	void showInventory();
	void showStats();

	void addXP(int xp);
	void gainLevel();

	void takeItem(std::string item);
	std::string equip(std::string item);
	void takeAll();
	void takeGold();

	void look(std::string item);
	void search();

	void searchHidden();

	void open(std::string noun);
	//go through player inventory. if item with same lockID as that of door is found, unlock the door
	void unlock(std::string noun);
	void showDoors();

	void showSpells();

private:
	int currXP;
	int nextXP;
	int level;
};

