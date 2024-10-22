#define _USE_MATH_DEFINES
#define ANIM_COUNT 240
#include "enemy.h"
#include <math.h>
#include <Novice.h>
#include <stdlib.h>

#define BOSS_STAND_TIME 180   // 待機时间(frame)
#define BOSS_MOVE_TIME 120    // 移動时间(frame)
#define BOSS_ATTACK_TIME 150  // 攻撃时间(frame)
#define BOSS_SPEED 3.0f       // 移動速度
#define BOSS_ATTACK_INTERVAL 60 // 攻撃cooldown

int remainingKeys = keyCount;
float move = 0.0f;
float moveSpeed = 0.2f;

void InitEnemyNormal(Enemy enemy[]) {
	enemy[0].pos = { 0.0f, -120.0f };
	enemy[1].pos = { 240.0f, -220.0f };
	enemy[2].pos = { 480.0f, -120.0f };
	enemy[3].pos = { 720.0f, -220.0f };
	enemy[4].pos = { 960.0f, -120.0f };
	enemy[5].pos = { 1200.0f, -220.0f };

	enemy[6].pos = { 1520.0f, 0.0f };
	enemy[7].pos = { 1320.0f, 240.0f };
	enemy[8].pos = { 1520.0f, 480.0f };
	enemy[9].pos = { 1320.0f, 720.0f };

	enemy[10].pos = { 0.0f, 1040.0f };
	enemy[11].pos = { 240.0f, 840.0f };
	enemy[12].pos = { 480.0f, 1040.0f };
	enemy[13].pos = { 720.0f, 840.0f };
	enemy[14].pos = { 960.0f, 1040.0f };
	enemy[15].pos = { 1200.0f, 840.0f };

	enemy[16].pos = { -320.0f, 0.0f };
	enemy[17].pos = { -120.0f, 240.0f };
	enemy[18].pos = { -320.0f, 480.0f };
	enemy[19].pos = { -120.0f, 720.0f };

	for (int i = 0; i < ENEMY_COUNT; i++) {
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
		enemy[i].score = 100;
		enemy[i].deadTimer = 60;
		enemy[i].deathAnimationCount = 0;

	}
}

void InitEnemyHorming(Enemy enemy[]) {
	enemy[0].pos = { 0.0f, -900.0f };
	enemy[1].pos = { 240.0f, -700.0f };
	enemy[2].pos = { 480.0f, -900.0f };
	enemy[3].pos = { 720.0f, -700.0f };
	enemy[4].pos = { 960.0f, -900.0f };
	enemy[5].pos = { 1200.0f, -700.0f };

	enemy[6].pos = { 2900.0f, 0.0f };
	enemy[7].pos = { 3100.0f, 240.0f };
	enemy[8].pos = { 2900.0f, 480.0f };
	enemy[9].pos = { 3100.0f, 720.0f };

	enemy[10].pos = { 0.0f, 1700.0f };
	enemy[11].pos = { 240.0f, 1400.0f };
	enemy[12].pos = { 480.0f, 1700.0f };
	enemy[13].pos = { 720.0f, 1400.0f };
	enemy[14].pos = { 960.0f, 1700.0f };
	enemy[15].pos = { 1200.0f, 1400.0f };

	enemy[16].pos = { -2000.0f, 0.0f };
	enemy[17].pos = { -1500.0f, 240.0f };
	enemy[18].pos = { -2000.0f, 480.0f };
	enemy[19].pos = { -1500.0f, 720.0f };

	for (int i = 0; i < ENEMY_COUNT; i++) {
		enemy[i].velocity.x = 2.0f;
		enemy[i].velocity.y = 2.0f;
		enemy[i].components.x = 0.0f;
		enemy[i].components.y = 0.0f;
		enemy[i].directions.x = 0.0f;
		enemy[i].directions.y = 0.0f;
		enemy[i].magnitude = 0.0f;
		enemy[i].width = 30.0f;
		enemy[i].height = 30.0f;
		enemy[i].radius = 16.0f;
		enemy[i].direction = 0;
		enemy[i].isAlive = true;
		enemy[i].isMove = false;
		enemy[i].health = 1;
		enemy[i].score = 200;
		enemy[i].deadTimer = 60;
		enemy[i].deathAnimationCount = 0;
	}
}

