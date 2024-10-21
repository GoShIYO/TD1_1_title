#include<Novice.h>
#include"obj.h"
#include<time.h>
#include<stdlib.h>
#include<assert.h>


float Lerp(float start, float end, float t);
float EaseOutLerp(float start, float end, float t);
float EaseOutCubic(float start, float end, float t);
/////////////////////////////////////////////////////////////////Normalization/////////////////////////////////////////////////////////////
void InitPlayer(Obj* player) {
	player->pos.x = 640.0f;
	player->pos.y = 220.0f;
	player->velocity.x = 10.0f;
	player->velocity.y = 10.0f;
	player->angle = (float)(M_PI) / 8.0f;
	player->radius = 30.0f;
	player->width = 32.0f;
	player->height = 30.0f;
	player->isRotate = false;
	player->health = 10000;
	player->InvincibleTimer = 60;
	player->attack = false;
	player->isCollied = false;
	player->atTimer = 60;
	player->isAdapt = false;
}
void InitObj(Obj obj[]) {
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < objCount; i++) {
		int randNum = rand() % 9;
		switch (randNum)
		{
		case ELECTRIC:
			obj[i].type = ELECTRIC;
			obj[i].radius = 40.0f;
			break;
		case FIRE:
			obj[i].type = FIRE;
			obj[i].radius = 65.0f;
			break;
		case GAS:
			obj[i].type = GAS;
			obj[i].radius = 101.5f;
			break;
		case ICE:
			obj[i].type = ICE;
			obj[i].radius = 65.0f;
			break;
		case METEOR:
			obj[i].type = METEOR;
			obj[i].radius = 32.5;
			break;
		case POISON:
			obj[i].type = POISON;
			obj[i].radius = 101.5f;
			break;
		case SAND:
			obj[i].type = SAND;
			obj[i].radius = 65.0f;
			break;
		case SUN:
			obj[i].type = SUN;
			obj[i].radius = 40.0f;
		case WATER:
			obj[i].type = WATER;
			obj[i].radius = 58.0f;
			break;
		default:
			break;
		}
		//obj[i].radius = 45.0f;
		//obj[i].pos.x = /*float(rand() % 6400 - 2560)*/0;
		//obj[i].pos.y = /*float(rand() % 6400 - 2560)*/0;
	}
	obj[0].type = EARTH;
	obj[0].radius = 65.0f;
	obj[0].pos = { 640.0f, 320.0f };  // 区域 (1, 4)
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
	obj[30].pos = { 160.9f, 223.9f };    // 区域 (3, 2)
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
	obj[63].pos = { 3258.8f, -69.1f };   // 区域 (5, 2)
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
Rect RectRotedPlayer(const Vector2* pos, float width, float height, float angle) {
	Rect points;
	const Vector2 ap = { -width / 2.0f , -height / 2.0f };
	const Vector2 bp = { width / 2.0f , -height / 2.0f };
	const Vector2 cp = { -width / 2.0f , height / 2.0f };
	const Vector2 dp = { width / 2.0f ,  height / 2.0f };

	points.a.x = ap.x * cosf(angle) - ap.y * sinf(angle) + pos->x;
	points.a.y = ap.y * cosf(angle) + ap.x * sinf(angle) + pos->y;

	points.b.x = bp.x * cosf(angle) - bp.y * sinf(angle) + pos->x;
	points.b.y = bp.y * cosf(angle) + bp.x * sinf(angle) + pos->y;

	points.c.x = cp.x * cosf(angle) - cp.y * sinf(angle) + pos->x;
	points.c.y = cp.y * cosf(angle) + cp.x * sinf(angle) + pos->y;

	points.d.x = dp.x * cosf(angle) - dp.y * sinf(angle) + pos->x;
	points.d.y = dp.y * cosf(angle) + dp.x * sinf(angle) + pos->y;

	return points;
}

