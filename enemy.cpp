#define _USE_MATH_DEFINES
#include "enemy.h"
#include "obj.h"
#include <math.h>
#include <Novice.h>
#include <stdlib.h>

void InitEnemyNormal(Enemy enemy[]) {
	enemy[0].pos = { 0.0f, -12.0f };
	enemy[1].pos = { 240.0f, -120.0f };
	enemy[2].pos = { 480.0f, -120.0f };
	enemy[3].pos = { 720.0f, -120.0f };
	enemy[4].pos = { 960.0f, -120.0f };
	enemy[5].pos = { 1200.0f, -120.0f };

	enemy[6].pos = { 1320.0f, 0.0f };
	enemy[7].pos = { 1320.0f, 240.0f };
	enemy[8].pos = { 1320.0f, 480.0f };
	enemy[9].pos = { 1320.0f, 720.0f };

	enemy[10].pos = { 0.0f, 840.0f };
	enemy[11].pos = { 240.0f, 840.0f };
	enemy[12].pos = { 480.0f, 840.0f };
	enemy[13].pos = { 720.0f, 840.0f };
	enemy[14].pos = { 960.0f, 840.0f };
	enemy[15].pos = { 1200.0f, 840.0f };

	enemy[16].pos = { -120.0f, 0.0f };
	enemy[17].pos = { -120.0f, 240.0f };
	enemy[18].pos = { -120.0f, 480.0f };
	enemy[19].pos = { -120.0f, 720.0f };

	for (int i = 0;i < ENEMY_COUNT;i++) {
		enemy[i].velocity.x = 5.0f;
		enemy[i].velocity.y = 5.0f;
		enemy[i].width = 32.0f;
		enemy[i].height = 32.0f;
		enemy[i].radius = 16.0f;
		enemy[i].moveTimer = 0;
		enemy[i].direction = 0;
		enemy[i].isAlive = true;
		enemy[i].isMove = false;
		enemy[i].health = 1;
	}
}

void InitEnemyHorming(Enemy enemy[]) {
	enemy[0].pos = { 0.0f, -840.0f };
	enemy[1].pos = { 240.0f, -840.0f };
	enemy[2].pos = { 480.0f, -840.0f };
	enemy[3].pos = { 720.0f, -840.0f };
	enemy[4].pos = { 960.0f, -840.0f };
	enemy[5].pos = { 1200.0f, -840.0f };

	enemy[6].pos = { 1700.0f, 0.0f };
	enemy[7].pos = { 1700.0f, 240.0f };
	enemy[8].pos = { 1700.0f, 480.0f };
	enemy[9].pos = { 1700.0f, 720.0f };

	enemy[10].pos = { 0.0f, 1560.0f };
	enemy[11].pos = { 240.0f, 1560.0f };
	enemy[12].pos = { 480.0f, 1560.0f };
	enemy[13].pos = { 720.0f, 1560.0f };
	enemy[14].pos = { 960.0f, 1560.0f };
	enemy[15].pos = { 1200.0f, 1560.0f };

	enemy[16].pos = { -1300.0f, 0.0f };
	enemy[17].pos = { -1300.0f, 240.0f };
	enemy[18].pos = { -1300.0f, 480.0f };
	enemy[19].pos = { -1300.0f, 720.0f };

	for (int i = 0;i < ENEMY_COUNT;i++) {
		enemy[i].velocity.x = 2.0f;
		enemy[i].velocity.y = 2.0f;
		enemy[i].components.x = 0.0f;
		enemy[i].components.y = 0.0f;
		enemy[i].directions.x = 0.0f;
		enemy[i].directions.y = 0.0f;
		enemy[i].magnitude = 0.0f;
		enemy[i].width = 32.0f;
		enemy[i].height = 32.0f;
		enemy[i].radius = 16.0f;
		enemy[i].direction = 0;
		enemy[i].isAlive = true;
		enemy[i].isMove = false;
		enemy[i].health = 1;
	}
}

