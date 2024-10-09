#define _USE_MATH_DEFINES
#include "enemy.h"
#include <math.h>

void InitEnemy(Enemy* enemy) {
	enemy->pos.x = 0.0f;
	enemy->pos.y = 0.0f;
	enemy->velocity.x = 2.0f;
	enemy->velocity.y = 2.0f;
	enemy->angle = (float)(M_PI) / 8.0f;
	enemy->isAlive = true;
}