void InitEnemyShot(Enemy enemy[]) {
	enemy[0].pos = { -2350.0f, -900.0f };
	enemy[1].pos = { 2000.0f, 1700.0f };
	enemy[2].pos = { -1700.0f, -900.0f };
	enemy[3].pos = { -1650.0f, -500.0f };
	enemy[4].pos = { -1660.0f, 0.0f };

	enemy[5].pos = { 3700.0f, 1700.0f };
	enemy[6].pos = { 3500.0f, 1100.0f };
	enemy[7].pos = { 3300.0f, 1700.0f };
	enemy[8].pos = { 3100.0f, 1200.0f };
	enemy[9].pos = { 2800.0f, 1700.0f };

	enemy[10].pos = { 3700.0f, -900.0f };
	enemy[11].pos = { 3500.0f, -500.0f };
	enemy[12].pos = { 3300.0f, -700.0f };
	enemy[13].pos = { 3100.0f, -500.0f };
	enemy[14].pos = { 2900.0f, -700.0f };

	enemy[15].pos = { -2200.0f, 1700.0f };
	enemy[16].pos = { -2000.0f, 1200.0f };
	enemy[17].pos = { -1800.0f, 1700.0f };
	enemy[18].pos = { -1600.0f, 1200.0f };
	enemy[19].pos = { -1500.0f, 1700.0f };

	for (int i = 0; i < ENEMY_COUNT; i++) {
		enemy[i].width = 30.0f;
		enemy[i].height = 30.0f;
		enemy[i].radius = 16.0f;
		enemy[i].shotTimer = 0;
		enemy[i].isAlive = true;
		enemy[i].isActive = false;
		enemy[i].health = 1;
		enemy[i].score = 150;
		enemy[i].deadTimer = 60;
		enemy[i].deathAnimationCount = 0;

	}
}

void InitEnemyBullet(EnemyBullet bullet[]) {
	for (int i = 0; i < BULLET_COUNT; i++) {
		bullet[i].pos.x = -10000.0f;
		bullet[i].pos.y = -10000.0f;
		bullet[i].velocity.x = 5.0f;
		bullet[i].velocity.y = 5.0f;
		bullet[i].components.x = 0.0f;
		bullet[i].components.y = 0.0f;
		bullet[i].directions.x = 0.0f;
		bullet[i].directions.y = 0.0f;
		bullet[i].magnitude = 0.0f;
		bullet[i].width = 25.0f;
		bullet[i].height = 25.0f;
		bullet[i].imageWidth = 300.0f;
		bullet[i].imageHeight = 25.0f;
		bullet[i].radius = 12.5f;
		bullet[i].moveX = 0;
		bullet[i].animTimer = 0;
		bullet[i].isActive = false;
	}
}

void InitBossKeys(BossKeys keys[], Enemy enemy[]) {
	keys[0].pos.x = enemy[0].pos.x + enemy[0].radius;
	keys[0].pos.y = enemy[0].pos.y + enemy[0].radius;
	keys[1].pos.x = enemy[5].pos.x + enemy[0].radius;
	keys[1].pos.y = enemy[5].pos.y + enemy[0].radius;
	keys[2].pos.x = enemy[10].pos.x + enemy[0].radius;
	keys[2].pos.y = enemy[10].pos.y + enemy[0].radius;
	keys[3].pos.x = enemy[15].pos.x + enemy[0].radius;
	keys[3].pos.y = enemy[15].pos.y + enemy[0].radius;
	for (int i = 0; i < keyCount; i++) {
		keys[i].width = 18.0f;
		keys[i].height = 38.0f;
		keys[i].radius = 8.0f;
		keys[i].isHit = false;
		keys[i].isPosSet = false;
	}
}

void InitBoss(Enemy& boss) {
	boss.pos = { 675, 0 };
	boss.velocity.x = 2.0f;
	boss.velocity.y = 1.0f;
	boss.width = 130.0f;
	boss.height = 130.0f;
	boss.radius = 75.0f;
	boss.moveTimer = 0;
	boss.direction = 0;
	boss.colTimer = 0;
	boss.isAlive = true;
	boss.isMove = false;
	boss.isHit = false;
	boss.isCol = false;
	boss.health = 1;
	boss.state = STAND;
	boss.score = 1000;
	boss.deadTimer = 300;
	boss.deathAnimationCount = 0;
	boss.color = WHITE;
	boss.stateTimer = 0;
}

