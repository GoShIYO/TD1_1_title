﻿#include<Novice.h>
#include"obj.h"


/////////////////////////////////////////////////////////////////Normalization/////////////////////////////////////////////////////////////
void InitPlayer(Obj* player) {
	player->pos.x = 200.0f;
	player->pos.y = 100.0f;
	player->velocity.x = 2.0f;
	player->velocity.y = 2.0f;
	player->angle = (float)(M_PI) / 8.0f;
	player->radius = 30.0f;
}
void InitObj(Obj obj[]) {
	for (int i = 0; i < 3; i++) {
		obj[i].radius = 60.0f;
		obj[i].isRotate = false;
	}
	obj[0].pos = { 200.0f,200.0f };
	obj[1].pos = { 550.0f,530.0f };
	obj[2].pos = { 890.0f,450.0f };
}

void InitSystem(System* system) {
	system->digFlat = 0;
}

////////////////////////////////////////////////////////////////////Order//////////////////////////////////////////////////////////////////

void viewDig(int* digFlat, int key1, int preKey1, int key2, int preKey2, int key3, int preKey3) {
	enum {
		Switch = 1,
		Page = 2
	};

	if (key1 && !preKey1) {
		*digFlat = *digFlat ^ Switch;
	}
	if (key2 && !preKey2) {
		*digFlat = *digFlat - Page;
	}
	if (key3 && !preKey3) {
		*digFlat = *digFlat + Page;
	}

	if (*digFlat & Switch) {
		int sx = 800; int sy = 100;
		Novice::DrawBox(sx, sy, 300, 5 + 20 * 10, 0, 0x00000033, kFillModeSolid);
		if (*digFlat == 3) {
			Novice::ScreenPrintf(sx + 5, sy + 5, "mousePos.x = %8d", 0);
			Novice::ScreenPrintf(sx + 5, sy + 25, "mousePos.y = %8d", 0);
		}
		if (*digFlat == 5) {
			Novice::ScreenPrintf(sx + 5, sy + 5, "Page2 = %8d", 0);
			Novice::ScreenPrintf(sx + 5, sy + 25, "mousePos.y = %8d", 0);
		}
		Novice::ScreenPrintf(sx + 5, sy + 185, "Page%8d ", (*digFlat - 1) / 2);
	}
}

Triangle TrianglePoint(const Obj* player) {
	Triangle points;

	const Vector2 ap = { player->radius , 0 };
	const Vector2 bp = { -1 * player->radius / 3 , -1 * player->radius / 2 };
	const Vector2 cp = { -1 * player->radius / 3, player->radius / 2 };

	points.a.x = ap.x * cosf(player->angle) - ap.y * sinf(player->angle) + player->pos.x;
	points.a.y = ap.y * cosf(player->angle) + ap.x * sinf(player->angle) + player->pos.y;

	points.b.x = bp.x * cosf(player->angle) - bp.y * sinf(player->angle) + player->pos.x;
	points.b.y = bp.y * cosf(player->angle) + bp.x * sinf(player->angle) + player->pos.y;

	points.c.x = cp.x * cosf(player->angle) - cp.y * sinf(player->angle) + player->pos.x;
	points.c.y = cp.y * cosf(player->angle) + cp.x * sinf(player->angle) + player->pos.y;

	return points;
}
void RenderPlayer(Obj* player, Vector2* scroll) {
	Triangle point = TrianglePoint(player);
	Vector2 a = point.a;
	Vector2 b = point.b;
	Vector2 c = point.c;

	Novice::DrawTriangle(
		int(a.x - scroll->x), int(a.y - scroll->y),
		int(b.x - scroll->x), int(b.y - scroll->y),
		int(c.x - scroll->x), int(c.y - scroll->y),
		RED, kFillModeSolid);
}
void RenderObj(Obj obj[], Vector2* scroll) {
	for (int i = 0; i < 3; i++) {
		Novice::DrawEllipse(int(obj[i].pos.x - scroll->x), int(obj[i].pos.y - scroll->y), int(obj[i].radius), int(obj[i].radius), 0.0f, WHITE, kFillModeSolid);
	}
}

