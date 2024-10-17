#pragma once
#define MOVE_TIME 60
#define STOP_TIME 120
#define SHOT_TIME 60
#define BULLET_COUNT 20
#define ENEMY_TO_PLAYER 500.0f
#define ENEMY_COUNT 20
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
	float radius;
	int moveTimer;
	int shotTimer;
	int graphHandle;
	int direction;
	int health;
	bool isAlive;
	bool isMove;
};

struct EnemyBullet {
	Vector2 pos;
	Vector2 velocity;
	Vector2 components;
	Vector2 directions;
	float magnitude;
	float width;
	float height;
	int graphHnadle;
	bool isShot;
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

void RenderEnemy(Enemy enemy[], Vector2 scroll, int handle, float px, float py);
void RenderBullet(EnemyBullet bullet[], Vector2 scroll, int handle);

void EnemyDebug(EnemyBullet bullet[]);
void RenderMiniMapEnemy(Enemy enemy[], Enemy enemy1[], Enemy enemy2[]);

void UpdatePlayerEnemyEvent(Enemy enemy[], Obj& player, char keys[], char preKeys[]);