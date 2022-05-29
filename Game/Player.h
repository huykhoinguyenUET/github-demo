#pragma once
#ifndef _PLAYER_
#define _PLAYER_
#include <iostream>
#include <string>
#include <cmath>
#include "MyGame.h"
using namespace std;

class Player: public MyGame
{
	private:
		int level;
	public:
		Player();
		~Player();
		Player(string name);
		int getLevel();
		void fight(int dmg_monster);
		void fight_win(int gold_ms);
};

#endif // !_PLAYER_

