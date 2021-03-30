#include "Enemy.h"

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

void Enemy::displayEnemy()
{
	std::cout << this->name << ", " << this->enemyType << '\t' << "Health: " << this->currHealth << "/" << this->maxHealth << std::endl;
}

int Enemy::getXP()
{
	return this->xpVal;
}

std::string Enemy::getEnemyType()
{
	return this->enemyType;
}