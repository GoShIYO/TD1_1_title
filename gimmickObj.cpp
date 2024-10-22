#include "gimmickObj.h"
#include "obj.h"
#include <Novice.h>

const int BOX_COUNT = 14;
int boxTexture;
int horizontalBoxTexture100_40;
int horizontalBoxTexture670_40;
int verticalBoxTexture40_740;
int verticalBoxTexture40_100;

void InitGimmickObjs(GimmickObj gimmickObjs[]) {
	horizontalBoxTexture100_40 = Novice::LoadTexture("./Resources/horizontalBox100x40.png");
	horizontalBoxTexture670_40 = Novice::LoadTexture("./Resources/horizontalBox670x40.png");
	verticalBoxTexture40_740 = Novice::LoadTexture("./Resources/verticalBox40x740.png");
	verticalBoxTexture40_100 = Novice::LoadTexture("./Resources/verticalBox40x100.png");

	gimmickObjs[0].obj.pos = { -1790.0f, -450.0f };
	gimmickObjs[0].obj.width = 100;
	gimmickObjs[0].obj.height = 40;

	gimmickObjs[1].obj.pos = { 100.0f, 1500.0f };
	gimmickObjs[1].obj.width = 40;
	gimmickObjs[1].obj.height = 100;

	gimmickObjs[2].obj.pos = { 2300.0f, -400.0f };
	gimmickObjs[2].obj.width = 100;
	gimmickObjs[2].obj.height = 40;

	gimmickObjs[3].obj.pos = { 2800.0f, 1400.0f };
	gimmickObjs[3].obj.width = 40;
	gimmickObjs[3].obj.height = 100;

	gimmickObjs[4].obj.pos = { 3640.0f, 1450.0f };
	gimmickObjs[4].obj.width = 100;
	gimmickObjs[4].obj.height = 40;

	gimmickObjs[5].obj.pos = { 3340.0f, 1960.0f };
	gimmickObjs[5].obj.width = 40;
	gimmickObjs[5].obj.height = 100;

	gimmickObjs[6].obj.pos = { 3100.0f, -750.0f };
	gimmickObjs[6].obj.width = 40;
	gimmickObjs[6].obj.height = 100;

	gimmickObjs[7].obj.pos = { -2460.0f, -500.0f };
	gimmickObjs[7].obj.width = 670;
	gimmickObjs[7].obj.height = 40;

	gimmickObjs[8].obj.pos = { -1390.0f, -1340.0f };
	gimmickObjs[8].obj.width = 40;
	gimmickObjs[8].obj.height = 740;

	gimmickObjs[9].obj.pos = { -2200.0f, -230.0f };
	gimmickObjs[9].obj.width = 40;
	gimmickObjs[9].obj.height = 100;

	gimmickObjs[10].obj.pos = { -850.0f, 650.0f };
	gimmickObjs[10].obj.width = 40;
	gimmickObjs[10].obj.height = 100;

	gimmickObjs[11].obj.pos = { 2600.0f, -1340.0f };
	gimmickObjs[11].obj.width = 40;
	gimmickObjs[11].obj.height = 740;

	gimmickObjs[12].obj.pos = { 2640.0f, -640.0f };
	gimmickObjs[12].obj.width = 100;
	gimmickObjs[12].obj.height = 40;

	gimmickObjs[13].obj.pos = { 2100.0f, 900.0f };
	gimmickObjs[13].obj.width = 100;
	gimmickObjs[13].obj.height = 40;

	for (int i = 0; i < BOX_COUNT; i++) {
		gimmickObjs[i].isActive = true;
		gimmickObjs[i].moveDir = 1;
	}
}

float Clamp(float value, float minValue, float maxValue) {
	if (value < minValue) return minValue;
	if (value > maxValue) return maxValue;
	return value;
}

