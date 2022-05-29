#include "Player.h"

Player::Player()
{
	level = 0;
}

Player::~Player()
{
}

Player::Player(string name) : MyGame(name,10,1,0), level(0)
{
}

int Player::getLevel()
{
	return level;
}

void Player::fight(int dmg_monster)
{
	this->health = this->health - dmg_monster;
}

void Player::fight_win(int gold_ms)
{
	level = level + 1;
	health = health + 1;
	dmg = dmg + 1;
	gold = gold + gold_ms;
}
