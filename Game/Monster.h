#pragma once
#ifndef _MONSTER_
#define _MONSTER_
#include "MyGame.h"

enum class Type : int{
	dragon,
	orc,
	slime,
	max,
};

class Monster:public MyGame
{	
	private:
		int type;
	public:
		Monster();
		~Monster();
		Monster(Type type);
		void fight(int dmg_player);
};

#endif // !_MONSTER_

