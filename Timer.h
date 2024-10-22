#pragma once
#include"texture.h"

/// <summary>
/// {clock,time}
/// </summary>
struct Timer final {
	float clock;
	float time;
};


/// <summary>
/// 動画運行のタイマー
/// </summary>
/// <param name="Timer">動画タイマーの関数</param>
void TimerRunAnimtion(Timer* Timer);



/// <summary>
/// 動画フレームの転換
/// </summary>
/// <param name="Timer">動画タイマーの関数</param>
/// <returns></returns>
int TimerToFrame(const Timer Timer);


/// <summary>
/// 0に戻るタイマー
/// </summary>
/// <param name="Timer">動画タイマーの関数</param>
void TimerRunZero(Timer* Timer);

void TimerToMix(Timer* Timer);
