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
	int booble60_90;
};


////////////////////////////////////////////////////////////////////texture////////////////////////////////////////////////////////////////
extern void initializeResource(AllResource* allresource);


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
void showCommonColorTexture(float width, float height, int Clock, float posX, float posY, int texture, unsigned int color);

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