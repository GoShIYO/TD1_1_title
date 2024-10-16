#define _USE_MATH_DEFINES
#include "enemy.h"
#include "obj.h"
#include <math.h>
#include <Novice.h>
#include <stdlib.h>

void InitEnemyNormal(Enemy enemy[]) {
	enemy[0].pos = { -3800.0f, -1400.0f };
	enemy[1].pos = { -3600.0f, -1300.0f };
	enemy[2].pos = { -3400.0f, -1200.0f };
	enemy[3].pos = { -3200.0f, -1100.0f };
	enemy[4].pos = { -3000.0f, -1000.0f };
	enemy[5].pos = { -2800.0f, -900.0f };
	enemy[6].pos = { -2600.0f, -800.0f };
	enemy[7].pos = { -2400.0f, -700.0f };
	enemy[8].pos = { -2200.0f, -600.0f };
	enemy[9].pos = { -2000.0f, -500.0f };
	enemy[10].pos = { -1800.0f, -400.0f };
	enemy[11].pos = { -1600.0f, -300.0f };
	enemy[12].pos = { -1400.0f, -200.0f };
	enemy[13].pos = { -1200.0f, -100.0f };
	enemy[14].pos = { -1000.0f, 0.0f };
	enemy[15].pos = { -800.0f, 100.0f };
	enemy[16].pos = { -600.0f, 200.0f };
	enemy[17].pos = { -400.0f, 300.0f };
	enemy[18].pos = { -200.0f, 400.0f };
	enemy[19].pos = { 0.0f, 500.0f };
	enemy[20].pos = { 200.0f, 600.0f };
	enemy[21].pos = { 400.0f, 700.0f };
	enemy[22].pos = { 600.0f, 800.0f };
	enemy[23].pos = { 800.0f, 900.0f };
	enemy[24].pos = { 1000.0f, 1000.0f };
	enemy[25].pos = { 1200.0f, 1100.0f };
	enemy[26].pos = { 1400.0f, 1200.0f };
	enemy[27].pos = { 1600.0f, 1300.0f };
	enemy[28].pos = { 1800.0f, 1400.0f };
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

void InitEnemyHorming(Enemy& enemy) {
	enemy.pos.x = 200.0f;
	enemy.pos.y = 700.0f;
	enemy.velocity.x = 2.0f;
	enemy.velocity.y = 2.0f;
	enemy.components.x = 0.0f;
	enemy.components.y = 0.0f;
	enemy.directions.x = 0.0f;
	enemy.directions.y = 0.0f;
	enemy.magnitude = 0.0f;
	enemy.width = 32.0f;
	enemy.height = 32.0f;
	enemy.radius = 16.0f;
	enemy.direction = 0;
	enemy.isAlive = true;
	enemy.isMove = false;
	enemy.health = 1;
}

void InitEnemyShot(Enemy& enemy) {
	enemy.pos.x = 200.0f;
	enemy.pos.y = 700.0f;
	enemy.width = 32.0f;
	enemy.height = 32.0f;
	enemy.shotTimer = 0;
	enemy.isAlive = true;
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

void EnemyMoveHorming(Enemy& enemy, Obj& player) {
	enemy.components.x = player.pos.x - enemy.pos.x;
	enemy.components.y = player.pos.y - enemy.pos.y;
	enemy.magnitude = (float)sqrt(pow(enemy.components.x, 2) + pow(enemy.components.y, 2));
	enemy.directions.x = enemy.components.x / enemy.magnitude;
	enemy.directions.y = enemy.components.y / enemy.magnitude;

	float distanceX = enemy.pos.x - player.pos.x;
	float distanceY = enemy.pos.y - player.pos.y;
	float distance = sqrtf(float(pow(distanceX, 2)) + float(pow(distanceY, 2)));

	if (distance <= ENEMY_TO_PLAYER) {
		enemy.pos.x += enemy.directions.x * enemy.velocity.x;
		enemy.pos.y += enemy.directions.y * enemy.velocity.y;
	}
}

void BulletShot(Enemy& enemy, Obj player, EnemyBullet bullet[]) {
	enemy.shotTimer++;
	for (int i = 0;i < BULLET_COUNT;i++) {
		if (enemy.shotTimer >= SHOT_TIME) {
			bullet[i].isShot = true;
			bullet[i].pos.x = enemy.pos.x;
			bullet[i].pos.y = enemy.pos.y;
			bullet[i].components.x = player.pos.x - bullet[i].pos.x;
			bullet[i].components.y = player.pos.y - bullet[i].pos.y;
			bullet[i].magnitude = (float)sqrt(pow(bullet[i].components.x, 2) + pow(bullet[i].components.y, 2));
			bullet[i].directions.x = bullet[i].components.x / bullet[i].magnitude;
			bullet[i].directions.y = bullet[i].components.y / bullet[i].magnitude;
			enemy.shotTimer = 0;
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

void EnemyDebug(EnemyBullet bullet, Enemy enemy) {
	Novice::ScreenPrintf(0, 20, "bullet.pos.x : %f", bullet.pos.x);
	Novice::ScreenPrintf(0, 40, "bullet.pos.y : %f", bullet.pos.y);
	Novice::ScreenPrintf(0, 120, "enemy.pos.x : %f", enemy.pos.x);
	Novice::ScreenPrintf(0, 140, "enemy.pos.y : %f", enemy.pos.y);
}

bool CheckCircleCollision(Vector2& a, Vector2& b,const float& radiusA,const float& radiusB) {
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