#pragma once
#include <Vector2.h>
#include "obj.h"

enum EnemyDirection {
	UP = 0,
	DOWN = 1,
	RIGHT = 2,
	LEFT = 3
};

struct Enemy {
	Vector2 pos;
	Vector2 velocity;
	Vector2 components;
	Vector2 directions;
	float magnitude;
	float width;
	float height;
	int moveTimer;
	int graphHandle;
	int direction;
	bool isAlive;
	bool isMove;
};

void InitEnemyNormal(Enemy& enemy);
void InitEnemyHorming(Enemy& enemy);

void EnemyMove(Enemy& enemy);
void EnemyMoveHorming(Enemy& enemy, Obj& player);

void RenderEnemy(Enemy& enemy, Vector2& scroll);

//void EnemyDebug(Enemy& enemy);