void InitEnemyShot(Enemy enemy[]) {
	enemy[0].pos = { 0.0f, -840.0f };
	enemy[1].pos = { 240.0f, -840.0f };
	enemy[2].pos = { 480.0f, -840.0f };
	enemy[3].pos = { 720.0f, -840.0f };
	enemy[4].pos = { 960.0f, -840.0f };
	enemy[5].pos = { 1200.0f, -840.0f };

	enemy[6].pos = { 1700.0f, 0.0f };
	enemy[7].pos = { 1700.0f, 240.0f };
	enemy[8].pos = { 1700.0f, 480.0f };
	enemy[9].pos = { 1700.0f, 720.0f };

	enemy[10].pos = { 0.0f, 1560.0f };
	enemy[11].pos = { 240.0f, 1560.0f };
	enemy[12].pos = { 480.0f, 1560.0f };
	enemy[13].pos = { 720.0f, 1560.0f };
	enemy[14].pos = { 960.0f, 1560.0f };
	enemy[15].pos = { 1200.0f, 1560.0f };

	enemy[16].pos = { -1300.0f, 0.0f };
	enemy[17].pos = { -1300.0f, 240.0f };
	enemy[18].pos = { -1300.0f, 480.0f };
	enemy[19].pos = { -1300.0f, 720.0f };

	for (int i = 0;i < ENEMY_COUNT;i++) {
		enemy[i].pos.x = 200.0f;
		enemy[i].pos.y = 700.0f;
		enemy[i].width = 32.0f;
		enemy[i].height = 32.0f;
		enemy[i].shotTimer = 0;
		enemy[i].isAlive = true;
	}
}

void InitEnemyBullet(EnemyBullet bullet[]) {
	for (int i = 0;i < BULLET_COUNT;i++) {
		bullet[i].pos.x = -10000.0f;
		bullet[i].pos.y = -10000.0f;
		bullet[i].velocity.x = 5.0f;
		bullet[i].velocity.y = 5.0f;
		bullet[i].components.x = 0.0f;
		bullet[i].components.y = 0.0f;
		bullet[i].directions.x = 0.0f;
		bullet[i].directions.y = 0.0f;
		bullet[i].magnitude = 0.0f;
		bullet[i].isShot = false;
	}
}

void EnemyMove(Enemy enemy[]) {
	for (int i = 0;i < ENEMY_COUNT;i++) {
		enemy[i].moveTimer++;

		if (enemy[i].moveTimer == MOVE_TIME) {
			enemy[i].isMove = true;
			enemy[i].direction = rand() % 3 + 1;
		}
		if (enemy[i].isMove) {
			switch (enemy[i].direction) {
			case UP:
				enemy[i].pos.y -= enemy[i].velocity.y;
				if (enemy[i].moveTimer >= STOP_TIME) {
					enemy[i].moveTimer = 0;
					enemy[i].isMove = false;
				}
				break;
			case DOWN:
				enemy[i].pos.y += enemy[i].velocity.y;
				if (enemy[i].moveTimer >= STOP_TIME) {
					enemy[i].moveTimer = 0;
					enemy[i].isMove = false;
				}
				break;
			case RIGHT:
				enemy[i].pos.x += enemy[i].velocity.x;
				if (enemy[i].moveTimer >= STOP_TIME) {
					enemy[i].moveTimer = 0;
					enemy[i].isMove = false;
				}
				break;
			case LEFT:
				enemy[i].pos.x -= enemy[i].velocity.x;
				if (enemy[i].moveTimer >= STOP_TIME) {
					enemy[i].moveTimer = 0;
					enemy[i].isMove = false;
				}
				break;
			}
		}
	}
}

void EnemyMoveHorming(Enemy enemy[], Obj& player) {
	for (int i = 0;i < ENEMY_COUNT;i++) {
		enemy[i].components.x = player.pos.x - enemy[i].pos.x;
		enemy[i].components.y = player.pos.y - enemy[i].pos.y;
		enemy[i].magnitude = (float)sqrt(pow(enemy[i].components.x, 2) + pow(enemy[i].components.y, 2));
		enemy[i].directions.x = enemy[i].components.x / enemy[i].magnitude;
		enemy[i].directions.y = enemy[i].components.y / enemy[i].magnitude;

		float distanceX = enemy[i].pos.x - player.pos.x;
		float distanceY = enemy[i].pos.y - player.pos.y;
		float distance = sqrtf(float(pow(distanceX, 2)) + float(pow(distanceY, 2)));

		if (distance <= ENEMY_TO_PLAYER) {
			enemy[i].pos.x += enemy[i].directions.x * enemy[i].velocity.x;
			enemy[i].pos.y += enemy[i].directions.y * enemy[i].velocity.y;
		}
	}
}

