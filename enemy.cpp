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
	enemy.radius = 16.0f;
	enemy.moveTimer = 0;
	enemy.direction = 0;
	enemy.isAlive = true;
	enemy.isMove = false;
	enemy.health = 1;
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

void RenderEnemy(Enemy enemy, Vector2 scroll, int handle) {
	if (enemy.isAlive) {
		Novice::DrawSprite(int(enemy.pos.x - scroll.x), int(enemy.pos.y - scroll.y), handle, 1, 1, 0.0f, WHITE);
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
void UpdatePlayerEnemyEvent(Enemy& enemy, Obj& player,char keys[],char preKeys[]) {
	 const float r = 50.0f;
	 if (enemy.isAlive) {
		 if (CheckCircleCollision(enemy.pos, player.pos, enemy.radius + r, player.radius)) {

			 if (CheckCircleCollision(enemy.pos, player.pos, enemy.radius, player.radius) && !player.isCollied) {
				 player.isCollied = true;
				 player.health--;				
			 }
			 if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				 if (!player.isRotate) {
					 float dx = player.pos.x - enemy.pos.x;
					 float dy = player.pos.y - enemy.pos.y;
					 float angle = atan2f(dy, dx);
					 player.angle += angle;
				 }
				 enemy.health--;
			 }
		 }
	 }	
	 if (enemy.health <= 0) {
		 enemy.isAlive = false;
	 }
	 Novice::ScreenPrintf(0, 60, "player.health : %d", player.health);
	 Novice::ScreenPrintf(0, 80, "enemy.health : %d", enemy.health);
	 Novice::ScreenPrintf(0, 100, "enemy.isAlive : %s", enemy.isAlive ? "alive" : "death");

}

void LoadImages(Handle& handle) {
	handle.enemy = Novice::LoadTexture("./Resources/enemy.png");
	handle.enemyHorming = Novice::LoadTexture("./Resources/enemy2.png");
	handle.enemyShot = Novice::LoadTexture("./Resources/enemy2.png");
	handle.bullet = Novice::LoadTexture("./Resources/bullet.png");
	handle.deathEffect = Novice::LoadTexture("./Resources/effect.png");
}