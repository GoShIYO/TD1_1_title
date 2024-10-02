#pragma once
#define _USE_MATH_DEFINES
#include<Vector2.h>
#include<math.h>


struct Obj
{
	Vector2 pos;
	Vector2 velocity;
	float angle;
	float radius;
	bool isRotate;
	bool isShoot;
};

struct Triangle {
	Vector2 a;
	Vector2 b;
	Vector2 c;
} ;
//プレイヤー初期化関数
void InitPlayer(Obj* player);
//オブジェクト(丸)初期化関数
void InitObj(Obj obj[]);
//プレイヤーの更新処理
void UpdatePlayer(Obj* palyer, Obj obj[],char keys[], char preKeys[]);
//プレイヤー描画
void RenderPlayer(Obj* player);
//オブジェクト(丸)描画
void RenderObj(Obj obj[]);