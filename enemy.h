#pragma once
#include <Vector2.h>

struct Enemy {
	Vector2 pos;
	Vector2 velocity;
	float angle;
	bool isAlive;
};

void InitEnemy(Enemy* enemy);