#pragma once
#include <Novice.h>
#include <Vector2.h>


struct UI
{
	Vector2 score;
	Vector2 damageShield;
	unsigned int damageShieldColor;
	Vector2 life;
	unsigned int lifeColor;
	Vector2 marker;
};
/// <summary>
/// show number by texture
/// </summary>
/// <param name="First Number Centre Pos x"></param>
/// <param name="First Number Centre Pos y"></param>
/// <param name="Mix number of number"></param>
/// <param name="number which want to show"></param>
/// <param name="texture's width"></param>
/// <param name="texture's height"></param>
/// <param name="texture handle"></param>
void showNumber(float x, float y, int mn, int n, int w, int h, int texture);

/// <summary>
/// show float number(.XX) by texture
/// </summary>
/// <param name="First Number Centre Pos x"></param>
/// <param name="First Number Centre Pos y"></param>
/// <param name="Mix number of number"></param>
/// <param name="Mix number of .XX"></param>
/// <param name="number which want to show"></param>
/// <param name="texture's width"></param>
/// <param name="texture's height"></param>
/// <param name="texture handle"></param>
void showFloatNumber(float x, float y, int mn, int mnf, float n, int w, int h, int texture);

void InitUI(UI& ui);