void RenderPlayer(Obj* player, Vector2* scroll, int* handle, int* handle2) {
	Rect points = RectRotedPlayer(&player->pos, player->width, player->height, player->angle);
	Vector2 a = points.a;
	Vector2 b = points.b;
	Vector2 c = points.c;
	Vector2 d = points.d;

	float t = 1 - (player->atTimer / 60.0f);
	static unsigned int color = WHITE;

	unsigned int red = (unsigned int)Lerp(0xFF, 0xFF, t);
	unsigned int green = (unsigned int)Lerp(0xFF, 0xFF, t);
	unsigned int blue = (unsigned int)Lerp(0xFF, 0xFF, t);
	unsigned int alpha = (unsigned int)(Lerp(0xF0, 0x00, t));
	color = ((red << 24) | (green << 16) | (blue << 8) | alpha);
	if (!player->isCollied) {
		Novice::DrawQuad(
			int(a.x - scroll->x), int(a.y - scroll->y),
			int(b.x - scroll->x), int(b.y - scroll->y),
			int(c.x - scroll->x), int(c.y - scroll->y),
			int(d.x - scroll->x), int(d.y - scroll->y),
			0, 0, int(player->width), int(player->height),
			*handle, WHITE
		);
		if (player->attack) {

			Rect s_points = RectRotedPlayer(&player->pos, 50.0f, 48.0f, player->angle);
			Vector2 ap = s_points.a;
			Vector2 bp = s_points.b;
			Vector2 cp = s_points.c;
			Vector2 dp = s_points.d;
			Novice::DrawQuad(
				int(ap.x - scroll->x), int(ap.y - scroll->y),
				int(bp.x - scroll->x), int(bp.y - scroll->y),
				int(cp.x - scroll->x), int(cp.y - scroll->y),
				int(dp.x - scroll->x), int(dp.y - scroll->y),
				0, 0, 50, 48,
				*handle2, color
			);
		}
	}
	if (player->InvincibleTimer % 5 == 0 && player->isCollied) {
		Novice::DrawQuad(
			int(a.x - scroll->x), int(a.y - scroll->y),
			int(b.x - scroll->x), int(b.y - scroll->y),
			int(c.x - scroll->x), int(c.y - scroll->y),
			int(d.x - scroll->x), int(d.y - scroll->y),
			0, 0, int(player->width), int(player->height),
			*handle, WHITE
		);
	}


}
void RenderObj(Obj obj[], Vector2* scroll, AllResource& texture) {

	for (int i = 0; i < objCount; i++) {
		static int handle;
		switch (obj[i].type)
		{
		case ELECTRIC:
			handle = texture.electricStar65_160;
			break;
		case FIRE:
			handle = texture.fireStar100_130;

			break;
		case GAS:
			handle = texture.gasStar150_203;

			break;
		case ICE:
			handle = texture.iceStar100_130;
			break;
		case METEOR:
			handle = texture.meteorStar60_65;

			break;
		case POISON:
			handle = texture.posionStar150_203;

			break;
		case SAND:
			handle = texture.sandStar100_130;

			break;
		case SUN:
			handle = texture.sun65_160;

			break;
		case WATER:
			handle = texture.waterStar80_106;

			break;
		case EARTH:
			handle = texture.earthStar100_130;
			break;
		default:
			break;
		}
		Novice::DrawSprite(
			int(obj[i].pos.x - obj[i].radius - scroll->x),
			int(obj[i].pos.y - obj[i].radius - scroll->y),
			handle, 1, 1, 0, WHITE
		);
	}
}
float SetRotedSpeed(int* const objType) {
	static float speed = 0;
	for (int i = 0; i < objCount; i++) {
		switch (*objType)
		{
		case ELECTRIC:
			speed = float(M_PI) / 60.0f;
			break;
		case FIRE:
			speed = float(M_PI) / 90.0f;

			break;
		case GAS:
			speed = float(M_PI) / 180.0f;

			break;
		case ICE:
			speed = float(M_PI) / 90.0f;

			break;
		case METEOR:
			speed = float(M_PI) / 75.0f;

			break;
		case POISON:
			speed = float(M_PI) / 180.0f;

			break;
		case SAND:
			speed = float(M_PI) / 90.0f;

			break;
		case SUN:
			speed = float(M_PI) / 60.0f;

			break;
		case WATER:
			speed = float(M_PI) / 75.0f;

			break;
		case EARTH:
			speed = float(M_PI) / 90.0f;

			break;
		default:
			break;
		}
	}
	return speed;
}
void RenderMiniMap(Obj obj[], Obj* player) {
	Novice::DrawBox(945, 25, 320, 165, 0, 0x100824A0, kFillModeSolid);
	for (int i = 0; i < objCount; i++) {
		//Novice::ScreenPrintf(int(obj[i].pos.x - scroll->x), int(obj[i].pos.y - scroll->y), "%d", i);
		Novice::DrawEllipse(
			int(obj[i].pos.x / 20 + kWindowWidth * 5 / 6.0f), int(obj[i].pos.y / 20 + kWindowHeight / 8.0f),
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
	float totalRadius = player.radius + obj.radius;
	float distanceSquared = d.x * d.x + d.y * d.y;
	return distanceSquared <= totalRadius * totalRadius;
}

float angle_difference(float a, float b) {
	float dif = fmodf(b - a + float(M_PI), 2 * float(M_PI)) - float(M_PI);
	return fmodf(dif + 2 * float(M_PI), 2 * float(M_PI)) - float(M_PI);
}

void InitParticle(Particle* p, float x, float y, float direction) {
	p->pos.x = x;
	p->pos.y = y;

	float angle = direction + ((rand() % 30 - 20) * (float(M_PI) / 45.0f));
	float speed = (rand() % 5) / 10.0f + 2.0f;

	p->velocity.x = cosf(angle) * speed;
	p->velocity.y = sinf(angle) * speed;
	p->life = 1.0f;
	p->size = (rand() % 5) + 1.0f;
	p->isActive = true;
}
//パーティクル出す初期処理
void EmitParticle(Particle particles[], Obj* player) {

	for (int i = 0; i < MAX_PARTICLES; i++) {
		if (!particles[i].isActive && !player->isRotate) {

			InitParticle(
				&particles[i],
				player->pos.x - player->width / 2.0f * cosf(player->angle),
				player->pos.y - player->height / 2.0f * sinf(player->angle),
				player->angle - float(M_PI));
			break;
		}
	}
}
//線形補間
float Lerp(float start, float end, float t) {
	return start + t * (end - start);
}
float EaseOutLerp(float start, float end, float t) {
	t = 1.0f - (1.0f - t) * (1.0f - t);
	return start + t * (end - start);
}
float EaseOutCubic(float start, float end, float t) {
	t = 1.0f - powf(1.0f - t, 3);
	return start + t * (end - start);
}
//パーティクル更新処理
void UpdateParticle(Particle* particles) {

	if (particles->isActive) {

		particles->pos.x += particles->velocity.x;
		particles->pos.y += particles->velocity.y;

		particles->life -= 0.01f;
		float t = 1.0f - particles->life;


		unsigned int r = (unsigned int)EaseOutCubic(0xf4, 0x27, t);
		unsigned int g = (unsigned int)EaseOutCubic(0xbb, 0x69, t);
		unsigned int b = (unsigned int)EaseOutCubic(0xf2, 0xcd, t);
		unsigned int a = (unsigned int)(EaseOutLerp(0xFF, 0x00, t));

		particles->color = ((r << 24) | (g << 16) | (b << 8) | a);
		if (particles->life <= 0) {
			particles->isActive = false;
		}

	}
}
void RenderParticle(Particle particles[], Vector2* scroll) {
	for (int i = 0; i < MAX_PARTICLES; i++) {
		if (particles[i].isActive) {
			Novice::DrawEllipse(
				int(particles[i].pos.x - scroll->x), int(particles[i].pos.y - scroll->y),
				int(particles[i].size), int(particles[i].size),
				0, particles[i].color, kFillModeSolid);
		}
	}
}

void UpdatePlayer(Obj* player, Obj obj[], char keys[], char preKeys[], Sound* sound) {
	assert(player != nullptr);
	assert(obj != nullptr);
	assert(keys != nullptr);
	assert(preKeys != nullptr);
	assert(sound != nullptr);

	static float angleTmp = 0;
	static float angle_dif = 0;
	static float t = 0;
	static float rotateSpeed = 0;
	float lerpSpeed = 0.01f;
	static int rotateDirection = 1;
	static Vector2 objPosTmp = { 0 };
	static float radiusTmp = 0.0f;
	//無敵時間処理
	if (player->isCollied && player->InvincibleTimer > 0) {
		player->InvincibleTimer--;
	}
	else {
		player->InvincibleTimer = 60;
		player->isCollied = false;
	}
	//攻撃処理
	if (!player->isRotate) {
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			player->attack = true;
			if (!Novice::IsPlayingAudio(sound->shield.play) && player->atTimer == 60) {
				sound->shield.play = Novice::PlayAudio(sound->shield.audio, 0, 1.0f);
			}
		}
	}
	if (player->attack && player->atTimer > 0) {
		player->atTimer--;
	}
	else {
		player->atTimer = 60;
		player->attack = false;
	}

	//Novice::ScreenPrintf(0, 200, "player.iTimer = %d", player->InvincibleTimer);

	for (int i = 0; i < objCount; i++) {
		float dx = player->pos.x - obj[i].pos.x;
		float dy = player->pos.y - obj[i].pos.y;
		float angle = atan2f(dy, dx);
		float crossProduct = dx * 0 - dy * 1;

		if (CheckPlayerToObj(*player, obj[i]) && !player->isRotate) {
			player->isRotate = true;

			radiusTmp = sqrtf(dx * dx + dy * dy);
			angleTmp = angle;
			rotateSpeed = SetRotedSpeed(&obj[i].type);
			t = 0;
			objPosTmp = obj[i].pos;
			player->isAdapt = true;
			if (crossProduct > 0) {
				rotateDirection = 1;
			}
			else if (crossProduct < 0) {
				rotateDirection = -1;
			}
			break;
		}
	}

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && player->isRotate && !player->isAdapt) {
		player->isRotate = false;
	}

	if (player->isRotate) {
		//Novice::ScreenPrintf(700, 45, "angle_dif = %.10f", angle_dif);
		Novice::StopAudio(sound->player_move.play);
		angle_dif = angle_difference(angleTmp, player->angle);

		player->pos.x = objPosTmp.x + radiusTmp * cosf(angleTmp);
		player->pos.y = objPosTmp.y + radiusTmp * sinf(angleTmp);
		angleTmp += rotateSpeed * rotateDirection;

		if (t < 1.0f) {
			t += lerpSpeed;
		}

		player->angle = Lerp(player->angle, angleTmp, t);

		if (t > 0.3f) {
			player->isAdapt = false;
		}
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
		if (!Novice::IsPlayingAudio(sound->player_move.play)) {
			sound->player_move.play = Novice::PlayAudio(sound->player_move.audio, 1, 0.2f);
		}
	}

	//Novice::ScreenPrintf(700, 30, "player.angle = %.10f  angle = %.10f", player->angle, angleTmp);
}

void checkPlayerMoveRange(Obj* player, Sound* sound) {
	const int rangeWidthMin = -kWindowWidth * 2 + 100;
	const int rangeWidthMax = kWindowWidth * 3 - 100;
	const int rangeHeightMin = -kWindowHeight * 2 + 100;
	const int rangeHeightMax = kWindowHeight * 3 - 100;

	if (player->pos.x + player->radius > rangeWidthMax ||
		player->pos.x - player->radius < rangeWidthMin) {
		player->angle = float(M_PI) - player->angle;
		if (!Novice::IsPlayingAudio(sound->collision_wall.play)) {
			sound->collision_wall.play = Novice::PlayAudio(sound->collision_wall.audio, 0, 0.7f);
		}
	}

	if (player->pos.y + player->radius > rangeHeightMax ||
		player->pos.y - player->radius < rangeHeightMin) {
		player->angle = -player->angle;
		if (!Novice::IsPlayingAudio(sound->collision_wall.play)) {
			sound->collision_wall.play = Novice::PlayAudio(sound->collision_wall.audio, 0, 0.7f);
		}
	}

	//Novice::ScreenPrintf(700, 80, "player.pos x = %.2f  y = %.2f", player->pos.x, player->pos.y);
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
