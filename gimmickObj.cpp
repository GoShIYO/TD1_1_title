#include "gimmickObj.h"
#include "obj.h"
#include <Novice.h>

const int BOX_COUNT = 3;

void InitGimmickObjs(GimmickObj gimmickObjs[]) {
	for (int i = 0; i < BOX_COUNT; i++) {
		gimmickObjs[i].obj.pos.x = (float)(300 + i * 200);
		gimmickObjs[i].obj.pos.y = 400.0f;
		gimmickObjs[i].obj.radius = 20.0f;
		gimmickObjs[i].isActive = true;
		gimmickObjs[i].moveDir = 1;
	}
}

void UpdateGimmickObjs(GimmickObj gimmickObjs[], Obj& player) {
	for (int i = 0; i < BOX_COUNT; i++) {
		if (gimmickObjs[i].isActive) {

			gimmickObjs[i].obj.pos.y += 2.0f * gimmickObjs[i].moveDir;
			if (gimmickObjs[i].obj.pos.y >= 450.0f || gimmickObjs[i].obj.pos.y <= 350.0f) {
				gimmickObjs[i].moveDir *= -1;
			}

			Vector2 collisionNormal = { 0.0f, 0.0f };
			if (CheckGimmickCollision(gimmickObjs[i], player, collisionNormal)) {
				ReflectPlayer(player, collisionNormal);
			}
		}
	}
}

void RenderGimmickObjs(GimmickObj gimmickObjs[], Vector2* scroll) {
	for (int i = 0; i < BOX_COUNT; i++) {
		if (gimmickObjs[i].isActive) {
			Novice::DrawBox(
				(int)(gimmickObjs[i].obj.pos.x - scroll->x),
				(int)(gimmickObjs[i].obj.pos.y - scroll->y),
				40, 100, 0, 0xFFFF00FF, kFillModeSolid
			);
		}
	}
}

float Max(float a, float b) {
	return (a > b) ? a : b;
}

float Min(float a, float b) {
	return (a < b) ? a : b;
}

bool CheckGimmickCollision(GimmickObj& gimmick, Obj& player, Vector2& collisionNormal) {

	float halfBoxWidth = 20.0f;
	float halfBoxHeight = 50.0f;

	float closestX = Max(gimmick.obj.pos.x - halfBoxWidth, Min(player.pos.x, gimmick.obj.pos.x + halfBoxWidth));
	float closestY = Max(gimmick.obj.pos.y - halfBoxHeight, Min(player.pos.y, gimmick.obj.pos.y + halfBoxHeight));

	float distanceX = player.pos.x - closestX;
	float distanceY = player.pos.y - closestY;
	float distanceSquared = distanceX * distanceX + distanceY * distanceY;

	if (distanceSquared < (player.radius * player.radius)) {

		if (closestX == gimmick.obj.pos.x - halfBoxWidth) {

			collisionNormal = { -1.0f, 0.0f };
		}
		else if (closestX == gimmick.obj.pos.x + halfBoxWidth) {

			collisionNormal = { 1.0f, 0.0f };
		}
		else if (closestY == gimmick.obj.pos.y - halfBoxHeight) {

			collisionNormal = { 0.0f, -1.0f };
		}
		else if (closestY == gimmick.obj.pos.y + halfBoxHeight) {

			collisionNormal = { 0.0f, 1.0f };
		}

		return true;
	}

	return false;
}



void NormalizeVector(Vector2& vector) {
	float length = sqrtf(vector.x * vector.x + vector.y * vector.y);
	if (length != 0) {
		vector.x /= length;
		vector.y /= length;
	}
}

void ReflectPlayer(Obj& player, Vector2& normal) {
	if (!player.isRotate) {

		Vector2 velocity = { cosf(player.angle) * player.velocity.x, sinf(player.angle) * player.velocity.y };

		NormalizeVector(normal);

		float dotProduct = velocity.x * normal.x + velocity.y * normal.y;

		velocity.x -= 2 * dotProduct * normal.x;
		velocity.y -= 2 * dotProduct * normal.y;

		player.angle = atan2f(velocity.y, velocity.x);
		player.pos.x += velocity.x;
		player.pos.y += velocity.y;
	}
}
