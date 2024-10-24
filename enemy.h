﻿#pragma once
#define MOVE_TIME 60
#define STOP_TIME 120
#define SHOT_TIME 240
#define BULLET_COUNT 100
#define BULLET_ACTIVE_RANGE 500.0f
#define ENEMY_TO_PLAYER 500.0f
#define ENEMY_COUNT 20
#include <Vector2.h>
#include "obj.h"
#include"sound.h"

extern float move;
extern float moveSpeed;

enum EnemyDirection {
	UP = 0,
	DOWN = 1,
	RIGHT = 2,
	LEFT = 3
};

enum EnemyState {
	STAND = 0,
	MOVE = 1,
	TACKLE = 2
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
	int state;
	int score;
	int colTimer;
	bool isAlive;
	bool isMove;
	bool isActive;
	bool isHit;
	bool isCol;
	int deadTimer;
	int deathAnimationCount;
	int color;
	int stateTimer;
};

struct EnemyBullet {
	Vector2 pos;
	Vector2 velocity;
	Vector2 components;
	Vector2 directions;
	float magnitude;
	float width;
	float height;
	float imageWidth;
	float imageHeight;
	float radius;
	int graphHnadle;
	int moveX;
	int animTimer;
	bool isActive;
};

struct Handle {
	int enemy;
	int enemyHorming;
	int enemyShot;
	int bullet;
	int deathEffect;
	int boss;
	int bossEye;
};

void InitEnemyNormal(Enemy enemy[]);
void InitEnemyHorming(Enemy enemy[]);
void InitEnemyShot(Enemy enemy[]);
void InitEnemyBullet(EnemyBullet bullet[]);
void InitBossKeys(BossKeys keys[], Enemy enemy[]);
void InitBoss(Enemy& boss);

void InitBossBullet(EnemyBullet& bullet);

void RenderBossBullet(EnemyBullet& bullet, int handle, Vector2& scroll);

void LoadImages(Handle& handle);

void EnemyMove(Enemy enemy[]);
void BossShot(Enemy& boss, EnemyBullet& bullet, Obj& player);
void BossUpdate(Enemy& boss, Scene& scene, EnemyBullet& bullet, Obj& player, Sound& sound);
void EnemyMoveHorming(Enemy enemy[], Obj& player);
void BulletShot(Enemy enemy[], Obj player, EnemyBullet bullet[]);

//void UpdateKeys(BossKeys keys[], Enemy enemy[]);
void UpdatePlayerKeyEvent(BossKeys keys[],Sound& sound, Enemy enemy[], Enemy& boss,Obj& player, int& remainingKeys);
void RenderKeys(BossKeys keys[], Vector2 scroll, int& handle);

void EnemyRange(Enemy enemy[], Enemy enemy1[]);

void RenderEnemy(Enemy enemy[], Vector2& scroll, int handle, float px, float py,int deathHandle);
void RenderBullet(EnemyBullet bullet[], Vector2 scroll, int handle);

void RenderBoss(Enemy& boss, Vector2 scroll, int handle, int handle2, int handle3);

void BulletAnim(EnemyBullet bullet[]);

void EnemyDebug(EnemyBullet bullet[]);
void RenderMiniMapEnemy(Enemy enemy[], Enemy enemy1[], Enemy enemy2[], Enemy& boss, BossKeys keys[], int handle1, int handle2);

void UpdatePlayerEnemyEvent(Enemy enemy[], Obj& player,Sound& sound, Enemy& boss);

void UpdatePlayerBulletEvent(Obj& player, EnemyBullet bullet[]);
