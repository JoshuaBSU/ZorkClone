#pragma once
#include "Character.h"

class Enemy :
	public Character
{
public:
	Enemy();
	~Enemy();
	void displayEnemy();
	int getXP();
	std::string getEnemyType();
	
protected:
	int xpVal;
	std::string enemyType;
	bool undead;
};

