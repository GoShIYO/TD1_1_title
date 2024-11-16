#pragma once
#include <Novice.h>
#include <Vector2.h>

struct Resource final {
	Vector2 pos;
	float width;
	float height;
	int texture;
	int handle;
};

struct AllResource final {
	//OBJ
	int bubble60_90;
	int earthStar100_130;
	int electricStar65_160;
	int fireStar100_130;
	int gasStar150_203;
	int iceStar100_130;
	int waterStar80_106;
	int meteorStar60_65;
	int posionStar150_203;
	int sandStar100_130;
	int sun65_160;
	int player30_32;
	int attackShield50_48;
	int playerExplosion60;
	int enemyExplosion50;
	//SCENE
	int bg7x7;
	int BG3_3;
	int key18x38;
	int GameClear;
	int GameOver;
	int ScoreBoard950x574;
	int textStart151x56;
	int earthStar1000;
	int title932x430;
	int titlePlayer337x279;
	int outsideRockWall;
	//UI
	int damageShield56;
	int life30x22;
	int marker20;
	int textNumber18_25;
	int textScore84_25;
	int textScores53x65;
	int keyHold_noKey;
	int keyHold_haveKey;
};	


////////////////////////////////////////////////////////////////////texture////////////////////////////////////////////////////////////////
 void initializeResource(AllResource* allresource);


////////////////////////////////////////////////////////////////////Order//////////////////////////////////////////////////////////////////
/// <summary>
/// common texture change color
/// </summary>
/// <param name="texture width"></param>
/// <param name="texture height"></param>
/// <param name="ani clock"></param>
/// <param name="posX"></param>
/// <param name="posY"></param>
/// <param name="Texture"></param>
/// <param name="Color"></param>
void showCommonColorTexture(float width, float height, int Clock, float posX, float posY, int texture, unsigned int color,Vector2* scroll);

/// <summary>
/// common Radian texture change color
/// </summary>
/// <param name="texture width"></param>
/// <param name="texture height"></param>
/// <param name="Radian"></param>
/// <param name="ani clock"></param>
/// <param name="posX"></param>
/// <param name="posY"></param>
/// <param name="Texture"></param>
/// <param name="Color"></param>
void showRadianColorTexture(float width, float height, float radian, int Clock, float posX, float posY,
	int texture, unsigned int color);

/// <summary>
/// common Radian texture change color
/// </summary>
/// <param name="texture width"></param>
/// <param name="texture height"></param>
/// <param name="Radian"></param>
/// <param name="ani clock"></param>
/// <param name="posX"></param>
/// <param name="posY"></param>
/// <param name="Texture"></param>
/// <param name="Color"></param>
void showRadian2ColorTexture(float width, float height, float radian, int Clock, float posX, float posY,
	int texture, unsigned int color);

/// <summary>
/// common texture change color
/// </summary>
/// <param name="texture width"></param>
/// <param name="texture height"></param>
/// <param name="ani clock"></param>
/// <param name="posX"></param>
/// <param name="posY"></param>
/// <param name="Texture"></param>
void show4PointColorTexture(float XA, float YA, float XB, float YB, float XC, float YC, float XD, float YD,
	int Clock, int TW, int TH, int texture, unsigned int color);

/// <summary>
/// colorClearnessChanger
/// </summary>
/// <param name="Color(Must be +00 or -FF)"></param>
/// <param name="Changer"></param>
/// <param name="Control"></param>
int colorClearnessChanger(int Color, float Clock, float Time);