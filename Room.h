#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

//random functionality
#include <ctime>

#include "Item.h"
#include "Door.h"

class Room
{
public:
	Room(std::string description);
	~Room();

	std::string getDescription();
	std::string getText();
	void setText(std::string text);

	void setRooms(Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom, Room* upRoom, Room* downRoom);
	Room* getRoom(std::string direction);

	void setDoors(Door* northDoor, Door* eastDoor, Door* southDoor, Door* westDoor, Door* upDoor, Door* downDoor);

	void showItems();
	void addItem(Item* newItem);
	std::vector<Item*> getItems();
	void setItems(std::vector<Item*> newItems);

	int getGold();
	void setGold(int gold);
	void addGold(int gold);

	std::vector<Item*> getHidden();
	void setHidden(std::vector<Item*> newHidden);
	void setHiddenContainer(std::string container);
	int getStash();
	void setStash(int gp);
	void addHidden(Item* secretItem);
	std::string getHiddenContainer();

	Door* getNorthDoor();
	Door* getEastDoor();
	Door* getSouthDoor();
	Door* getWestDoor();
	Door* getUpDoor();
	Door* getDownDoor();

	void openNorthDoor(bool status);
	void openEastDoor(bool status);
	void openSouthDoor(bool status);
	void openWestDoor(bool status);
	void openUpDoor(bool status);
	void openDownDoor(bool status);

	// returns true if player has not visited room already, false if player has already visited room
	bool getVisitedStatus();
	// sets hasNotVisited bool to false
	void changeVisitedStatus();



private:
	//vector of visible items
	std::vector<Item*> items;
	//vector of hidden items, revealed through search
	std::vector<Item*> hidden;

	//int of visible gold coins lying around
	int gold;
	//int of hidden gold in room
	int stash;

	//vector of containers (each containing a vector of items)

	//vector of doors

	//what the player sees upon entering a room
	std::string description;
	std::string text;

	//special container string for hidden
	std::string hiddenItemContainer;

	//pointers to adjacent rooms
	Room* northRoom;
	Room* eastRoom;
	Room* southRoom;
	Room* westRoom;
	Room* upRoom;
	Room* downRoom;

	//pointers to doors
	Door* northDoor;
	Door* eastDoor;
	Door* southDoor;
	Door* westDoor;
	Door* upDoor;
	Door* downDoor;

	// true if player has not been in a room yet, false if already has been in this room
	bool hasNotVisited;
};


