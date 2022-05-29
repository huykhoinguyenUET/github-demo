#include "MyGame.h"

MyGame::MyGame()
{
	name = "";
	health = 0; dmg = 0; gold = 0;
}

MyGame::~MyGame()
{
}

MyGame::MyGame(string name, int health, int dmg, int gold)
{
	this->name = name;
	this->health = health;
	this->dmg = dmg;
	this->gold = gold;
}

string MyGame::getName()
{
	return name;
}

int MyGame::getHealth()
{
	return health;
}

int MyGame::getDmg()
{
	return dmg;
}

int MyGame::getGold()
{
	return gold;
}

void MyGame::setHealth(int health)
{
	this->health = health;
}
