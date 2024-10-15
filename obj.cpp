#include<Novice.h>
#include"obj.h"
#include<time.h>
#include<stdlib.h>

/////////////////////////////////////////////////////////////////Normalization/////////////////////////////////////////////////////////////
void InitPlayer(Obj* player) {
	player->pos.x = 200.0f;
	player->pos.y = 100.0f;
	player->velocity.x = 10.0f;
	player->velocity.y = 10.0f;
	player->angle = (float)(M_PI) / 8.0f;
	player->radius = 30.0f;
	player->isRotate = false;
	player->health = 3;
	player->InvincibleTimer = 60;
	player->isCollied = false;
}
void InitObj(Obj obj[]) {
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < objCount; i++) {
		obj[i].radius = 60.0f;
		obj[i].pos.x = float(rand() % 6400 - 2560);
		obj[i].pos.y = float(rand() % 6400 - 2560);

	}
	//obj[0].pos = { 200.0f,200.0f };
	//obj[1].pos = { 550.0f,530.0f };
	//obj[2].pos = { 890.0f,450.0f };
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
	for (int i = 0; i < objCount; i++) {
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
	static float t = 0;
	float rotateSpeed = float(M_PI) / 90.0f;
	float lerpSpeed = 0.01f;
	static int rotateDirection = 1;
	static Vector2 objPosTmp = { 0 };

	if (player->isCollied && player->InvincibleTimer>0) {
		player->InvincibleTimer--;
		
	}
	else {
		player->InvincibleTimer = 60;
		player->isCollied = false;
	}
	Novice::ScreenPrintf(0, 200, "player.iTimer = %d", player->InvincibleTimer);
	for (int i = 0; i < objCount; i++) {
		float dx = player->pos.x - obj[i].pos.x;
		float dy = player->pos.y - obj[i].pos.y;
		float angle = atan2f(dy, dx);
		float crossProduct = dx * 0 - dy * 1;

		if (CheckPlayerToObj(*player, obj[i]) && !player->isRotate) {
			player->isRotate = true;
			angleTmp = angle;
			t = 0;
			objPosTmp = obj[i].pos;
			if (crossProduct > 0) {
				rotateDirection = 1;
			}
			else if (crossProduct < 0) {
				rotateDirection = -1;
			}
			break;
		}
	}
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && player->isRotate) {
		player->isRotate = false;
	}
	if (player->isRotate) {

		Novice::ScreenPrintf(700, 45, "angle_dif = %.10f", angle_dif);
		angle_dif = angle_difference(angleTmp, player->angle);

		player->pos.x = objPosTmp.x + r * cosf(angleTmp);
		player->pos.y = objPosTmp.y + r * sinf(angleTmp);
		angleTmp += rotateSpeed * rotateDirection;
		if (t < 1.0f) {
			t += lerpSpeed;
		}

		player->angle = player->angle + t * (angleTmp - player->angle);
		if (t >= 1.0f) {
			player->angle = angleTmp;
		}
		if (angleTmp > M_PI) {
			angleTmp = -static_cast<float>(M_PI);
		}
		if (player->angle > M_PI) {
			player->angle = -static_cast<float>(M_PI);
		}
	}
	else {
		player->pos.x += player->velocity.x * cosf(player->angle);
		player->pos.y += player->velocity.y * sinf(player->angle);
	}

	Novice::ScreenPrintf(700, 30, "player.angle = %.10f  angle = %.10f", player->angle, angleTmp);

}
void checkPlayerMoveRange(Obj* player) {
	const int rangeWidthMin = -kWindowWidth * 2 + 100;
	const int rangeWidthMax = kWindowWidth * 3 - 100;
	const int rangeHeightMin = -kWindowHeight * 2 + 100;
	const int rangeHeightMax = kWindowHeight * 3 - 100;

	if (player->pos.x + player->radius > rangeWidthMax || player->pos.x - player->radius < rangeWidthMin) {
		player->angle = float(M_PI) - player->angle;
	}

	if (player->pos.y + player->radius > rangeHeightMax || player->pos.y - player->radius < rangeHeightMin) {
		player->angle = -player->angle;
	}

	Novice::ScreenPrintf(700, 80, "player.pos x = %.2f  y = %.2f", player->pos.x, player->pos.y);

}
void UpdateScroll(Obj* player, Vector2* scroll) {
	//マップサイズ
	float mapWidthMax = 3.0f * kWindowWidth;
	float mapWidthMin = -2.0f * kWindowWidth;

	float mapHeightMax = 3.0f * kWindowHeight;
	float mapHeightMin = -2.0f * kWindowHeight;

	//スクロール発生ターゲット
	float rightScrollTrigger = scroll->x + kWindowWidth * 3.0f / 4.0f;
	float leftScrollTrigger = scroll->x + kWindowWidth * 1.0f / 4.0f;

	float topScrollTrigger = scroll->y + kWindowHeight * 1.0f / 3.0f;
	float bottomScrollTrigger = scroll->y + kWindowHeight * 2.0f / 3.0f;

	//プレイヤーの方向によってスクロール
	if (player->pos.x > rightScrollTrigger) {
		scroll->x += 0.1f * (player->pos.x - rightScrollTrigger);
	}
	else if (player->pos.x < leftScrollTrigger) {
		scroll->x -= 0.1f * (leftScrollTrigger - player->pos.x);
	}

	if (player->pos.y > bottomScrollTrigger) {
		scroll->y += 0.1f * (player->pos.y - bottomScrollTrigger);
	}
	else if (player->pos.y < topScrollTrigger) {
		scroll->y -= 0.1f * (topScrollTrigger - player->pos.y);
	}

	//スクロールの範囲処理
	if (scroll->x < mapWidthMin) {
		scroll->x = mapWidthMin;
	}
	if (scroll->x > mapWidthMax - kWindowWidth) {
		scroll->x = mapWidthMax - kWindowWidth;
	}
	if (scroll->y < mapHeightMin) {
		scroll->y = mapHeightMin;
	}
	if (scroll->y > mapHeightMax - kWindowHeight) {
		scroll->y = mapHeightMax - kWindowHeight;
	}
}