bool CheckPlayerToObj(Obj player, Obj obj) {
	Vector2 d = { player.pos.x - obj.pos.x, player.pos.y - obj.pos.y };
	float totalRadius = player.radius + obj.radius + 10.0f;
	float distanceSquared = d.x * d.x + d.y * d.y;
	return distanceSquared <= totalRadius * totalRadius;
}

float angle_difference(float a, float b) {
	float dif = fmodf(b - a + float(M_PI), 2 * float(M_PI)) - float(M_PI);
	return fmodf(dif + 2 * float(M_PI), 2 * float(M_PI)) - float(M_PI);
}
void UpdatePlayer(Obj* player, Obj obj[], char keys[], char preKeys[]) {

	float r = 100.0f;

	static float angleTmp = 0;
	static float angle_dif = 0;
	float rotateSpeed = float(M_PI) / 180.0f;
	float lerpFactor = 0.2f;

	for (int i = 0; i < 3; i++) {
		float dx = player->pos.x - obj[i].pos.x;
		float dy = player->pos.y - obj[i].pos.y;
		float angle = atan2f(dy, dx);


		if (CheckPlayerToObj(*player, obj[i]) && !obj[i].isRotate) {
			obj[i].isRotate = true;

			angleTmp = angle;
			break;
		}

		if (obj[i].isRotate) {

			Novice::ScreenPrintf(0, 45, "angle_dif = %.10f", angle_dif);
			angle_dif = angle_difference(angleTmp, player->angle);

			player->pos.x = obj[i].pos.x + r * cosf(angleTmp);
			player->pos.y = obj[i].pos.y + r * sinf(angleTmp);
			angleTmp += rotateSpeed;
			player->angle = player->angle + lerpFactor * (angleTmp - player->angle);

		}
		else {
			player->pos.x += player->velocity.x * cosf(player->angle);
			player->pos.y += player->velocity.y * sinf(player->angle);
		}

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && obj[i].isRotate) {
			obj[i].isRotate = false;
		}
	}
	Novice::ScreenPrintf(0, 30 , "player.angle = %.10f  angle = %.10f", player->angle, angleTmp);

}
void UpdateScroll(Obj* player, Vector2* scroll) {
	//マップサイズ
	float mapWidthMax = 3.0f * kWindowWidth;
	float mapWidthMin = -2.0f * kWindowWidth;

	float mapHeightMax = 3.0f * kWindowHeight;
	float mapHeightMin = -2.0f * kWindowHeight;

	//スクロール発生ターゲット
	float rightScrollTrigger = scroll->x + kWindowWidth * 2.0f / 3.0f;
	float leftScrollTrigger = scroll->x + kWindowWidth * 1.0f / 3.0f;

	float topScrollTrigger = scroll->y + kWindowHeight * 1.0f / 3.0f;
	float bottomScrollTrigger = scroll->y + kWindowHeight * 2.0f / 3.0f;

	//プレイヤーの方向によってスクロール
	if (player->pos.x > rightScrollTrigger) {
		//scroll->x += player->pos.x - rightScrollTrigger;
	}
	else if (player->pos.x < leftScrollTrigger) {
		//scroll->x -= leftScrollTrigger - player->pos.x;
	}

	if (player->pos.y > bottomScrollTrigger) {
		//scroll->y += player->pos.y - bottomScrollTrigger;
	}
	else if (player->pos.y < topScrollTrigger) {
		//scroll->y -= topScrollTrigger - player->pos.y;
	}

	//スクロールの範囲処理
	if (scroll->x < mapWidthMin - 100) {
		scroll->x = mapWidthMin - 100;
	}
	if (scroll->x > mapWidthMax - kWindowWidth) {
		scroll->x = mapWidthMax - kWindowWidth;
	}
	if (scroll->y < mapHeightMin - 100) {
		scroll->y = mapHeightMin - 100;
	}
	if (scroll->y > mapHeightMax - kWindowHeight - 100) {
		scroll->y = mapHeightMax - kWindowHeight - 100;
	}
}

