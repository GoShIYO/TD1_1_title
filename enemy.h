#pragma once
#define MOVE_TIME 60
#define STOP_TIME 120
#define SHOT_TIME 180
#define BULLET_COUNT 100
#define BULLET_ACTIVE_RANGE 500.0f
#define ENEMY_TO_PLAYER 500.0f
#define ENEMY_COUNT 20
#include <Vector2.h>
#include "obj.h"
#include"sound.h"

extern int remainingKeys;

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
	float radius;
	int moveTimer;
	int shotTimer;
	int graphHandle;
	int direction;
	int health;
	bool isAlive;
	bool isMove;
	bool isActive;
};

struct EnemyBullet {
	Vector2 pos;
	Vector2 velocity;
	Vector2 components;
	Vector2 directions;
	float magnitude;
	float width;
	float height;
	float radius;
	int graphHnadle;
	bool isActive;
};

struct Handle {
	int enemy;
	int enemyHorming;
	int enemyShot;
	int bullet;
	int deathEffect;
};

void InitEnemyNormal(Enemy enemy[]);
void InitEnemyHorming(Enemy enemy[]);
void InitEnemyShot(Enemy enemy[]);
void InitEnemyBullet(EnemyBullet bullet[]);

void LoadImages(Handle& handle);

void EnemyMove(Enemy enemy[]);
void EnemyMoveHorming(Enemy enemy[], Obj& player);
void BulletShot(Enemy enemy[], Obj player, EnemyBullet bullet[]);

void UpdateKeys(BossKeys keys[], Enemy enemy[]);
void UpdatePlayerKeyEvent(Obj& player, BossKeys keys[]);
void RenderKeys(BossKeys keys[], Vector2 scroll);

void EnemyRange(Enemy enemy[], Enemy enemy1[]);

void RenderEnemy(Enemy enemy[], Vector2 scroll, int handle, float px, float py);
void RenderBullet(EnemyBullet bullet[], Vector2 scroll, int handle);

void EnemyDebug(EnemyBullet bullet[]);
void RenderMiniMapEnemy(Enemy enemy[], Enemy enemy1[], Enemy enemy2[]);

void UpdatePlayerEnemyEvent(Enemy enemy[], Obj& player,Sound& sound);

void UpdatePlayerBulletEvent(Obj& player, EnemyBullet bullet[]);
