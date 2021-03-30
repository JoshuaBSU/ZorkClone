//need to include subclasses of the Character class that can be initialized from Main
#include "Door.h"
#include "Spell.h"
#include <random>

//ITEMS
#include "Consumable.h"
#include "Artifact.h"
	//EQUIPMENT TYPES
	#include "Weapon.h"

//CHARACTERS
	//PLAYER
	#include "Player.h"

	//ENEMIES
	#include "HumanCaptain.h"
	#include "HumanCrossbow.h"
	#include "HumanGuard.h"
	#include "SkeletonArcher.h"
	#include "SkeletonChampion.h"
	#include "SkeletonWarrior.h"
	#include "VampireLord.h"
	#include "OrcWarrior.h"
	#include "OrcBerserker.h"
	#include "OrcBrawler.h"
	#include "KoboldHunter.h"
	#include "KoboldStabber.h"
	#include "KoboldStealer.h"

//Some methods to make main() easier to read
std::vector<Room*> initRooms(std::vector<Room*> rooms);

int main()
{
	//True Random
	std::random_device rd;
	std::mt19937 mt(rd());
	//Base is set to 3.5 increase second number to decrease chance of item spawn
	std::uniform_real_distribution<double> randChance(0, 8);
	//floor results when convertint to int
	std::uniform_real_distribution<double> randItem(0, 3.9);

	/* Used for testing random
	for (int i = 0; i < 16; ++i)
	{
		std::cout << randChance(mt) << "\n";
		std::cout << randItem(mt) << "\n";
	}
	*/

	//CREATE ROOMS
	std::vector<Room*> rooms;
	//INITIALIZE ROOMS (incl. descriptions, doors, items)
	rooms = initRooms(rooms);

	//CREATE THE DOORS
	//open(bool), unlocked(bool), lockID(int)
	Door* door00000 = new Door(true, true, 0);
	Door* door00001 = new Door(false, true, 0);
	Door* door00002 = new Door(false, true, 0);
	Door* doorChapel = new Door(false, true, 0);
	Door* doorArmory = new Door(false, true, 0);
	Door* doorCapn = new Door(false, false, 1);		// captain's key
	Door* doorKeep = new Door(false, true, 0);
	Door* doorCloset = new Door(false, true, 0);
	Door* doorServ = new Door(false, false, 3);		// servant's key
	Door* doorPantry = new Door(false, false, 3);		// servant's key
	Door* doorKitchen = new Door(false, true, 0);
	Door* doorWar = new Door(false, true, 0);
	Door* doorWine = new Door(false, true, 0);
	Door* doorTower = new Door(false, false, 2);		// tower key

	//CONNECT DOORS TO ROOMS
	//NESWUD
	rooms[0]->setDoors(door00000, nullptr, nullptr, nullptr, door00001, door00002);
	rooms[1]->setDoors(nullptr, nullptr, nullptr, nullptr, door00002, nullptr);
	rooms[2]->setDoors(nullptr, nullptr, nullptr, nullptr, nullptr, door00001);
	rooms[3]->setDoors(nullptr, nullptr, door00000, nullptr, nullptr, nullptr);
	rooms[4]->setDoors(nullptr, nullptr, nullptr, doorChapel, nullptr, nullptr);
	rooms[5]->setDoors(nullptr, doorArmory, nullptr, nullptr, nullptr, nullptr);
	//rooms[6]->setDoors(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
	rooms[7]->setDoors(nullptr, doorChapel, nullptr, nullptr, nullptr, nullptr);
	rooms[8]->setDoors(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
	rooms[9]->setDoors(nullptr, nullptr, nullptr, doorArmory, doorCapn, nullptr);
	rooms[10]->setDoors(nullptr, nullptr, nullptr, nullptr, nullptr, doorCapn);
	//rooms[11]->setDoors(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
	rooms[12]->setDoors(doorKeep, nullptr, nullptr, nullptr, nullptr, nullptr);
	rooms[13]->setDoors(nullptr, doorServ, doorKeep, doorCloset, nullptr, nullptr);
	rooms[14]->setDoors(nullptr, doorCloset, nullptr, nullptr, nullptr, nullptr);
	rooms[15]->setDoors(nullptr, doorPantry, nullptr, nullptr, nullptr, nullptr);
	rooms[16]->setDoors(nullptr, doorKitchen, nullptr, doorWar, nullptr, nullptr);
	rooms[17]->setDoors(nullptr, doorWar, nullptr, nullptr, nullptr, nullptr);
	rooms[18]->setDoors(nullptr, nullptr, nullptr, doorServ, nullptr, nullptr);
	rooms[19]->setDoors(nullptr, nullptr, nullptr, doorPantry, nullptr, nullptr);
	rooms[20]->setDoors(nullptr, nullptr, nullptr, doorKitchen, nullptr, doorWine);
	rooms[21]->setDoors(nullptr, nullptr, nullptr, nullptr, doorWine, nullptr);
	//rooms[22]->setDoors(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
	//rooms[23]->setDoors(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
	//rooms[24]->setDoors(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
	rooms[25]->setDoors(nullptr, nullptr, nullptr, doorTower, nullptr, nullptr);
	rooms[26]->setDoors(nullptr, doorTower, nullptr, nullptr, nullptr, nullptr);
	rooms[27]->setDoors(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
	rooms[28]->setDoors(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);

	//CREATE FIELD FOR USER INPUT
	std::string userInput = "";

	//CREATE PLAYER
	//ask player for name
	std::cout << "What is your name? ";
	std::getline(std::cin, userInput);
	//create new player with user-given name, starting at room 0
	Player* player = new Player(userInput, rooms[0]);
	userInput = "";

	//CREATE ITEMS
	//Consumables (one-time use, usually gives positive effect to character who used it)
    std::vector<Consumable*> consumables;
    consumables.push_back(new Consumable("healing potion", 15, "heal", 25));
    consumables[0]->setDescription("A foggy red liquid in a very thick glass bottle. Registered trademark of 'Wyrd & Sons, Inc.' All rights reserved.");
    consumables.push_back(new Consumable("mana potion", 15, "mana", 25));
    consumables[1]->setDescription("A misty blue liquid in a corked test tube. 'For medicinal purposes only: keep refrigerated for that cool minty taste!'Weird flex but okay");
    //Consumable Stat modifiers, Chug before moving to enhance your character permenantly
    consumables.push_back(new Consumable("strength potion", 15, "strength", 2));
    consumables[2]->setDescription("A crusty magenta colored ''liquid'' in a victorian era vial. Only Label is ''Stronk'', Looks Disgusting.");
    consumables.push_back(new Consumable("dexterity potion", 15, "dexterity", 2));
    consumables[3]->setDescription("A semi transparent green liquid diamond shaped glassware. Smells like a forest, you can also feel your wits quickening. Zooom!");
    
    
    //Artifacts (can't be used but usually have a high value, or key story text --> also includes keys)
    Artifact* gemstone = new Artifact("gemstone", 50);
    gemstone->setDescription("You seem to have found a gemstone-thing. it has Esteves's face etched into it, with the number: 340 under it. Huh, strange. ");
    Artifact* wantedPoster = new Artifact("wanted poster", 0);
    wantedPoster->setDescription("The scroll reads:\n'WANTED:\n"+player->getName()+"\nREWARD OF an A+\nto he that bringeth the head of the accused to Grandmaster Esteves'\nThere is also a holographic picture of your face. Kinda unsettling at the detail of your face.");
    Artifact* victoryNote = new Artifact("important note", 0);
    victoryNote->setDescription("CONGRATULATIONS!\nYou have defeated Grandmaster Esteves! and beaten the game.\nWhile there are no further objectives, you are free to explore the castle. Enter the 'quit' command when you are finished. Don't stay too long, for your Girlfriend awaits you in the real World. Go tell her how much you love her after this.");
    Artifact* MorbisRing = new Artifact("ring of Esteves.", 100);
    MorbisRing->setDescription("This ring signifies lordship over Castle 340 and its fiefs. Unfortunately it has been cursed by the dark magic of Grandmaster Esteves, and cannot be worn.");
    
    //Keys (special type of artifact)
	Artifact* cpnKey = new Artifact("captain's key", 0);
	cpnKey->setLockID(1);
	Artifact* towerKey = new Artifact("tower key", 0);
	towerKey->setLockID(2);
	Artifact* servKey = new Artifact("servant's key", 0);
	servKey->setLockID(3);
	
	//Weapons (they help in combat)
	std::vector<Weapon*> weapons;
	//name, value, damage, type (0=melee, 1=ranged)
	weapons.push_back(new Weapon("steel longsword", 20, 5, 0));
	weapons[0]->setDescription("A long double-edged blade, forged from imported metals. Not to be used for shaving.");
	weapons.push_back(new Weapon("spear", 8, 2, 0));
	weapons[1]->setDescription("A narrow wooden rod with a sharp point at one end. What did you expect?");
	weapons.push_back(new Weapon("light crossbow", 12, 3, 1));
	weapons[2]->setDescription("A light-weight crossbow, about as long as the distance from your elbow to your wrist.");
	weapons.push_back(new Weapon("iron broadsword", 12, 3, 0));
	weapons[3]->setDescription("A wide iron blade meant for ye olde hack'n'slash.");
	weapons.push_back(new Weapon("iron dagger", 12, 2, 0));
	weapons[4]->setDescription("A short piece of cheap metal with a grip.");
	weapons.push_back(new Weapon("sling", 12, 2, 1));
	weapons[5]->setDescription("A piece of cloth you can use to launch rocks at bad guys.");

	//CREATE SPELLS
	std::vector<Spell*> spells;
	//name(string), effect(string), potency(int), manaCost(int)
    spells.push_back(new Spell("Persona: Arsene", "damage", 10, 15));
    spells.push_back(new Spell("Persona: Ishtar", "heal", 10, 10));

	//CREATE VECTOR OF ENEMIES
	std::vector<Enemy*> enemies;

	//CREATE ENEMIES AND ADD THEM TO VECTOR
	//NOTE - putting enemies in same room next to each other in vector won't work
	enemies.push_back(new HumanGuard("Generic Mid Level Normie", rooms[13]));
	enemies.push_back(new KoboldStealer("Steal-Steal", rooms[17]));
	enemies.push_back(new KoboldHunter("Shoot-Shoot", rooms[11]));
	enemies.push_back(new KoboldStabber("Stab-Stab", rooms[9]));
	enemies.push_back(new HumanGuard("Generic DnD Character", rooms[13]));
	enemies.push_back(new HumanCaptain("Cpt. Obvious", rooms[10]));
	enemies.push_back(new HumanCrossbow("Sgt. Jose", rooms[2]));
    enemies.push_back(new OrcBerserker("Tommy Wiseau", rooms[14]));
	enemies.push_back(new SkeletonChampion("Undead Hero", rooms[8]));
	enemies.push_back(new SkeletonArcher("Undead Stoner", rooms[25]));
	enemies.push_back(new OrcBrawler("Josh the lunatic", rooms[26]));
	enemies.push_back(new OrcWarrior("Nick the Absolute Unit.", rooms[27]));
	enemies.push_back(new VampireLord("Grandmaster Esteves", rooms[28]));

	//make sure every enemy of same type has the same inventory
	for (auto z : enemies)
	{
		if (z->getEnemyType() == "human captain")
		{
			z->equipWeapon(weapons[0]);
			z->addItem(towerKey);
			if (randChance(mt) < 3.5)
			{
				z->addItem(consumables[int(randItem(mt))]);
			}
		}
		else if (z->getEnemyType() == "human guard")
		{
			z->equipWeapon(weapons[1]);
			if (randChance(mt) < 3.5)
			{
				z->addItem(consumables[int(randItem(mt))]);
			}
		}
		else if (z->getEnemyType() == "human crossbowman")
		{
			z->equipWeapon(weapons[2]);
			if (randChance(mt) < 3.5)
			{
				z->addItem(consumables[int(randItem(mt))]);
			}
		}
		else if (z->getEnemyType() == "skeleton champion")
		{
			z->equipWeapon(weapons[3]);
			if (randChance(mt) < 3.5)
			{
				z->addItem(consumables[int(randItem(mt))]);
			}
		}
		else if (z->getEnemyType() == "skeleton warrior")
		{
			z->equipWeapon(weapons[3]);
			if (randChance(mt) < 3.5)
			{
				z->addItem(consumables[int(randItem(mt))]);
			}
		}
		else if (z->getEnemyType() == "skeleton archer")
		{
			z->equipWeapon(weapons[2]);
			if (randChance(mt) < 3.5)
			{
				z->addItem(consumables[int(randItem(mt))]);
			}
		}
		else if (z->getEnemyType() == "kobold hunter")
		{
			z->equipWeapon(weapons[5]);
			if (randChance(mt) < 3.5)
			{
				z->addItem(consumables[int(randItem(mt))]);
			}
		}
		else if (z->getEnemyType() == "kobold stabber")
		{
			z->equipWeapon(weapons[1]);
			if (randChance(mt) < 3.5)
			{
				z->addItem(consumables[int(randItem(mt))]);
			}
		}
		else if (z->getEnemyType() == "kobold stealer")
		{
			z->equipWeapon(weapons[4]);
			if (randChance(mt) < 3.5)
			{
				z->addItem(consumables[int(randItem(mt))]);
			}
		}
		else if (z->getEnemyType() == "orc berserker")
		{
			z->equipWeapon(weapons[0]);
			if (randChance(mt) < 3.5)
			{
				z->addItem(consumables[int(randItem(mt))]);
			}
		}
		else if (z->getEnemyType() == "orc brawler")
		{
			// has literally nothing, fights with fists
		}
		else if (z->getEnemyType() == "orc warrior")
		{
			z->equipWeapon(weapons[3]);
			if (randChance(mt) < 3.5)
			{
				z->addItem(consumables[int(randItem(mt))]);
			}
		}
		else if (z->getEnemyType() == "vampire lord")
		{
			z->addItem(victoryNote);
			z->addItem(MorbisRing);
		}
		else {}
	}

	//SPAWN ITEMS IN ROOMS
	rooms[0]->addItem(wantedPoster);
	rooms[1]->addItem(gemstone);
	rooms[9]->addItem(wantedPoster);
	rooms[23]->addItem(consumables[1]);

	//SPAWN HIDDEN ITEMS IN ROOMS
	rooms[9]->addHidden(weapons[3]);
	rooms[9]->setHiddenContainer("Chest");
	rooms[1]->addHidden(consumables[0]);
	rooms[1]->addHidden(cpnKey);
	rooms[1]->setHiddenContainer("Wood Pile");

	//SPAWN HIDDEN GOLD IN ROOMS
	rooms[11]->setStash(15);
	rooms[18]->setStash(5);

	//GIVE PLAYER STARTING ITEMS
	player->addItem(consumables[0]);
	player->addItem(consumables[1]);
	player->addGold(20);

	//GIVE PLAYER STARTING SPELLS
	player->addSpell(spells[0]);
	player->addSpell(spells[1]);

	//VECTORS OF ATTACKS THE PLAYER CAN PERFORM
	std::vector<std::string> meleeAttacks;
	meleeAttacks.push_back("Melee Attack");		//standard
	meleeAttacks.push_back("Dab");			//less likely to hit but does more damage
	meleeAttacks.push_back("T-Pose");		//no damage but can prevent enemy from acting
	meleeAttacks.push_back("Keyboard Smash");	//more likely to hit but does less damage

	std::vector<std::string> rangedAttacks;
	rangedAttacks.push_back("Ranged Attack");	//standard
	rangedAttacks.push_back("Aim for the Head");	//less likely to hit but does more damage
	rangedAttacks.push_back("Air Drop Memes");	//no damage but can prevent enemy from acting
	rangedAttacks.push_back("Trick Shot");		//more likely to hit but does less damage

	//DISPLAY WELCOME MESSAGE
	std::cout << "Welcome to Esteves's Castle, " << player->getName() << "!" << std::endl << std::endl
		<< "After beating everyone up (With your mind device) in the Computer Science wing, and even defeating Grandmaster Esteves himself in order to get higher than a B in your computer Science Class, \n you may finally return home to the warm embrace of your Girlfriend...\n\n Except that the Grandmaster isn't done with you yet... \n With acesss to the latest teleportation technology, he shoves you into his big monitor.\n Rather than smashing into the monitor, you go into Esteves's Caste, a DnD inspired world.\n\n Let us Begin the Game."
		<< std::endl <<std::endl << "If you are not sure of what to do, type 'help' and press ENTER."
		<< std::endl << std::endl;

	//split userInput into a verb and noun, separated by a space
	int space;
	std::string verb;
	std::string noun;

	//bool keeps track of whether player entered a situation that triggered combat
	bool inCombat = false;

	//vector keeps track of enemies who player is currently in combat with
	std::vector<Enemy*> combatants;

	//int keeps track of position in vector
	int y;

	//this bool keeps track of whether the boss is dead
	bool bossDead = false;

	while (true)
	{
		//check to see if any enemy is in the same room as the player

		//int keeps track of position in vector
		y = 0;
		//compare player's currentRoom to each enemy's currentRoom
		for (auto i : enemies)
		{
			
			//if there is a match, combat occurs and add all enemies with that currentRoom pointer to the combat
			if (i->getRoom() == player->getRoom())
			{
				//presence of enemy means player is in combat, so alert player of this
				std::cout << "--- ENEMY SIGHTED ---" << std::endl;
				inCombat = true;
				//add the enemy to list of combatants who the player will have to fight
				combatants.push_back(i);
				//remove enemy from list of enemies (so won't fight them again later)
				//NOTE - putting enemies in same room next to each other in vector won't work, because erasing an element then iterating causes the element after the erased one to be skipped by the iterator
				enemies.erase(enemies.begin() + y);
				//i now points to the next enemy in the vector, who was shifted up to the erased enemy's position
				//std::advance(i,1);
			}
			y++;
		}

		//if not in combat, describe room to player and ask for action
		if (!inCombat)
		{
			//before each action, see if the player has gained a level (will occur immediately after combat if this is the case)
			player->checkLevel();

			//display short description of player's current room
			std::cout << std::endl << player->getRoom()->getDescription() << std::endl;
			//display long text of player's current room, only if has not already been here
			if (player->getRoom()->getVisitedStatus() == true)
			{
				//after displaying the text, change the status to mark that the player HAS been here now
				std::cout << player->getRoom()->getText() << std::endl;
				player->getRoom()->changeVisitedStatus();
			}
			if (player->getRoom()->getText() != "")
			{
				std::cout << std::endl;
			}

			//display doors to player
			player->showDoors();

			//show visible items in current room
			player->getRoom()->showItems();

			//show gold if any
			if (player->getRoom()->getGold() > 0)
			{
				std::cout << "You see " << player->getRoom()->getGold() << " gold coins in this area." << std::endl;

			}

			//ask player for input
			std::cout << "What do you do? ";
			std::getline(std::cin, userInput);

			//split userInput into a verb and noun, separated by a space
			space = userInput.find_first_of(' ');
			verb = userInput.substr(0, space);
			noun = userInput.substr(space + 1);


			//if player types "help" then show a list of commands
			if (verb == "help")
			{
				std::cout << std::endl << "LIST OF VALID COMMANDS:" << std::endl << "-----------------------" << std::endl
					<< "help - opens up a list of commands the player can give the game" << std::endl
					<< "go [north/east/south/west/up/down] - move in a specified direction" << std::endl
					<< "inventory - see your character's status and list of carried items" << std::endl
					<< std::endl
					<< "equip [item] - ready a weapon or don a piece of armor in your inventory" << std::endl
					<< "unequip [weapon/shield/head/torso/legs] - place an equipped item back into your inventory" << std::endl
					<< std::endl
					<< "take [item] - take a particular item from the room you are currently in" << std::endl
					<< "take all - take every single accessible item in the room you are currently in, as well as the gold" << std::endl
					<< "take gold - take all the visible gold in your current room" << std::endl
					<< "drop [item] - drop a particular item you are currently carrying onto the floor of the room you are currently in" << std::endl
					<< "drop all - drop everything you are currently carrying EXCEPT your gold" << std::endl
					<< "drop gold - why would you even want to do this ???" << std::endl
					<< std::endl
					<< "search - reveals hidden item container and doors you are currently in" << std::endl
					<< "search [container]- shows items inside a container" << std::endl
					<< "look - displays the room description again" << std::endl
					<< "examine [item] - get a description of a particular thing in your inventory" << std::endl
					<< "use [item] - use an item in your inventory" << std::endl
					<< "open [north/east/south/west/up/down] - open a door in a specific direction" << std::endl
					<< "unlock [north/east/south/west/up/down] - unlock a door in a specific direction, if you have the key" << std::endl
					<< std::endl
					<< "quit - close the game (please don't leave ... please?)" << std::endl;

			}
			//show player what he is carrying if he enters "inventory"
			else if (verb == "inventory")
			{
				player->displayPlayer();
				player->showStats();
				player->showSpells();
				player->showInventory();
			}
			else if (verb == "go")
			{
				//go to room specified by player
				player->setRoom(player->getRoom()->getRoom(noun));
			}
			else if (verb == "take")
			{
				//take all
				if (noun == "all")
				{
					player->takeAll();
					player->takeGold();
				}
				//take gold
				else if (noun == "gold")
				{
					player->takeGold();
				}
				//take item
				else
				{
					player->takeItem(noun);
				}
			}
			else if (verb == "drop")
			{
				//drop all
				if (noun == "all")
				{
					player->dropInventory();
				}
				//drop gold
				else if (noun == "gold")
				{
					player->dropGold();
				}
				//drop item
				else
				{
					player->dropItem(noun);
				}
			}
			else if (verb == "search")
			{
				if (noun == player->getRoom()->getHiddenContainer())
				{
					//hidden to unhidden
					player->searchHidden();
				}
				else
				{
					player->search();
				}
			}
			else if (verb == "look")
			{
				std::cout << player->getRoom()->getText() << std::endl;
				if (player->getRoom()->getText() != "")
				{
					std::cout << std::endl;
				}
			}
			else if (verb == "examine")
			{
				player->look(noun);
			}
			else if (verb == "use")
			{
				player->useItem(noun, consumables);
			}
			else if (verb == "unequip")
			{
				//copy item to inventory, then make pointer null
				if ( (noun == "weapon") && (player->getWeapon() != nullptr) )
				{
					player->addItem(player->getWeapon());
					player->equipWeapon(nullptr);
				}
				else
				{
					std::cout << "Can't unequip that!" << std::endl;
				}
			}
			else if (verb == "equip")
			{
				//run method to figure out what category of equipable item the item is
				std::string invCheck = player->equip(noun);
				
				if (invCheck == "")
				{
					std::cout << "That type of item cannot be equipped." << std::endl;
				}
				else if (invCheck == "x")
				{
					std::cout << "No such item found in your inventory." << std::endl;
				}
				else if ((invCheck == "weapon") && (player->getWeapon() == nullptr))
				{
					//set pointer by iterating through weapons vector until match is found
					for (auto c : weapons)
					{
						if (c->getName() == noun)
						{
							player->equipWeapon(c);
							break;
						}
					}
				
				}
				else {
					std::cout << "Slot taken. Unequip slot first." << std::endl;
					//add item back to inventory since could not be equipped
					for (auto c : weapons)
					{
						if (c->getName() == noun)
						{
							player->addItem(c);
							break;
						}
					}
				}
			}
			else if (verb == "open")
			{
				player->open(noun);
			}
			else if (verb == "unlock")
			{
				player->unlock(noun);
			}
			else if (verb == "quit")
			{
				exit(0);
			}
			else
			{
				std::cout << std::endl << std::endl << "I don't know what I just tried to do, but it didn't work. Let me try that again." << std::endl << std::endl;
			}

		}
		//else, there are enemies present, so enter combat
		else
		{			
			//while some enemies are still alive ...
			while (!combatants.empty())
			{
				//at the start of each round, display player information and enemy information
				player->displayPlayer();
				std::cout << std::endl << std::endl << "ENEMY COMBATANTS:" << std::endl;
				for (auto x : combatants)
				{
					x->displayEnemy();
				}

				//clear userInput so can be used for combat
				userInput = "";

				while (userInput == "")
				{
					//show possible combat actions to player
					std::cout << std::endl << std::endl << "AVAILABLE MOVES:" << std::endl
						<< "- Attack" << std::endl
						<< "- Cast Spell" << std::endl
						<< "- Use Item" << std::endl;
					while (userInput != "Attack" && userInput != "Cast Spell" && userInput != "Use Item")
					{
						//tell user that their input is invalid
						//std::cout << std::endl << "Invalid input. Try again, typing each word in lower case." << std::endl;
						//get user input
						std::getline(std::cin, userInput);
					}

					bool test = true;		//makes sure user input is valid
					int att = 0;			//keeps track of which attack type (i.e. address in meleeAttacks or rangedAttacks vector)
					int myAttack;			//saves att when it is right to do so


					//now use userInput to display appropriate submenu
					if (userInput == "Attack")
					{
						//attacks have variant names, depending on whether melee or ranged weapon is equipped
						std::cout << std::endl << std::endl << "AVAILABLE ATTACKS:" << std::endl;
						//melee weapons or fists
						if (player->getWeapon() == nullptr || player->getWeapon()->getType() == 0)
						{
							//display options
							for (auto i : meleeAttacks)
							{
								std::cout << i << ", ";
							}
							std::cout << std::endl;



							while (test)
							{
								std::getline(std::cin, userInput);
								for (auto i : meleeAttacks)
								{
									if (userInput == i)
									{
										myAttack = att;
										test = false;
										break;
									}
									att++;
								}
							}

						}
						//ranged weapons
						else
						{
							//display options
							for (auto i : rangedAttacks)
							{
								std::cout << i << ", ";
							}
							std::cout << std::endl;

							while (test)
							{
								std::getline(std::cin, userInput);
								for (auto i : rangedAttacks)
								{
									if (userInput == i)
									{
										myAttack = att;
										test = false;
										break;
									}
								}
							}
						}


						int x = 0;
						test = true;
						while (test)
						{
							//ask player for name of target
							std::cout << std::endl << std::endl << "TARGET: ";
							std::getline(std::cin, userInput);
							std::cout << std::endl;

							x = 0;

							for (auto i : combatants)
							{
								if (userInput == i->getName())
								{
									test = false;
									break;
								}
								x++;
							}
						}

						
						//after proper input is verified, attack target
						player->attack(combatants[x], myAttack);
						std::cout << std::endl;

					}
					else if (userInput == "Cast Spell")
					{
						//show list of spells the player can use
						player->showSpells();

						//ask player for spell to cast
						std::cout << "CAST: ";
						std::getline(std::cin, userInput);
						std::cout << std::endl;

						//iterate through vector of spells until match
						for (auto i : spells)
						{
							//if name matches, do castSpell method (which checks to make sure player knows spell and has enough mana)
							if (i->getName() == userInput)
							{
								//if healing spell, player targets self
								if (i->getEffect() == "heal")
								{
									player->castSpell(i, player);
								}
								//if damaging spell, ask player for target
								else if (i->getEffect() == "damage")
								{
									int x = 0;
									test = true;
									while (test)
									{
										//ask player for name of target
										std::cout << std::endl << std::endl << "TARGET: ";
										std::getline(std::cin, userInput);
										std::cout << std::endl;

										x = 0;

										for (auto a : combatants)
										{
											if (userInput == a->getName())
											{
												player->castSpell(i, a);
												test = false;
												break;
											}
											x++;
										}
									}
									
								}
								
							}
						}

					}
					else if (userInput == "Use Item")
					{
						//show list of items in player inventory
						player->showInventory();
						
						//ask player for item to use
						std::cout << "USE: ";
						std::getline(std::cin, userInput);
						std::cout << std::endl;

						player->useItem(userInput, consumables);
					}
					else
					{
						//shouldn't happen
						userInput = "";
					}
				}




				//after each player action, check to see if any enemy combatants are dead
				int check = 0;
				for (auto e : combatants)
				{
					if (e->getHealth() <= 0)
					{
						//if enemy is dead, add XP val to player's current XP
						player->addXP(e->getXP());
						//alert player of XP gain
						std::cout << "You gained " << e->getXP() << " experience from defeating " << e->getName() << std::endl;
						//then remove from combatants vector
						combatants.erase(combatants.begin() + check);
					}
					check++;
				}

				//enemies act after player
				for (auto e : combatants)
				{
					//each enemy acts in turn, attacking player
					//enemies only use their standard attack

					//make sure that enemy has not been stunned first
					if (e->getStunned() != true)
					{ e->attack(player, 0); }
					//if enemy is stunned, he spends his turn recovering
					else { e->setStunned(false); }

					//being in the presence of Morbis causes the player to lose 1 health per turn
					if (e->getEnemyType() == "vampire lord" && e->getHealth()>0 && player->getHealth()>0)
					{
						std::cout << "You feel drained from being in the presence of " << e->getName() << std::endl;
						player->takeDamage(1);
						e->healDamage(1);
					}

					//after each enemy action, check to see if player is dead
					if (player->getHealth() <= 0)
					{
						//if player is dead, display game over message
						std::cout << "You were killed by " << e->getName() << "!" << std::endl << std::endl << std::endl << std::endl
                                << "You were unable to escape Esteves palace, and are now doomed to serve him until someone else dethrones him..." << std:: endl
                                << "Best you hope that someone with a GF comes and saves you." << std::endl
				<< "--- GAME OVER ---" << std::endl << std::endl
				<< "Press any key to leave ";
						int a;
						std::cin >> a;
						exit(0);
					}
					
				}
			}

			//after combat is finished, take player out of combat
			inCombat = false;
			//clear combatants vector
			combatants.clear();
			std::cout << std::endl << std::endl << "You have vanquished your foes and emerge victorious!" << std::endl << std::endl;
		}
	}
}

std::vector<Room*> initRooms(std::vector<Room*> rooms)
{
	//1. Create a room, giving it a name and adding it to the rooms vector
	//2. Give the room some flavor text for the player to read
	//3. Set each room's connections to other rooms (north, east, south, west, up, down)
	
	//Step 1 and Step 2
	rooms.push_back(new Room("Gatehouse"));					//0
	rooms[0]->setText("You are in the gatehouse of Castle Esteves's outer wall. The portcullis is down, blocking your escape to the road south. Stairs lead up to the battlements, and down below the ground. The castle courtyard is to your north.");

	rooms.push_back(new Room("Contraband Room"));			//1
	rooms[1]->setText("You are in the castle's contraband room, where weapons and illegal goods would be seized from visitors and stored here. Luckily, nobody stopped you when you entered.You happen to find stack overflow signs that have been crossd out.");
	
	rooms.push_back(new Room("Battlements"));				//2
	rooms[2]->setText("From atop the gatehouse you can observe the surrounding forests and the layout of the castle. West of the courtyard there is a chapel. East of the courtyard is the armory. North of the courtyard is the castle keep, where you expect the vampire would be. There is a winch to the portcullis but its chains are rusted in place. He really has a detailed DND castle... Great.");

	rooms.push_back(new Room("Courtyard (S.)"));			//3
	rooms[3]->setText("You are standing in the south end of the courtyard. The yard extends to the north, east, and west, where it connects to various buildings.");

	rooms.push_back(new Room("Courtyard (W.)"));			//4
	rooms[4]->setText("You are standing in the west end of the courtyard. Further to the west is the chapel.");

	rooms.push_back(new Room("Courtyard (E.)"));			//5
	rooms[5]->setText("You are standing in the east end of the courtyard. Further to the east is the armory.");

	rooms.push_back(new Room("Courtyard (N.)"));			//6
	rooms[6]->setText("You are standing in the north end of the courtyard. The entrance to the castle keep is further to your north.");

    	rooms.push_back(new Room("Esteves's Chapel"));					//7
	rooms[7]->setText("You are standing in the chapel, where the castle lord (Esteves) would have his subjects come to pray to him. There is a ruined altar on the opposite side of the room, behind which are stone steps that lead to darkness. The room is illuminated through the broken stained glass that once depicted various saints.");

	rooms.push_back(new Room("Tomb"));						//8
	rooms[8]->setText("Here seems to lie a tomb of someone's who should have been there but has been unearthed... Spooky.\nStone steps lead upwards, to a faint light.");
	
	rooms.push_back(new Room("Armory"));					//9
	rooms[9]->setText("This room contains heaps of broken weapons and rusted armor. There are two sets of rickety wooden stairs, one leading up and the other below.\n The amount of broken stuff implies that you aren't the only one that's been thrown into his Castle.");
	
	rooms.push_back(new Room("Captain's Quarters"));		//10
	rooms[10]->setText("On the far side of the room is a tidy desk, and to the east a well-made bed. Behind you is a set of stairs, leading down.");
	
	rooms.push_back(new Room("Barracks"));					//11
	rooms[11]->setText("This is where the castle garrison would rest while off-duty... Wait he has a garrison?! Many unmade bunks line the walls. Some stairs lead above to the armory.");
	
	rooms.push_back(new Room("Castle Entrance"));			//12
	rooms[12]->setText("You are on the steps leading up to the door of the keep. As you near, the hairs on the back of your neck stand on end. The entrance was very midieval, however this is a mix between science fiction and medieval! \n The courtyard lies behind you, to the south.");
	
	rooms.push_back(new Room("Great Hall (S.)"));			//13
	rooms[13]->setText("You are standing in the south end of the great hall. The center of the room is occupied by a massive bare table with benches on either side, along the wall you see monitors that stream memes from r/programmerhumor, r/memes among other subreddits being displayed... ");
	
	rooms.push_back(new Room("The Room"));				//14
	rooms[14]->setText("On the wall... There's a name written in blood... 'Lisa' God damn Tommy Wiseau");
	
	rooms.push_back(new Room("Great Hall (N.)"));			//15
	rooms[15]->setText("You are standing in the north end of the great hall. The table comes to an end here, where a big monitor stands grand, to entertain guests. To the north is another table where the lord would sit with his guests of honor. There is a wide passage to your west.");
	
	rooms.push_back(new Room("Throneroom"));				//16
	rooms[16]->setText("You are at the head of the great hall, where sits the lord's throne and several tall chairs for his guests. A table here runs perpendicular to the one to the south. Someone's a fan of game of thrones. Oh and he also his chair says meme king.");
	
	rooms.push_back(new Room("War Room"));					//17
	rooms[17]->setText("Here is the least midieval looking room. This place is basically ripped from the movie Alien. Like there's buttons everywhere, big old computers with wires runing everywhere.\n the Biggest question you ask is how they were able to get this powered, whatever moving on. ");
	
	rooms.push_back(new Room("Servants' Quarters"));		//18
	rooms[18]->setText("Many untidy bunks fill this cramped, dark room. The pantry connects directly to the north. You feel bad for whoever has to listen to videogame OST's the whole time they're working.");
	
	rooms.push_back(new Room("Pantry"));					//19
	rooms[19]->setText("This small room contains a vast selection of rotten fruits, mildewed vegetables, and moldy cheeses. That smells bloody awful, best to leave before you pass out! The kitchen is to your north, and the servants' quarters to your south.");
	
	rooms.push_back(new Room("Kitchen"));					//20
	rooms[20]->setText("This large room has many bare and wide tables set around for preparing food. There is a fireplace full of ash in one corner. The walls are lined with cabinets that once contained utensils. Damn, you felt like preparing some mac and cheese... Whatever, The pantry connects directly to the south.");
	
	rooms.push_back(new Room("Wine Cellar (N.)"));			//21
	rooms[21]->setText("Standing in the north end of the wine cellar, there is a lingering smell of fermented grapes. The walls are lined with racks. To your disappointment most of the bottles here have been smashed. (unless you're under 21 years old) The cellar continues to the south.");
	
	rooms.push_back(new Room("Wine Cellar (S.)"));			//22
	rooms[22]->setText("Standing in the south end of the wine cellar, rotten kegs of ale are scattered around the floor. The cellar continues to your north and south.");
	
	rooms.push_back(new Room("Herb Storage"));				//23
	rooms[23]->setText("Many different dried herbs hang from the ceiling. You have the curiosity to see if he smokes... No he doesn't. Damn. Most appear to have been nibbled at by fruit bats. There are shelves of glass jars, containing the remains of fruits that turned to mush long ago. The cellar continues to the north.");
	
	rooms.push_back(new Room("Grand Staircase (Bottom)"));	//24
	rooms[24]->setText("You are standing at the bottom of the grand staircase. It continues up to the west. The great hall is to your east.");
	
	rooms.push_back(new Room("Grand Staircase (Top)"));		//25
	rooms[25]->setText("You are standing at the top of the grand staircase. It leads down, to the east. You are standing in the ruins of a hallway.");
	
	rooms.push_back(new Room("Tower (Middle)"));			//26
	rooms[26]->setText("You are standing on the landing of a round tower, with stairs leading up and down from your position.");
	
	rooms.push_back(new Room("Tower (Base)"));				//27
	rooms[27]->setText("You are standing at the bottom of the tower. It is nearly pitch-black in here, but you think you can make out some plastic Halloween skeletons shackled to the walls. Creepy! Get me out of here!");
	
	rooms.push_back(new Room("Tower (Top)"));				//28
	rooms[28]->setText("You are standing at the top of the tower. From here you can survey the countryside for miles in any direction. There is a glimmer of sunlight on the eastern horizon.");


	//Step 3
	rooms[0]->setRooms(rooms[3], nullptr, nullptr, nullptr, rooms[2], rooms[1]);
	rooms[1]->setRooms(nullptr, nullptr, nullptr, nullptr, rooms[0], nullptr);
	rooms[2]->setRooms(nullptr, nullptr, nullptr, nullptr, nullptr, rooms[0]);
	rooms[3]->setRooms(rooms[6], rooms[5], rooms[0], rooms[4], nullptr, nullptr);
	rooms[4]->setRooms(rooms[6], rooms[5], rooms[3], rooms[7], nullptr, nullptr);
	rooms[5]->setRooms(rooms[6], rooms[9], rooms[3], rooms[4], nullptr, nullptr);
	rooms[6]->setRooms(rooms[12], rooms[5], rooms[3], rooms[4], nullptr, nullptr);
	rooms[7]->setRooms(nullptr, rooms[4], nullptr, nullptr, nullptr, rooms[8]);
	rooms[8]->setRooms(nullptr, nullptr, nullptr, nullptr, rooms[7], nullptr);
	rooms[9]->setRooms(nullptr, nullptr, nullptr, rooms[5], rooms[10], rooms[11]);
	rooms[10]->setRooms(nullptr, nullptr, nullptr, nullptr, nullptr, rooms[9]);
	rooms[11]->setRooms(nullptr, nullptr, nullptr, nullptr, rooms[9], nullptr);
	rooms[12]->setRooms(rooms[13], nullptr, rooms[6], nullptr, nullptr, nullptr);
	rooms[13]->setRooms(rooms[15], rooms[18], rooms[12], rooms[14], nullptr, nullptr);
	rooms[14]->setRooms(nullptr, rooms[13], nullptr, nullptr, nullptr, nullptr);
	rooms[15]->setRooms(rooms[16], rooms[19], rooms[13], rooms[24], nullptr, nullptr);
	rooms[16]->setRooms(nullptr, rooms[20], rooms[15], rooms[17], nullptr, nullptr);
	rooms[17]->setRooms(nullptr, rooms[16], nullptr, nullptr, nullptr, nullptr);
	rooms[18]->setRooms(rooms[19], nullptr, nullptr, rooms[13], nullptr, nullptr);
	rooms[19]->setRooms(rooms[20], nullptr, rooms[18], rooms[15], nullptr, nullptr);
	rooms[20]->setRooms(nullptr, nullptr, rooms[19], rooms[16], nullptr, rooms[21]);
	rooms[21]->setRooms(nullptr, nullptr, rooms[22], nullptr, rooms[20], nullptr);
	rooms[22]->setRooms(rooms[21], nullptr, rooms[23], nullptr, nullptr, nullptr);
	rooms[23]->setRooms(rooms[22], nullptr, nullptr, nullptr, nullptr, nullptr);
	rooms[24]->setRooms(nullptr, rooms[15], nullptr, rooms[25], rooms[25], nullptr);
	rooms[25]->setRooms(nullptr, rooms[24], nullptr, rooms[26], nullptr, rooms[24]);
	rooms[26]->setRooms(nullptr, rooms[25], nullptr, nullptr, rooms[28], rooms[27]);
	rooms[27]->setRooms(nullptr, nullptr, nullptr, nullptr, rooms[26], nullptr);
	rooms[28]->setRooms(nullptr, nullptr, nullptr, nullptr, nullptr, rooms[26]);

	//return the vector to main when done setting up the rooms
	return rooms;
}
