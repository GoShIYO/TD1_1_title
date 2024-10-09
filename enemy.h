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
	int moveTimer;
	int graphHandle;
	int direction;
	int moveTimer;
	int graphHandle;
	int direction;
	bool isAlive;
	bool isMove;
};

void InitEnemyNormal(Enemy& enemy);
void InitEnemyHorming(Enemy& enemy);

void EnemyMove(Enemy& enemy);
void EnemyMoveHorming(Enemy& enemy);

void RenderEnemy(Enemy& enemy, Vector2& scroll);