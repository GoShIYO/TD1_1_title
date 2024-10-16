#pragma once
#define _USE_MATH_DEFINES
#include<Vector2.h>
#include<math.h>
#include"texture.h"

extern const int kWindowWidth;
extern const int kWindowHeight;
const int objCount = 65;
struct System {
	int digFlat;
};

enum StarType
{
	ELECTRIC = 0,
	FIRE = 1,
	GAS = 2,
	ICE = 3,
	METEOR = 4,
	POISON = 5,
	SAND = 6,
	SUN = 7,
	WATER = 8,
	EARTH = 9
};
struct Obj
{
	Vector2 pos;
	Vector2 velocity;
	float angle;
	float radius;
	float width;
	float height;
	bool isRotate;
	bool isCollied;
	int health;
	int InvincibleTimer;
	int type;
};
struct Rect
{
	Vector2 a;
	Vector2 b;
	Vector2 c;
	Vector2 d;
};
//struct Triangle {
//	Vector2 a;
//	Vector2 b;
//	Vector2 c;
//};

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
/// <param name="player"></param>
/// <param name="obj"></param>
/// <param name="keys"></param>
/// <param name="preKeys"></param>
void UpdatePlayer(Obj* player, Obj obj[], char keys[], char preKeys[]);

/// <summary>
/// プレイヤーの移動範囲処理関数
/// </summary>
/// <param name="player">player</param>
void checkPlayerMoveRange(Obj* player);

/// <summary>
/// プレイヤー描画
/// </summary>
/// <param name="player"></param>
void RenderPlayer(Obj* player,Vector2* scroll,int* handle);

/// <summary>
/// MINI MAP 描画
/// </summary>
/// <param name="obj"></param>
void RenderMiniMap(Obj obj[], Vector2* scroll, Obj* player);
/// <summary>
/// 星描画
/// </summary>
/// <param name="obj">星</param>
/// <param name="scroll">スクロール</param>
/// <param name="texture">テクスチャ</param>
void RenderObj(Obj obj[], Vector2* scroll, AllResource& texture);
/// <summary>
/// スクロールの更新処理
/// </summary>
/// <param name="player">プレイヤー</param>
/// <param name="scroll">スクロール変数</param>
void UpdateScroll(Obj* player, Vector2* scroll);