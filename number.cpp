#include "number.h"

void showNumber(float x, float y, int mn, int n, int w, int h, int texture) {
	int number[10];
	float numberPosX[10];
	float numberPosY[10];
	for (int i = 0; i < 10; i++) {
		number[i] = -1;
		numberPosX[i] = 0;
		numberPosY[i] = y;
	}
	int counterSaver;

	///number counting
	counterSaver = n;
	for (int i = 0; i < mn; i++) {
		number[i] = int(counterSaver % 10);
		counterSaver /= 10;
	}

	///number position setting
	numberPosX[mn] = x;
	numberPosY[mn] = y;
	for (int i = mn - 1; i > -1; i--) {
		if (number[i] < 10 && number[i] > -1) {
			numberPosX[i] = numberPosX[i + 1] + w + 1;
			numberPosY[i] = numberPosY[4];
		}
		if (number[i + 1] < -1) {
			numberPosX[i] = numberPosX[i + 1];
			numberPosY[i] = y;
		}
	}

	///number show
	for (int i = 0; i < mn; i++) {
		if (number[i] < 10 && number[i] > -1) {
			Novice::DrawQuad(int(numberPosX[i] - w / 2), int(numberPosY[i] - h / 2),
				int(numberPosX[i] + w / 2), int(numberPosY[i] - h / 2),
				int(numberPosX[i] - w / 2), int(numberPosY[i] + h / 2),
				int(numberPosX[i] + w / 2), int(numberPosY[i] + h / 2),
				int((number[i] - 1 + (number[i] == 0) * 10) * (int)w), 0, w, h, texture, 0xFFFFFFFF);
		}
	}

}

void showFloatNumber(float x, float y, int mn, int mnf, float n, int w, int h, int texture) {
	int number[10];
	float numberPosX[10];
	float numberPosY[10];
	int j = mn + mnf;
	int k = 0;
	int l = mn + 1 + mnf - 1;
	for (int i = 0; i < 10; i++) {
		number[i] = -1;
		numberPosX[i] = 0;
		numberPosY[i] = y;
	}
	int counterSaver;
	int counterSaverFloat;

	///number counting
	counterSaver = (int)n;
	counterSaverFloat = int((n - counterSaver) * 100);
	for (; k < mnf; k++) {
		number[k] = int(counterSaverFloat % 10);
		counterSaverFloat /= 10;

	}
	number[k] = 10;
	k++;
	for (; k < mn + mnf + 1; k++) {
		number[k] = int(counterSaver % 10);
		counterSaver /= 10;
	}

	///number position setting
	numberPosX[l] = x;
	numberPosY[l] = y;
	for (l--; l > mn + 1; l--) {
		if (number[l] < 10 && number[l] > -1) {
			numberPosX[l] = numberPosX[l + 1] + w + 1;
			numberPosY[l] = numberPosY[4];
		}
		if (number[l + 1] < -1) {
			numberPosX[l] = numberPosX[l + 1];
			numberPosY[l] = y;
		}
	}
	numberPosX[l] = numberPosX[l + 1] + w + 1;
	numberPosY[l] = numberPosY[4];
	l--;
	for (; l > -1; l--) {
		if (number[l] < 11 && number[l] > -1) {
			numberPosX[l] = numberPosX[l + 1] + w + 1;
			numberPosY[l] = numberPosY[4];
		}
		if (number[l + 1] < -1) {
			numberPosX[l] = numberPosX[l + 1];
			numberPosY[l] = y;
		}
	}

	///number show
	for (; j > (mnf); j--) {
		if (number[j] < 10 && number[j] > -1) {
			Novice::DrawQuad(int(numberPosX[j] - w / 2), int(numberPosY[j] - h / 2),
				int(numberPosX[j] + w / 2), int(numberPosY[j] - h / 2),
				int(numberPosX[j] - w / 2), int(numberPosY[j] + h / 2),
				int(numberPosX[j] + w / 2), int(numberPosY[j] + h / 2),
				int((number[j] - 1 + (number[j] == 0) * 10) * (int)w), 0, w, h, texture, 0xFFFFFFFF);
		}
	}
	Novice::DrawQuad(int(numberPosX[j] - w / 2), int(numberPosY[j] - h / 2),
		int(numberPosX[j] + w / 2), int(numberPosY[j] - h / 2),
		int(numberPosX[j] - w / 2), int(numberPosY[j] + h / 2),
		int(numberPosX[j] + w / 2), int(numberPosY[j] + h / 2),
		int((10) * (int)w), 0, w, h, texture, 0xFFFFFFFF);
	j--;
	for (; j > -1; j--) {
		if (number[j] < 10 && number[j] > -1) {
			Novice::DrawQuad(int(numberPosX[j] - w / 2), int(numberPosY[j] - h / 2),
				int(numberPosX[j] + w / 2), int(numberPosY[j] - h / 2),
				int(numberPosX[j] - w / 2), int(numberPosY[j] + h / 2),
				int(numberPosX[j] + w / 2), int(numberPosY[j] + h / 2),
				int((number[j] - 1 + (number[j] == 0) * 10) * (int)w), 0, w, h, texture, 0xFFFFFFFF);
		}
	}
}

void InitUI(UI& ui)
{
	ui.score = { 10,690 };
	ui.damageShield = { 0 };
	ui.life = { 0 };
	ui.marker = { 0 };
	ui.damageShieldColor = 0xFFFFFFFF;
	ui.lifeColor = 0xFFFFFFFF;
}