void UpdateGimmickObjs(GimmickObj gimmickObjs[], Obj& player) {
	if (gimmickObjs[0].isActive) {
		gimmickObjs[0].obj.pos.x += 1.0f * gimmickObjs[0].moveDir;
		if (gimmickObjs[0].obj.pos.x >= -1290.0f || gimmickObjs[0].obj.pos.x <= -1790.0f) {
			gimmickObjs[0].moveDir *= -1;
		}
	}

	if (gimmickObjs[1].isActive) {

		gimmickObjs[1].obj.pos.y += 1.0f * gimmickObjs[1].moveDir;
		if (gimmickObjs[1].obj.pos.y >= 1900.0f || gimmickObjs[1].obj.pos.y <= 1500.0f) {
			gimmickObjs[1].moveDir *= -1;
		}
	}
	if (gimmickObjs[2].isActive) {

		gimmickObjs[2].obj.pos.x += 1.0f * gimmickObjs[2].moveDir;
		if (gimmickObjs[2].obj.pos.x >= 2700 || gimmickObjs[2].obj.pos.x <= 2300.0f) {
			gimmickObjs[2].moveDir *= -1;
		}
	}
	if (gimmickObjs[3].isActive) {

		gimmickObjs[3].obj.pos.y += 1.0f * gimmickObjs[3].moveDir;
		if (gimmickObjs[3].obj.pos.y >= 1900.0f || gimmickObjs[3].obj.pos.y <= 1400.0f) {
			gimmickObjs[3].moveDir *= -1;
		}
	}
	if (gimmickObjs[4].isActive) {

		gimmickObjs[4].obj.pos.x -= 1.0f * gimmickObjs[4].moveDir;
		if (gimmickObjs[4].obj.pos.x >= 3640.0f || gimmickObjs[4].obj.pos.x <= 2840.0f) {
			gimmickObjs[4].moveDir *= -1;
		}
	}
	if (gimmickObjs[5].isActive) {

		gimmickObjs[5].obj.pos.y -= 1.0f * gimmickObjs[5].moveDir;
		if (gimmickObjs[5].obj.pos.y >= 1960.0f || gimmickObjs[5].obj.pos.y <= 1700.0f) {
			gimmickObjs[5].moveDir *= -1;
		}
	}
	if (gimmickObjs[6].isActive) {

		gimmickObjs[6].obj.pos.y += 0.25f * gimmickObjs[6].moveDir;
		if (gimmickObjs[6].obj.pos.y >= -550.0f || gimmickObjs[6].obj.pos.y <= -750.0f) {
			gimmickObjs[6].moveDir *= -1;
		}
	}
	for (int i = 0; i < BOX_COUNT; i++) {
		if (gimmickObjs[i].isActive) {

			if (CheckGimmickCollision(gimmickObjs[i], player)) {

				Vector2 collisionNormal = { 0.0f, 0.0f };

				float left = gimmickObjs[i].obj.pos.x ;
				float right = gimmickObjs[i].obj.pos.x + gimmickObjs[i].obj.width ;
				float top = gimmickObjs[i].obj.pos.y ;
				float bottom = gimmickObjs[i].obj.pos.y + gimmickObjs[i].obj.height ;

				float closestX = Clamp(player.pos.x, left, right);
				float closestY = Clamp(player.pos.y, top, bottom);

				float dx = player.pos.x - closestX;
				float dy = player.pos.y - closestY;

				if (fabsf(dx) > fabsf(dy)) {

					collisionNormal = { dx > 0 ? 1.0f : -1.0f, 0.0f };
				}
				else {

					collisionNormal = { 0.0f, dy > 0 ? 1.0f : -1.0f };
				}

				ReflectPlayer(player, collisionNormal);
				break;
			}
		}
	}
}

bool CheckGimmickCollision(GimmickObj& gimmick, Obj& player) {

	float left = gimmick.obj.pos.x;
	float right = gimmick.obj.pos.x + gimmick.obj.width;
	float top = gimmick.obj.pos.y;
	float bottom = gimmick.obj.pos.y + gimmick.obj.height;

	float closestX = Clamp(player.pos.x, left, right);
	float closestY = Clamp(player.pos.y, top, bottom);

	float dx = player.pos.x - closestX;
	float dy = player.pos.y - closestY;

	return (dx * dx + dy * dy) < (player.radius * player.radius);
}

void NormalizeVector(Vector2& vector) {
	float length = sqrtf(vector.x * vector.x + vector.y * vector.y);
	if (length != 0) {
		vector.x /= length;
		vector.y /= length;
	}
}

void ReflectPlayer(Obj& player, Vector2& normal) {

	Vector2 velocity = {
		cosf(player.angle) * player.velocity.x,
		sinf(player.angle) * player.velocity.y
	};

	NormalizeVector(normal);

	float dotProduct = velocity.x * normal.x + velocity.y * normal.y;

	velocity.x -= 2 * dotProduct * normal.x;
	velocity.y -= 2 * dotProduct * normal.y;

	player.angle = atan2f(velocity.y, velocity.x);

	player.pos.x += normal.x * (player.radius + 1.0f);
	player.pos.y += normal.y * (player.radius + 1.0f);

	float newVelocityMagnitude = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);
	player.velocity.x = newVelocityMagnitude;
	player.velocity.y = newVelocityMagnitude;
}

void RenderGimmickObjs(GimmickObj gimmickObjs[], Vector2* scroll) {
	int textures[] = {
		horizontalBoxTexture100_40, horizontalBoxTexture670_40, verticalBoxTexture40_740, verticalBoxTexture40_100
	};
	for (int i = 0; i < BOX_COUNT; i++) {
		if (gimmickObjs[i].isActive) {
			int texture = textures[0];
			switch (i) {
			case 0:
			case 2:
			case 4:
			case 12:
			case 13:
				texture = horizontalBoxTexture100_40; break;
			case 7:
				texture = horizontalBoxTexture670_40; break;
			case 8:
			case 11:
				texture = verticalBoxTexture40_740; break;
			default:
				texture = verticalBoxTexture40_100; break;
			}

			Novice::DrawSprite(
				(int)(gimmickObjs[i].obj.pos.x - scroll->x),
				(int)(gimmickObjs[i].obj.pos.y - scroll->y),
				texture, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF
			);
		}
	}
}

