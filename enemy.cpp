#define _USE_MATH_DEFINES
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
	enemy.pos.x = 200.0f;
	enemy.pos.y = 700.0f;
	enemy.velocity.x = 1.0f;
	enemy.velocity.y = 1.0f;
	enemy.components.x = 0.0f;
	enemy.components.y = 0.0f;
	enemy.directions.x = 0.0f;
	enemy.directions.y = 0.0f;
	enemy.magnitude = 0.0f;
	enemy.width = 32.0f;
	enemy.height = 32.0f;
	enemy.graphHandle = Novice::LoadTexture("./Resources/enemy2.png");
	enemy.direction = 0;
	enemy.isAlive = true;
	enemy.isMove = false;
}

void InitEnemyShot(Enemy& enemy) {
	enemy.pos.x = 200.0f;
	enemy.pos.y = 700.0f;
	enemy.width = 32.0f;
	enemy.height = 32.0f;
	enemy.graphHandle = Novice::LoadTexture("./Resources/enemy2.png");
	enemy.isAlive = true;
}

void InitEnemyBullet(EnemyBullet bullet[]) {
	for (int i = 0;i < BULLET_COUNT;i++) {
		bullet[i].pos.x = -10000.0f;
		bullet[i].pos.y = -10000.0f;
	}
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

void EnemyMoveHorming(Enemy& enemy, Obj player) {
	enemy.components.x = player.pos.x - enemy.pos.x;
	enemy.components.y = player.pos.y - enemy.pos.y;
	enemy.magnitude = (float)sqrt(pow(enemy.components.x, 2) + pow(enemy.components.y, 2));
	enemy.directions.x = enemy.components.x / enemy.magnitude;
	enemy.directions.y = enemy.components.y / enemy.magnitude;

	enemy.pos.x += enemy.directions.x * enemy.velocity.x;
	enemy.pos.y += enemy.directions.y * enemy.velocity.y;
}

void EnemyMoveShot(Enemy& enemy, Obj player, EnemyBullet bullet[]) {
	for (int i = 0;i < BULLET_COUNT;i++) {
		bullet[i].shotTimer++;
		if (bullet[i].shotTimer >= SHOT_TIME) {
			bullet[i].isShot = true;
			bullet[i].pos.x = enemy.pos.x;
			bullet[i].pos.y = enemy.pos.y;
			bullet[i].components.x = player.pos.x - bullet[i].pos.x;
			bullet[i].components.y = player.pos.y - bullet[i].pos.y;
			bullet[i].magnitude = (float)sqrt(pow(bullet[i].components.x, 2) + pow(bullet[i].components.y, 2));
			bullet[i].directions.x = bullet[i].components.x / bullet[i].magnitude;
			bullet[i].directions.y = bullet[i].components.y / bullet[i].magnitude;
			bullet[i].shotTimer = 0;
			break;
		}
		if (bullet[i].isShot) {
			bullet[i].pos.x += bullet[i].directions.x * bullet[i].velocity.x;
			bullet[i].pos.y += bullet[i].directions.y * bullet[i].velocity.y;
		}
	}
}

void RenderEnemy(Enemy& enemy, Vector2& scroll) {
	Novice::DrawSprite(int(enemy.pos.x - scroll.x), int(enemy.pos.y - scroll.y), enemy.graphHandle, 1, 1, 0.0f, WHITE);
}

void EnemyDebug(Enemy& enemy) {
	Novice::ScreenPrintf(0, 20, "hormingEnemy.pos.x : %f", enemy.pos.x);
	Novice::ScreenPrintf(0, 40, "hormingEnemy.pos.y : %f", enemy.pos.y);
}