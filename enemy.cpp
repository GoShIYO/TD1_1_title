#define _USE_MATH_DEFINES
#define MOVE_TIME 60
#define STOP_TIME 120
#include "enemy.h"
#include <math.h>
#include <Novice.h>

void InitEnemy(Enemy& enemy) {
	enemy.pos.x = 700.0f;
	enemy.pos.y = 400.0f;
	enemy.velocity.x = 5.0f;
	enemy.velocity.y = 5.0f;
	enemy.width = 32.0f;
	enemy.height = 32.0f;
	enemy.angle = (float)(M_PI) / 8.0f;
	enemy.moveTimer = 0;
	enemy.graphHandle = Novice::LoadTexture("./Resources/enemy.png");
	enemy.isAlive = true;
	enemy.isMove = false;
}

void EnemyMove(Enemy& enemy) {
	enemy.moveTimer++;

	if (enemy.moveTimer >= MOVE_TIME) {
		enemy.isMove = true;
	}
	if (enemy.isMove) {
		enemy.pos.x += enemy.velocity.x;
		if (enemy.moveTimer >= STOP_TIME) {
			enemy.moveTimer = 0;
			enemy.isMove = false;
		}
	}
}

void RenderEnmey(Enemy& enemy) {
	Novice::DrawSprite((int)enemy.pos.x, (int)enemy.pos.y, enemy.graphHandle, 1, 1, 0.0f, WHITE);
}

void EnemyDebug(Enemy& enemy) {
	Novice::ScreenPrintf(0, 0, "enemy.isMove : %d", enemy.isMove);
	Novice::ScreenPrintf(0, 20, "enemy.moveTimer : %d", enemy.moveTimer);
}