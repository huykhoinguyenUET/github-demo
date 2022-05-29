#include "Monster.h"

Monster::Monster(){}

Monster::~Monster(){}

Monster::Monster(Type type) {
	if (type == Type::dragon) {
		name = "Dragon";
		dmg = 4;
		gold = rand() % 100 + 1;
		health = 20;
	}
	else if (type == Type::orc) {
		name = "Orc";
		dmg = 2;
		gold = rand() % 25 + 1;
		health = 4;
	}
	else if (type == Type::slime) {
		name = "Smile";
		dmg = 1;
		gold = rand()%10 + 1;
		health = 1;
	}
}

void Monster::fight(int dmg_player)
{
	this->health = this->health - dmg_player;
}
