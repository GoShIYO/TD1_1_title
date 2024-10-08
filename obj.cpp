#include<Novice.h>
#include"obj.h"

extern int kWindowWidth;
extern int kWindowHeight;

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
void RenderPlayer(Obj* player) {
	Triangle point = TrianglePoint(player);
	Vector2 a = point.a;
	Vector2 b = point.b;
	Vector2 c = point.c;

	Novice::DrawTriangle(int(a.x), int(a.y), int(b.x), int(b.y), int(c.x), int(c.y), RED, kFillModeSolid);
}
void RenderObj(Obj obj[]) {
	for (int i = 0; i < 3; i++) {
		Novice::DrawEllipse(int(obj[i].pos.x), int(obj[i].pos.y), int(obj[i].radius), int(obj[i].radius), 0.0f, WHITE, kFillModeSolid);
	}
}

bool CheckPlayerToObj(Obj player, Obj obj) {
	Vector2 d;
	d.x = player.pos.x - obj.pos.x;
	d.y = player.pos.y - obj.pos.y;

	float totalRadius = powf(player.radius + obj.radius + 10.0f, 2) ;
	float distance = d.x * d.x + d.y * d.y;
	if (distance <= totalRadius) {
		return true;
	}
	return false;
}

void UpdatePlayer(Obj* player, Obj obj[], char keys[], char preKeys[]) {


	float r = 100.0f;

	for (int i = 0; i < 3; i++) {

		float dx = player->pos.x - obj[i].pos.x;
		float dy = player->pos.y - obj[i].pos.y;
		float angle = atan2f(dy, dx);

		if (CheckPlayerToObj(*player, obj[i]) && !obj[i].isRotate) {	
			obj[i].isRotate = true;
			break;
		}

		if (obj[i].isRotate) {
			player->pos.x = obj[i].pos.x + r * cosf(angle);
			player->pos.y = obj[i].pos.y + r * sinf(angle);
			player->angle += 0.01f;

		}
		else {
			player->pos.x += player->velocity.x * cosf(player->angle);
			player->pos.y += player->velocity.y * sinf(player->angle);
		}

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && obj[i].isRotate) {
			obj[i].isRotate = false;
		}
	}

}
