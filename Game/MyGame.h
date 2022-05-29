#pragma once
#ifndef _MYGAME_
#define _MYGAME_
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
using namespace std;

class MyGame
{
protected:
	string name;
	int health, dmg, gold;
public:
	MyGame();
	~MyGame();
	MyGame(string name, int health, int dmg, int gold);
	string getName();
	int getHealth();
	int getDmg();
	int getGold();
	void setHealth(int);
};

#endif // !_MYGAME_