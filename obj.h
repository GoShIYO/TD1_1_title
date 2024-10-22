#pragma once
#define _USE_MATH_DEFINES
#include<Vector2.h>
#include<math.h>
#include"texture.h"
#include"sound.h"
#include"number.h"
#define MAX_PARTICLES 1000

extern const int kWindowWidth;
extern const int kWindowHeight;
const int objCount = 65;
const int keyCount = 4;

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
enum Scene
{
	TITLE = 0,
	HELP = 1,
	PLAY = 2,
	GAME_OVER = 3,
	CLEAR = 4
};
struct Obj
{
	Vector2 pos;
	Vector2 velocity;
	Vector2 deathPosTmp;
	float angle;
	float radius;
	float width;
	float height;
	bool isRotate;
	bool isCollied;
	bool attack;
	bool isAdapt;
	bool isDead;
	int deathTimer;
	int health;
	int InvincibleTimer;
	int type;
	int atTimer;
	int score;
};
struct Rect
{
	Vector2 a;
	Vector2 b;
	Vector2 c;
	Vector2 d;
};
struct Particle {
	Vector2 pos;
	Vector2 velocity;
	float life;
	float size;
	bool isActive;
	int color;
};


//struct Triangle {
//	Vector2 a;
//	Vector2 b;
//	Vector2 c;
//};
struct BossKeys 
{
	Vector2 pos;
	float width;
	float height;
	float radius;
	int remaining;
	bool isHit;
	bool isPosSet;
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
/// <param name="player"></param>
/// <param name="obj"></param>
/// <param name="keys"></param>
/// <param name="preKeys"></param>
void UpdatePlayer(Obj* player, Obj obj[], char keys[], char preKeys[],Sound* sound,UI* ui);

/// <summary>
/// プレイヤーの移動範囲処理関数
/// </summary>
/// <param name="player">player</param>
void checkPlayerMoveRange(Obj* player, Sound* sound);

/// <summary>
/// プレイヤー描画
/// </summary>
/// <param name="player"></param>
void RenderPlayer(Obj* player,Vector2* scroll, AllResource* handle, UI* ui);

/// <summary>
/// パーティクル更新処理
/// </summary>
/// <param name="particles"></param>
void UpdateParticle(Particle* particles);

/// <summary>
/// パーティクル描画
/// </summary>
/// <param name="particles"></param>
/// <param name="scroll"></param>
void RenderParticle(Particle particles[],Vector2* scroll);

//パーティクル初期処理
void EmitParticle(Particle particles[], Obj* player);

/// <summary>
/// MINI MAP 描画
/// </summary>
/// <param name="obj"></param>
void RenderMiniMap(Obj obj[], Obj* player);

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

float Lerp(float start, float end, float t);
float EaseOutLerp(float start, float end, float t);
float EaseOutCubic(float start, float end, float t);
float EaseOutElastic(float start, float end, float t);
float EaseInBounce(float start, float end, float t);
unsigned int RgbaAnimation(unsigned int color, float t);

void InitParticle(Particle* p, float x, float y, float direction);
void UpdateParticle(Particle* particles);
