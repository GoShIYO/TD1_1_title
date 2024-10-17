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
		obj[i].radius = 45.0f;
		//obj[i].pos.x = /*float(rand() % 6400 - 2560)*/0;
		//obj[i].pos.y = /*float(rand() % 6400 - 2560)*/0;
	}
	
	obj[0].pos = { -2071.0f, 1143.5f };  // 区域 (1, 4)
	obj[1].pos = { -2088.6f, 809.0f };   // 区域 (1, 3)
	obj[2].pos = { -1900.2f, 95.9f };    // 区域 (1, 2)
	obj[3].pos = { -1847.1f, 1576.2f };  // 区域 (1, 5)
	obj[4].pos = { -1796.6f, -708.9f };  // 区域 (1, 1)	
	obj[5].pos = { -1718.3f, 532.5f };   // 区域 (1, 3)
	obj[6].pos = { -1644.1f, -108.2f };  // 区域 (1, 2)
	obj[7].pos = { -1626.8f, -974.1f }; // 区域 (1, 1)
	obj[8].pos = { -1482.3f, 1372.6f }; // 区域 (2, 5)
	obj[9].pos = { -1390.7f, 1007.0f }; // 区域 (2, 4)
	obj[10].pos = { -1298.4f, 289.7f };  // 区域 (2, 2)
	obj[11].pos = { -1207.5f, 1664.8f }; // 区域 (2, 5)
	obj[12].pos = { -973.4f, -858.4f };  // 区域 (2, 1)
	obj[13].pos = { -946.6f, 1123.8f };  // 区域 (2, 4)
	obj[14].pos = { -902.2f, -59.7f };   // 区域 (2, 2)
	obj[15].pos = { -864.3f, 384.8f };   // 区域 (2, 2)
	obj[16].pos = { -681.5f, -762.7f };  // 区域 (2, 1)
	obj[17].pos = { -541.5f, 1551.2f };  // 区域 (2, 5)
	obj[18].pos = { -484.5f, -205.8f };  // 区域 (2, 2)
	obj[19].pos = { -429.2f, 712.6f };   // 区域 (2, 3)
	obj[20].pos = { -345.3f, 378.1f };   // 区域 (2, 2)
	obj[21].pos = { -268.7f, -414.9f };  // 区域 (2, 1)
	obj[22].pos = { -229.9f, 1681.7f };  // 区域 (2, 5)
	obj[23].pos = { -213.9f, -951.3f };  // 区域 (2, 1)
	obj[24].pos = { -123.8f, 962.1f };   // 区域 (2, 4)
	obj[25].pos = { 157.4f, -662.4f };   // 区域 (3, 1)
	obj[26].pos = { 223.0f, -240.6f };   // 区域 (3, 2)
	obj[27].pos = { 258.9f, 1171.1f };   // 区域 (3, 4)
	obj[28].pos = { 294.5f, -932.9f };   // 区域 (3, 1)
	obj[29].pos = { 437.4f, 1540.5f };   // 区域 (3, 5)
	obj[30].pos = { 460.9f, 223.9f };    // 区域 (3, 2)
	obj[31].pos = { 750.4f, -324.9f };   // 区域 (3, 2)
	obj[32].pos = { 757.9f, 718.4f };    // 区域 (3, 3)
	obj[33].pos = { 789.3f, 1653.2f };   // 区域 (3, 5)
	obj[34].pos = { 903.1f, -842.9f };   // 区域 (3, 1)
	obj[35].pos = { 1031.8f, -488.2f };  // 区域 (3, 1)
	obj[36].pos = { 1110.4f, 416.6f };   // 区域 (3, 3)
	obj[37].pos = { 1320.1f, -301.3f };  // 区域 (4, 2)
	obj[38].pos = { 1344.3f, 1472.5f };  // 区域 (4, 5)
	obj[39].pos = { 1508.9f, -916.3f };  // 区域 (4, 1)
	obj[40].pos = { 1508.9f, 779.4f };   // 区域 (4, 4)
	obj[41].pos = { 1554.1f, 1252.7f };  // 区域 (4, 5)
	obj[42].pos = { 1757.6f, 1703.2f };  // 区域 (4, 5)
	obj[43].pos = { 1776.2f, -85.8f };   // 区域 (4, 2)
	obj[44].pos = { 1929.9f, 188.2f };   // 区域 (4, 2)
	obj[45].pos = { 2079.6f, 1356.8f };  // 区域 (4, 5)
	obj[46].pos = { 2108.5f, 676.3f };   // 区域 (4, 3)
	obj[47].pos = { 2159.9f, -925.0f };  // 区域 (5, 1)
	obj[48].pos = { 2236.3f, 1624.0f };  // 区域 (5, 5)
	obj[49].pos = { 2328.7f, -671.1f };  // 区域 (5, 1)
	obj[50].pos = { 2390.9f, -110.1f };  // 区域 (5, 2)
	obj[51].pos = { 2582.3f, 1385.2f };  // 区域 (5, 5)
	obj[52].pos = { 2675.4f, 683.9f };   // 区域 (5, 3)
	obj[53].pos = { 2881.8f, -170.4f };  // 区域 (5, 2)
	obj[54].pos = { 2867.5f, -960.3f };  // 区域 (5, 1)
	obj[55].pos = { 2909.5f, 920.3f };   // 区域 (5, 4)
	obj[56].pos = { 3019.5f, 1639.6f };  // 区域 (5, 5)
	obj[57].pos = { 3142.2f, -344.5f };  // 区域 (5, 2)
	obj[58].pos = { 3181.4f, 487.2f };   // 区域 (5, 3)
	obj[59].pos = { 3236.3f, -924.0f };  // 区域 (5, 1)
	obj[60].pos = { 3357.4f, -586.2f };  // 区域 (5, 1)
	obj[61].pos = { 3358.8f, 169.1f };   // 区域 (5, 2)
	obj[62].pos = { 3382.8f, 890.3f };   // 区域 (5, 4)
	obj[63].pos = { 3358.8f, 169.1f };   // 区域 (5, 2)
	obj[64].pos = { 3434.0f, 1253.5f };  // 区域 (5, 5)
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
void RenderMiniMap(Obj obj[], Vector2* scroll,Obj* player) {
	for (int i = 0; i < objCount; i++) {
		Novice::ScreenPrintf(int(obj[i].pos.x - scroll->x), int(obj[i].pos.y - scroll->y), "%d",i);
		Novice::DrawEllipse(
			int(obj[i].pos.x / 20 + kWindowWidth * 5 / 6.0f), int(obj[i].pos.y / 20 + kWindowHeight/8.0f), 
			int(obj[i].radius / 20), int(obj[i].radius / 20),
			0.0f, WHITE, kFillModeSolid);
	}
	Novice::DrawEllipse(
		int(player->pos.x / 20 + kWindowWidth * 5 / 6.0f), int(player->pos.y / 20 + kWindowHeight / 8.0f),
		int(player->radius / 10), int(player->radius / 10),
		0.0f, RED, kFillModeSolid);
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

	if (player->isCollied && player->InvincibleTimer > 0) {
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
		else if (angleTmp < -M_PI) {
			angleTmp = static_cast<float>(M_PI);
		}
		if (player->angle > M_PI) {
			player->angle = -static_cast<float>(M_PI);
		}
		else if (player->angle < -M_PI) {
			player->angle = static_cast<float>(M_PI);
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

