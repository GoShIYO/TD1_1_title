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
};

/// <summary>
/// プレイヤー初期化関数
/// </summary>
/// <param name="player"></param>
void InitPlayer(Obj* player);

/// <summary>
/// オブジェクト(丸)初期化関数
/// </summary>
/// <param name="obj"></param>
void InitObj(Obj obj[]);

/// <summary>
/// プレイヤーの更新処理
/// </summary>
/// <param name="palyer"></param>
/// <param name="obj"></param>
/// <param name="keys"></param>
/// <param name="preKeys"></param>
void UpdatePlayer(Obj* palyer, Obj obj[], char keys[], char preKeys[]);

/// <summary>
/// プレイヤー描画
/// </summary>
/// <param name="player"></param>
void RenderPlayer(Obj* player);


/// <summary>
/// オブジェクト(丸)描画
/// </summary>
/// <param name="obj"></param>
void RenderObj(Obj obj[]);