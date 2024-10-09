#define _USE_MATH_DEFINES
#define MOVE_TIME 60
#define STOP_TIME 120
#include "enemy.h"
#include "obj.h"
#include <math.h>
#include <Novice.h>
#include <stdlib.h>

void InitEnemyNormal(Enemy& enemy) {
	enemy.pos.x = 700.0f;
	enemy.pos.y = 400.0f;
	enemy.velocity.x = 5.0f;
	enemy.velocity.y = 5.0f;
	enemy.width = 32.0f;
	enemy.height = 32.0f;
	enemy.moveTimer = 0;
	enemy.graphHandle = Novice::LoadTexture("./Resources/enemy.png");
	enemy.direction = 0;
	enemy.isAlive = true;
	enemy.isMove = false;
}

void InitEnemyHorming(Enemy& enemy) {
	enemy.pos.x = 700.0f;
	enemy.pos.y = 400.0f;
	enemy.velocity.x = 5.0f;
	enemy.velocity.y = 5.0f;
	enemy.width = 32.0f;
	enemy.height = 32.0f;
	enemy.graphHandle = Novice::LoadTexture("./Resources/enemy.png");
	enemy.direction = 0;
	enemy.isAlive = true;
	enemy.isMove = false;
}

void EnemyMove(Enemy& enemy) {
	enemy.moveTimer++;

	if (enemy.moveTimer == MOVE_TIME) {
		enemy.isMove = true;
		enemy.direction = rand() % 3 + 1;
	}
	if (enemy.isMove) {
		switch (enemy.direction) {
		case UP:
			enemy.pos.y -= enemy.velocity.y;
			if (enemy.moveTimer >= STOP_TIME) {
				enemy.moveTimer = 0;
				enemy.isMove = false;
			}
			break;
		case DOWN:
			enemy.pos.y += enemy.velocity.y;
			if (enemy.moveTimer >= STOP_TIME) {
				enemy.moveTimer = 0;
				enemy.isMove = false;
			}
			break;
		case RIGHT:
			enemy.pos.x += enemy.velocity.x;
			if (enemy.moveTimer >= STOP_TIME) {
				enemy.moveTimer = 0;
				enemy.isMove = false;
			}
			break;
		case LEFT:
			enemy.pos.x -= enemy.velocity.x;
			if (enemy.moveTimer >= STOP_TIME) {
				enemy.moveTimer = 0;
				enemy.isMove = false;
			}
			break;
		}
	}
}

void EnemyMoveHorming(Enemy& enemy, Vector2& playerPos) {
	float componentsX = enemy.pos.x - playerPos.x;
	float componentsY = enemy.pos.y - playerPos.y;
	float magnitude = (float)sqrt(pow(componentsX, 2) + pow(componentsY, 2));
	float directionX = componentsX / magnitude;
	float directionY = componentsY / magnitude;

	enemy.pos.x = directionX * enemy.velocity.x;
	enemy.pos.y = directionY * enemy.velocity.y;
}

void RenderEnemy(Enemy& enemy, Vector2& scroll) {
	Novice::DrawSprite(int(enemy.pos.x - scroll.x), int(enemy.pos.y - scroll.y), enemy.graphHandle, 1, 1, 0.0f, WHITE);
}