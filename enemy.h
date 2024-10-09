#pragma once
#include <Vector2.h>

enum EnemyDirection {
	UP = 0,
	DOWN = 1,
	RIGHT = 2,
	LEFT = 3
};

struct Enemy {
	Vector2 pos;
	Vector2 velocity;
	float width;
	float height;
	float angle;
	int moveTimer;
	int graphHandle;
	int direction;
	bool isAlive;
	bool isMove;
};

void InitEnemy(Enemy& enemy);
void EnemyMove(Enemy& enemy);

void RenderEnmey(Enemy& enemy);