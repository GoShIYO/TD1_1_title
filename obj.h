#pragma once
#define _USE_MATH_DEFINES
#include<Vector2.h>
#include<math.h>
#include"texture.h"

extern const int kWindowWidth;
extern const int kWindowHeight;
const int objCount = 100;
struct System {
	int digFlat;
};

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




/////////////////////////////////////////////////////////////////Normalization/////////////////////////////////////////////////////////////
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
/// システム初期化関数
/// </summary>
/// <param name="system"></param>
void InitSystem(System* system);

////////////////////////////////////////////////////////////////////Order//////////////////////////////////////////////////////////////////

/// <summary>
/// システム内の数値を簡単に見えるように使うどこ
/// </summary>
/// <param name="digFlat">digFlat数値</param>
/// <param name="key">開くキー</param>
/// <param name="preKey">開くキーのpre</param>
/// <param name="key">前ページキー</param>
/// <param name="preKey">前ページキーのpre</param>
/// <param name="key">次ページキー</param>
/// <param name="preKey">次ページキーのpre</param>
void viewDig(int* digFlat, int key1, int preKey1, int key2, int preKey2, int key3, int preKey3);


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
void RenderPlayer(Obj* player,Vector2* scroll);


/// <summary>
/// オブジェクト(丸)描画
/// </summary>
/// <param name="obj"></param>
void RenderObj(Obj obj[], Vector2* scroll);

void UpdateScroll(Obj* player, Vector2* scroll);