void InitBossBullet(Enemy& boss, EnemyBullet& bullet) {
	boss.isActive = false;
	bullet.isActive = false;
	bullet.pos.x = 0.0f;
	bullet.pos.y = 0.0f;
	bullet.velocity.x = 5.0f;
	bullet.velocity.y = 5.0f;
	bullet.components.x = 0.0f;
	bullet.components.y = 0.0f;
	bullet.magnitude = 0.0f;
	bullet.directions.x = 0.0f;
	bullet.directions.y = 0.0f;
	bullet.moveX = 0;
	bullet.animTimer = 0;
}

void EnemyMove(Enemy enemy[]) {
	for (int i = 0; i < ENEMY_COUNT; i++) {
		if (enemy[i].isAlive) {
			enemy[i].moveTimer++;

			if (enemy[i].moveTimer == MOVE_TIME) {
				enemy[i].isMove = true;
				enemy[i].direction = rand() % 4;
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
}

void BossMove(Enemy& boss) {
	static int bossMoveTimer = 0;
	bossMoveTimer++;
	boss.pos.x += boss.velocity.x * sinf(bossMoveTimer * 0.05f);
	boss.pos.y += boss.velocity.y * cosf(bossMoveTimer * 0.01f);
	if (boss.health <= 0)return;
}

void BossShot(Enemy& boss, EnemyBullet& bullet, Obj& player) {
	boss.shotTimer++;
	if (boss.shotTimer >= 120 && !boss.isActive) {
		bullet.pos.x = boss.pos.x;
		bullet.pos.y = boss.pos.y;
		bullet.components.x = player.pos.x - bullet.pos.x + bullet.radius;
		bullet.components.y = player.pos.y - bullet.pos.y + bullet.radius;
		bullet.magnitude = (float)sqrt(pow(bullet.components.x, 2) + pow(bullet.components.y, 2));
		bullet.directions.x = bullet.components.x / bullet.magnitude;
		bullet.directions.y = bullet.components.y / bullet.magnitude;
		boss.isActive = true;
	}
	if (boss.isActive) {
		bullet.pos.x += bullet.directions.x * bullet.velocity.x;
		bullet.pos.y += bullet.directions.y * bullet.velocity.y;
	}
	if (boss.shotTimer >= 360) {
		boss.shotTimer = 0;
		boss.isActive = false;
	}

	bullet.animTimer++;
	if (bullet.animTimer >= ANIM_COUNT) {
		bullet.animTimer = 0;
		bullet.moveX = 0;
	}
	if (bullet.animTimer % 20 == 0) {
		bullet.moveX += 25;
	}
	Novice::ScreenPrintf(0, 0, "bullet.pos.x : %f", bullet.pos.x);
	Novice::ScreenPrintf(0, 20, "bullet.pos.y : %f", bullet.pos.y);
	Novice::ScreenPrintf(0, 40, "bullet.moveX : %d", bullet.moveX);
	Novice::ScreenPrintf(0, 60, "boss.pos.x : %f", boss.pos.x);
}

void BossUpdate(Enemy& boss, Scene& scene, EnemyBullet& bullet, Obj& player, Sound& sound) {
	if (boss.isHit && !boss.isCol) {
		boss.health--;
		boss.isHit = false;
		boss.isCol = true;
	}

	if (boss.isCol) {
		boss.colTimer++;
	}
	if (boss.colTimer >= 120) {
		boss.isCol = false;
		boss.colTimer = 0;
	}

	if (boss.health <= 0) {
		if (boss.deadTimer > 0) {
			boss.deadTimer--;
		}
		if (!Novice::IsPlayingAudio(sound.explosion.play)) {
			sound.explosion.play = Novice::PlayAudio(sound.explosion.audio, 1, 1.0f);
		}
	}
	if (boss.deadTimer <= 0) {
		Novice::StopAudio(sound.explosion.play);
		boss.isAlive = false;
		scene = CLEAR;
	}
	BossMove(boss);
	BossShot(boss, bullet, player);
	switch (boss.state)
	{
	case STAND:

		break;

	case MOVE:



		break;
	case TACKLE:



		break;
	}
}

void RenderBossBullet(EnemyBullet& bullet, int handle, Vector2& scroll) {
	Novice::DrawSpriteRect(int(bullet.pos.x - scroll.x), int(bullet.pos.y - scroll.y), bullet.moveX, 0, 25, 25, handle, 1/12, 1, 0.0f, WHITE);
}

void EnemyMoveHorming(Enemy enemy[], Obj& player) {
	for (int i = 0; i < ENEMY_COUNT; i++) {
		if (enemy[i].isAlive) {

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
}

void BulletShot(Enemy enemy[], Obj player, EnemyBullet bullet[]) {
	for (int i = 0; i < ENEMY_COUNT; i++) {
		float distanceX = player.pos.x - enemy[i].pos.x + enemy[i].radius;
		float distanceY = player.pos.y - enemy[i].pos.y + enemy[i].radius;
		float distance = sqrtf(static_cast<float>(pow(distanceX, 2) + static_cast<float>(pow(distanceY, 2))));

		if (!enemy[i].isActive && enemy[i].isAlive && distance <= BULLET_ACTIVE_RANGE) {
			enemy[i].shotTimer++;
			if (enemy[i].shotTimer >= SHOT_TIME) {
				enemy[i].isActive = true;
			}
		}
		for (int j = 0; j < BULLET_COUNT; j++) {
			if (!bullet[j].isActive && enemy[i].isActive) {
				bullet[j].pos.x = enemy[i].pos.x;
				bullet[j].pos.y = enemy[i].pos.y;
				bullet[j].isActive = true;
				bullet[j].components.x = player.pos.x - bullet[j].pos.x;
				bullet[j].components.y = player.pos.y - bullet[j].pos.y;
				bullet[j].magnitude = (float)sqrt(pow(bullet[j].components.x, 2) + pow(bullet[j].components.y, 2));
				bullet[j].directions.x = bullet[j].components.x / bullet[j].magnitude;
				bullet[j].directions.y = bullet[j].components.y / bullet[j].magnitude;
				bullet[j].isActive = true;
				enemy[i].isActive = false;
				enemy[i].shotTimer = 0;
				break;
			}
		}
	}

	for (int j = 0; j < BULLET_COUNT; j++) {
		if (bullet[j].isActive) {
			bullet[j].pos.x += bullet[j].directions.x * bullet[j].velocity.x;
			bullet[j].pos.y += bullet[j].directions.y * bullet[j].velocity.y;
		}
		if (bullet[j].pos.x >= kWindowWidth * 3 || bullet[j].pos.x <= -kWindowWidth * 2 || bullet[j].pos.y >= kWindowHeight * 3 || bullet[j].pos.y <= -kWindowHeight * 2) {
			bullet[j].pos.x = -10000.0f;
			bullet[j].pos.y = -10000.0f;
			bullet[j].isActive = false;
		}
	}
}

void RenderEnemy(Enemy enemy[], Vector2& scroll, int handle, float px, float py, int deathHandle) {
	for (int i = 0; i < ENEMY_COUNT; i++) {
		float distanceX = enemy[i].pos.x - px;
		float distanceY = enemy[i].pos.y - py;
		float distanceSquared = distanceX * distanceX + distanceY * distanceY;
		float maxDistanceSquared = float(kWindowWidth * kWindowWidth);

		if (distanceSquared <= maxDistanceSquared) {
			if (enemy[i].isAlive) {
				Novice::DrawSprite(int(enemy[i].pos.x - scroll.x), int(enemy[i].pos.y - scroll.y), handle, 1, 1, 0.0f, WHITE);
			}
			else if (!enemy[i].isAlive && enemy[i].deadTimer > 0) {
				enemy[i].deadTimer--;

				if (enemy[i].deadTimer % 5 == 0) {
					enemy[i].deathAnimationCount++;
				}

				const int maxFrames = 12;
				if (enemy[i].deathAnimationCount >= maxFrames) {
					enemy[i].deathAnimationCount = maxFrames - 1;
				}

				Novice::DrawSpriteRect(
					int(enemy[i].pos.x - scroll.x), int(enemy[i].pos.y - scroll.y),
					enemy[i].deathAnimationCount * 50, 0,
					50, 50,
					deathHandle, 1 / 12.0f, 1, 0, WHITE);
			}
		}
	}
}


void RenderBullet(EnemyBullet bullet[], Vector2 scroll, int handle) {
	for (int i = 0; i < BULLET_COUNT; i++) {
		Novice::DrawSpriteRect(int(bullet[i].pos.x - scroll.x), int(bullet[i].pos.y - scroll.y), bullet[i].moveX, 0,
			(int)bullet[i].width, (int)bullet[i].height, handle, (bullet[i].imageHeight / bullet[i].imageWidth), 1, 0.0f, 0xFFFFFFFF);
	}
}

void RenderBoss(Enemy& boss, Vector2 scroll, int handle, int handle2, int handle3) {
	static int randX = 0;
	static int randY = 0;
	static int timer = 0;
	if (boss.isAlive) {
		Novice::DrawSprite(int(boss.pos.x - scroll.x), int(boss.pos.y - scroll.y), handle, 1, 1, 0.0f, WHITE);
		Novice::DrawSprite(int(boss.pos.x - scroll.x), int(boss.pos.y - scroll.y), handle2, 1, 1, 0.0f, WHITE);
	}
	if (boss.health <= 0) {
		if (boss.deadTimer % 5 == 0) {
			timer++;

		}
		if (timer > 12) {
			timer = 0;
			randX = rand() % 50 - 20;
			randY = rand() % 50 - 20;
		}
		Novice::DrawSpriteRect(
			int(boss.pos.x + boss.radius + randX - scroll.x),
			int(boss.pos.y + boss.radius + randY - scroll.y),
			timer * 50, 0, 50, 50,
			handle3, 1 / 12.0f, 1, 0.0f, WHITE);

	}
}

void BulletAnim(EnemyBullet bullet[]) {
	for (int i = 0; i < BULLET_COUNT; i++) {
		if (bullet[i].isActive) {
			bullet[i].animTimer++;
			if (bullet[i].animTimer >= ANIM_COUNT) {
				bullet[i].animTimer = 0;
				bullet[i].moveX = 0;
			}
			if (bullet[i].animTimer % 20 == 0) {
				bullet[i].moveX += static_cast<int>(bullet[i].width);
			}
		}
	}
}

bool CheckCircleCollision(Vector2& a, Vector2& b, const float& radiusA, const float& radiusB) {
	float x = a.x + radiusA - b.x;
	float y = a.y + radiusA - b.y;
	float distance = x * x + y * y;
	float radius = radiusA + radiusB;
	if (distance <= radius * radius) {
		return true;
	}
	return false;
}
void UpdatePlayerEnemyEvent(Enemy enemy[], Obj& player, Sound& sound, Enemy& boss) {
	const float r = 50.0f;
	for (int i = 0; i < ENEMY_COUNT; i++) {
		if (enemy[i].isAlive) {
			if (CheckCircleCollision(enemy[i].pos, player.pos, enemy[i].radius + r, player.radius)) {

				if (CheckCircleCollision(enemy[i].pos, player.pos, enemy[i].radius, player.radius) && !player.isCollied) {
					player.isCollied = true;
					player.health--;
					if (!Novice::IsPlayingAudio(sound.collision_enemy.play)) {
						sound.collision_enemy.play = Novice::PlayAudio(sound.collision_enemy.audio, 0, 0.7f);
					}
				}
				if (player.attack) {
					if (!player.isRotate) {
						float dx = player.pos.x - enemy[i].pos.x;
						float dy = player.pos.y - enemy[i].pos.y;
						float angle = atan2f(dy, dx);
						player.angle += angle;
					}
					if (!Novice::IsPlayingAudio(sound.explosion.play)) {
						sound.explosion.play = Novice::PlayAudio(sound.explosion.audio, 0, 1.5f);
					}
					enemy[i].health--;
					player.score += enemy[i].score;

				}
			}
		}

		if (enemy[i].health <= 0) {
			enemy[i].isAlive = false;
		}

		//Novice::ScreenPrintf(0, 60, "player.health : %d", player.health);
		//Novice::ScreenPrintf(0, 80, "enemy.health : %d", enemy[i].health);
		//Novice::ScreenPrintf(0, 100, "enemy.isAlive : %s", enemy[i].isAlive ? "alive" : "death");
	}

	if (boss.isAlive) {

		if (CheckCircleCollision(boss.pos, player.pos, boss.radius, player.radius) && !player.isCollied) {
			float dx = player.pos.x - boss.pos.x;
			float dy = player.pos.y - boss.pos.y;
			float angle = atan2f(dy, dx);
			player.angle += angle;
			
			if (!Novice::IsPlayingAudio(sound.collision_enemy.play)) {
				sound.collision_enemy.play = Novice::PlayAudio(sound.collision_enemy.audio, 0, 0.7f);
			}
			if (player.attack) {

			boss.isHit = true;
			}
			else {
				player.isCollied = true;
				player.health--;
			}
		}		
	}
}

void UpdatePlayerBulletEvent(Obj& player, EnemyBullet bullet[]) {
	for (int i = 0; i < BULLET_COUNT; i++) {
		float distanceX = player.pos.x - bullet[i].pos.x + bullet[i].radius;
		float distanceY = player.pos.y - bullet[i].pos.y + bullet[i].radius;
		float distance = sqrtf(static_cast<float>(pow(distanceX, 2) + static_cast<float>(pow(distanceY, 2))));

		if (distance <= player.radius + bullet[i].radius) {
			if (!player.attack) {
				player.health--;
				player.isCollied = true;
			}
			bullet[i].pos.x = -10000.0f;
			bullet[i].pos.y = -10000.0f;
			bullet[i].isActive = false;
		}
	}
}

void RenderMiniMapEnemy(Enemy enemy[], Enemy enemy1[], Enemy enemy2[]) {

	for (int i = 0; i < ENEMY_COUNT; i++) {
		if (enemy[i].isAlive) {
			Novice::DrawEllipse(
				int(enemy[i].pos.x / 20 + kWindowWidth * 5 / 6.0f), int(enemy[i].pos.y / 20 + kWindowHeight / 8.0f),
				int(enemy[i].radius / 8), int(enemy[i].radius / 8),
				0.0f, 0xFFFF55FF, kFillModeSolid);
		}
		if (enemy1[i].isAlive) {
			Novice::DrawEllipse(
				int(enemy1[i].pos.x / 20 + kWindowWidth * 5 / 6.0f), int(enemy1[i].pos.y / 20 + kWindowHeight / 8.0f),
				int(enemy1[i].radius / 8), int(enemy1[i].radius / 8),
				0.0f, 0x5555FFFF, kFillModeSolid);
		}
		if (enemy2[i].isAlive) {
			Novice::DrawEllipse(
				int(enemy2[i].pos.x / 20 + kWindowWidth * 5 / 6.0f), int(enemy2[i].pos.y / 20 + kWindowHeight / 8.0f),
				int(enemy2[i].radius / 8), int(enemy2[i].radius / 8),
				0.0f, 0x55FF55FF, kFillModeSolid);
		}
	}
}

void EnemyRange(Enemy enemy[], Enemy enemy1[]) {
	for (int i = 0; i < ENEMY_COUNT; i++) {
		if (enemy[i].pos.x >= kWindowWidth * 3 - enemy[i].radius - 100.0f) {
			enemy[i].pos.x = kWindowWidth * 3 - enemy[i].radius - 100.0f;
		}
		if (enemy1[i].pos.x >= kWindowWidth * 3 - enemy1[i].radius - 100.0f) {
			enemy1[i].pos.x = kWindowWidth * 3 - enemy1[i].radius - 100.0f;
		}
		if (enemy[i].pos.x <= -kWindowWidth * 2 + enemy[i].radius + 100.0f) {
			enemy[i].pos.x = -kWindowWidth * 2 + enemy[i].radius + 100.0f;
		}
		if (enemy1[i].pos.x <= -kWindowWidth * 2 + enemy1[i].radius + 100.0f) {
			enemy1[i].pos.x = -kWindowWidth * 2 + enemy1[i].radius + 100.0f;
		}
		if (enemy[i].pos.y >= kWindowHeight * 3 - enemy[i].radius - 100.0f) {
			enemy[i].pos.y = kWindowHeight * 3 - enemy[i].radius - 100.0f;
		}
		if (enemy1[i].pos.y >= kWindowHeight * 3 - enemy1[i].radius - 100.0f) {
			enemy1[i].pos.y = kWindowHeight * 3 - enemy1[i].radius - 100.0f;
		}
		if (enemy[i].pos.y <= -kWindowHeight * 2 + enemy[i].radius + 100.0f) {
			enemy[i].pos.y = -kWindowHeight * 2 + enemy[i].radius + 100.0f;
		}
		if (enemy1[i].pos.y <= -kWindowHeight * 2 + enemy1[i].radius + 100.0f) {
			enemy1[i].pos.y = -kWindowHeight * 2 + enemy1[i].radius + 100.0f;
		}
	}
}

//void UpdateKeys(BossKeys keys[], Enemy enemy[]) {
//
//}

void UpdatePlayerKeyEvent(BossKeys keys[], Sound& sound, Enemy enemy[], Enemy& boss, Obj& player) {
	if (!enemy[0].isAlive && !keys[0].isHit) {
		keys[0].isHit = true;
		keys[0].pos.x = -10000.0f;
		keys[0].pos.y = -10000.0f;
		remainingKeys--;
		player.health++;
		player.isCollied = true;
		if (!Novice::IsPlayingAudio(sound.key.play)) {
			sound.key.play = Novice::PlayAudio(sound.key.audio, 0, 0.2f);
		}
	}

	if (!enemy[5].isAlive && !keys[1].isHit) {
		keys[1].isHit = true;
		keys[1].pos.x = -10000.0f;
		keys[1].pos.y = -10000.0f;
		remainingKeys--;
		player.health++;
		player.isCollied = true;

		if (!Novice::IsPlayingAudio(sound.key.play)) {
			sound.key.play = Novice::PlayAudio(sound.key.audio, 0, 0.2f);
		}
	}

	if (!enemy[10].isAlive && !keys[2].isHit) {
		keys[2].isHit = true;
		keys[2].pos.x = -10000.0f;
		keys[2].pos.y = -10000.0f;
		remainingKeys--;
		player.health++;
		player.isCollied = true;

		if (!Novice::IsPlayingAudio(sound.key.play)) {
			sound.key.play = Novice::PlayAudio(sound.key.audio, 0, 0.2f);
		}
	}

	if (!enemy[15].isAlive && !keys[3].isHit) {
		keys[3].isHit = true;
		keys[3].pos.x = -10000.0f;
		keys[3].pos.y = -10000.0f;
		remainingKeys--;
		player.health++;
		player.isCollied = true;

		if (!Novice::IsPlayingAudio(sound.key.play)) {
			sound.key.play = Novice::PlayAudio(sound.key.audio, 0, 0.2f);
		}
	}
	if (remainingKeys == 0 && boss.health >= 1) {
		boss.isAlive = true;
	}
}

void RenderKeys(BossKeys keys[], Vector2 scroll, int& handle) {
	move += moveSpeed;
	if (move >= 2.0f || move <= -2.0f) {
		moveSpeed *= -1;
	}
	for (int i = 0; i < keyCount; i++) {
		if (!keys[i].isHit) {
			Novice::DrawSprite(int(keys[i].pos.x - scroll.x), int(keys[i].pos.y - scroll.y + move), handle, 1, 1, 0.0f, WHITE);
		}
	}
}

void LoadImages(Handle& handle) {
	handle.enemy = Novice::LoadTexture("./Resources/Enemy/EnemyStopBoom32.png");
	handle.enemyHorming = Novice::LoadTexture("./Resources/Enemy/enemyFollow30.png");
	handle.enemyShot = Novice::LoadTexture("./Resources/Enemy/enemyShot30.png");
	handle.bullet = Novice::LoadTexture("./Resources/Enemy/enemyBullet.png");
	handle.deathEffect = Novice::LoadTexture("./Resources/Effect/enemyExplosion50.png");
	handle.boss = Novice::LoadTexture("./Resources/Enemy/boss130_B.png");
	handle.bossEye = Novice::LoadTexture("./Resources/Enemy/boss34_F.png");
}

