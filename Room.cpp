#include "Room.h"

Room::Room(std::string description)
{
	this->description = description;
	this->hasNotVisited = true;
}


Room::~Room()
{
}

std::string Room::getDescription() {
	return this->description;
}

int Room::getGold()
{
	return this->gold;
}

void Room::setGold(int gold)
{
	this->gold = gold;
}

void Room::addGold(int gold)
{
	this->gold += gold;
}

void Room::setRooms(Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom, Room* upRoom, Room* downRoom) {
	this->northRoom = northRoom;
	this->southRoom = southRoom;
	this->eastRoom = eastRoom;
	this->westRoom = westRoom;
	this->upRoom = upRoom;
	this->downRoom = downRoom;
}

void Room::setDoors(Door* northDoor, Door* eastDoor, Door* southDoor, Door* westDoor, Door* upDoor, Door* downDoor)
{
	this->northDoor = northDoor;
	this->southDoor = southDoor;
	this->eastDoor = eastDoor;
	this->westDoor = westDoor;
	this->upDoor = upDoor;
	this->downDoor = downDoor;
}

void Room::showItems()
{
	if (!items.empty())
	{
		std::cout << "You see the following items in the room: ";
		for (auto i : this->items)
		{
			std::cout << i->getName() << ", ";
		}
		std::cout << std::endl;
	}

}

void Room::addItem(Item* newItem)
{
	this->items.push_back(newItem);
}

std::vector<Item*> Room::getItems()
{
	return this->items;
}

void Room::setItems(std::vector<Item*> newItems)
{
	this->items = newItems;
}

Room* Room::getRoom(std::string direction) {
	if (direction == "north" && this->northRoom != nullptr)
	{
		if (this->northDoor != nullptr)
		{
			if (this->northDoor->getOpen() == false)
			{
				std::cout << std::endl << "There is a closed door in your path." << std::endl << std::endl;
				return this;
			}
		}
		return this->northRoom;
	}
	else if (direction == "east" && this->eastRoom != nullptr)
	{
		if (this->eastDoor != nullptr)
		{
			if (this->eastDoor->getOpen() == false)
			{
				std::cout << std::endl << "There is a closed door in your path." << std::endl << std::endl;
				return this;
			}
		}
		return this->eastRoom;
	}
	else if (direction == "south" && this->southRoom != nullptr)
	{
		if (this->southDoor != nullptr)
		{
			if (this->southDoor->getOpen() == false)
			{
				std::cout << std::endl << "There is a closed door in your path." << std::endl << std::endl;
				return this;
			}
		}
		return this->southRoom;
	}
	else if (direction == "west" && this->westRoom != nullptr)
	{
		if (this->westDoor != nullptr)
		{
			if (this->westDoor->getOpen() == false)
			{
				std::cout << std::endl << "There is a closed door in your path." << std::endl << std::endl;
				return this;
			}
		}
		return this->westRoom;
	}
	else if (direction == "up" && this->upRoom != nullptr)
	{
		if (this->upDoor != nullptr)
		{
			if (this->upDoor->getOpen() == false)
			{
				std::cout << std::endl << "There is a closed door in your path." << std::endl << std::endl;
				return this;
			}
		}
		return this->upRoom;
	}
	else if (direction == "down" && this->downRoom != nullptr)
	{
		if (this->downDoor != nullptr)
		{
			if (this->downDoor->getOpen() == false)
			{
				std::cout << std::endl << "There is a closed door in your path." << std::endl << std::endl;
				return this;
			}
		}
		return this->downRoom;
	}
	else {
		std::cout << std::endl << "Cannot go that way." << std::endl << std::endl;
		return this;
	}
}

std::string Room::getText()
{
	return this->text;
}
void Room::setText(std::string text)
{
	this->text = text;
}

std::vector<Item*> Room::getHidden()
{
	return this->hidden;
}
void Room::setHidden(std::vector<Item*> newHidden)
{
	this->hidden = newHidden;
}

void Room::setHiddenContainer(std::string container)
{
	this->hiddenItemContainer = container;
}

std::string Room::getHiddenContainer()
{
	return hiddenItemContainer;
}

int Room::getStash()
{
	return this->stash;
}
void Room::setStash(int gp)
{
	this->stash = gp;
}

void Room::addHidden(Item* secretItem)
{
	this->hidden.push_back(secretItem);
}



Door* Room::getNorthDoor()
{
	return this->northDoor;
}
Door* Room::getEastDoor()
{
	return this->eastDoor;
}
Door* Room::getSouthDoor()
{
	return this->southDoor;
}
Door* Room::getWestDoor()
{
	return this->westDoor;
}
Door* Room::getUpDoor()
{
	return this->upDoor;
}
Door* Room::getDownDoor()
{
	return this->downDoor;
}

void Room::openNorthDoor(bool status)
{
	this->northDoor->setOpen(status);
}
void Room::openEastDoor(bool status)
{
	this->eastDoor->setOpen(status);
}
void Room::openSouthDoor(bool status)
{
	this->southDoor->setOpen(status);
}
void Room::openWestDoor(bool status)
{
	this->westDoor->setOpen(status);
}
void Room::openUpDoor(bool status)
{
	this->upDoor->setOpen(status);
}
void Room::openDownDoor(bool status)
{
	this->downDoor->setOpen(status);
}

// returns true if player has not visited room already, false if player has already visited room
bool Room::getVisitedStatus()
{
	return this->hasNotVisited;
}

// sets hasNotVisited bool to false
void Room::changeVisitedStatus()
{
	this->hasNotVisited = false;
}