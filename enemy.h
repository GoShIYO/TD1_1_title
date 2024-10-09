#pragma once
#include <Vector2.h>

struct Enemy {
	Vector2 pos;
	Vector2 velocity;
	float width;
	float height;
	float angle;
	int moveTimer;
	int graphHandle;
	bool isAlive;
	bool isMove;
};

void InitEnemy(Enemy& enemy);
void EnemyMove(Enemy& enemy);

void RenderEnmey(Enemy& enemy);
void EnemyDebug(Enemy& enemy);