void BulletShot(Enemy enemy[], Obj player, EnemyBullet bullet[]) {
	for (int j = 0;j < ENEMY_COUNT;j++) {
		enemy[j].shotTimer++;
		for (int i = 0;i < BULLET_COUNT;i++) {
			if (enemy[j].shotTimer >= SHOT_TIME) {
				bullet[i].isShot = true;
				bullet[i].pos.x = enemy[j].pos.x;
				bullet[i].pos.y = enemy[j].pos.y;
				bullet[i].components.x = player.pos.x - bullet[i].pos.x;
				bullet[i].components.y = player.pos.y - bullet[i].pos.y;
				bullet[i].magnitude = (float)sqrt(pow(bullet[i].components.x, 2) + pow(bullet[i].components.y, 2));
				bullet[i].directions.x = bullet[i].components.x / bullet[i].magnitude;
				bullet[i].directions.y = bullet[i].components.y / bullet[i].magnitude;
				enemy[j].shotTimer = 0;
				break;
			}
			if (bullet[i].isShot) {
				bullet[i].pos.x += bullet[i].directions.x * bullet[i].velocity.x;
				bullet[i].pos.y += bullet[i].directions.y * bullet[i].velocity.y;
			}
			if (bullet[i].pos.x >= kWindowWidth * 3 || bullet[i].pos.x <= -kWindowWidth * 2 || bullet[i].pos.y >= kWindowHeight * 3 || bullet[i].pos.y <= -kWindowHeight * 2) {
				bullet[i].pos.x = -10000.0f;
				bullet[i].pos.y = -10000.0f;
				bullet[i].isShot = false;
			}
		}
	}
}

void RenderEnemy(Enemy enemy[], Vector2 scroll, int handle, float px, float py) {
	for (int i = 0;i < ENEMY_COUNT;i++) {
		float distanceX = enemy[i].pos.x - px;
		float distanceY = enemy[i].pos.y - py;
		float distance = sqrtf(static_cast<float>(pow(distanceX, 2)) + static_cast<float>(pow(distanceY, 2)));

		if (distance <= kWindowWidth) {
			if (enemy[i].isAlive) {
				Novice::DrawSprite(int(enemy[i].pos.x - scroll.x), int(enemy[i].pos.y - scroll.y), handle, 1, 1, 0.0f, WHITE);
			}
		}
	}
}

void RenderBullet(EnemyBullet bullet[], Vector2 scroll, int handle) {
	for (int i = 0;i < BULLET_COUNT;i++) {
		Novice::DrawSprite(int(bullet[i].pos.x - scroll.x), int(bullet[i].pos.y - scroll.y), handle, 1, 1, 0.0f, WHITE);
	}
}

void EnemyDebug(EnemyBullet bullet[]) {
	for (int i = 0;i < 5;i++) {
		Novice::ScreenPrintf(0, 100 * i, "bullet.pos.x : %f", bullet[i].pos.x);
		Novice::ScreenPrintf(100, 100 * i, "bullet.pos.y : %f", bullet[i].pos.y);
	}
}

bool CheckCircleCollision(Vector2& a, Vector2& b, const float& radiusA, const float& radiusB) {
	float x = a.x - b.x;
	float y = a.y - b.y;
	float distence = x * x + y * y;
	float radius = radiusA + radiusB;
	if (distence <= radius * radius) {
		return true;
	}
	return false;
}
void UpdatePlayerEnemyEvent(Enemy enemy[], Obj& player, char keys[], char preKeys[]) {
	const float r = 50.0f;
	for (int i = 0;i < ENEMY_COUNT;i++) {
		if (enemy[i].isAlive) {
			if (CheckCircleCollision(enemy[i].pos, player.pos, enemy[i].radius + r, player.radius)) {

				if (CheckCircleCollision(enemy[i].pos, player.pos, enemy[i].radius, player.radius) && !player.isCollied) {
					player.isCollied = true;
					player.health--;
				}
				if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
					if (!player.isRotate) {
						float dx = player.pos.x - enemy[i].pos.x;
						float dy = player.pos.y - enemy[i].pos.y;
						float angle = atan2f(dy, dx);
						player.angle += angle;
					}
					enemy[i].health--;
				}
			}
		}

		if (enemy[i].health <= 0) {
			enemy[i].isAlive = false;
		}
		Novice::ScreenPrintf(0, 60, "player.health : %d", player.health);
		Novice::ScreenPrintf(0, 80, "enemy.health : %d", enemy[i].health);
		Novice::ScreenPrintf(0, 100, "enemy.isAlive : %s", enemy[i].isAlive ? "alive" : "death");
	}

}

void LoadImages(Handle& handle) {
	handle.enemy = Novice::LoadTexture("./Resources/enemy.png");
	handle.enemyHorming = Novice::LoadTexture("./Resources/enemy2.png");
	handle.enemyShot = Novice::LoadTexture("./Resources/enemy2.png");
	handle.bullet = Novice::LoadTexture("./Resources/bullet.png");
	handle.deathEffect = Novice::LoadTexture("./Resources/effect.png");
}