#include "texture.h"
#include "math.h"

/////////////////////////////////////////////////////////////////Normalization/////////////////////////////////////////////////////////////
extern void initializeResource(AllResource* texture) {
	///Title
	texture->booble60_90 = Novice::LoadTexture("./Resources/booble60-90.png");

}

////////////////////////////////////////////////////////////////////Order//////////////////////////////////////////////////////////////////


void showCommonColorTexture(float width, float height, int Clock, float posX, float posY,
	int texture, unsigned int color) {

	Novice::DrawQuad(int(posX - width / 2), int(posY - height / 2),
		int(posX + width / 2), int(posY - height / 2),
		int(posX - width / 2), int(posY + height / 2),
		int(posX + width / 2), int(posY + height / 2),
		(0 + ((Clock / 5) * (int)width)), 0, int(width), int(height), texture, color);
}


void showRadianColorTexture(float width, float height, float radian, int Clock, float posX, float posY,
	int texture, unsigned int color) {

	float PX[4];
	float PY[4];

	for (int i = 0; i < 4; i++) {
		PX[i] = (float)-(width / 2 * pow(-1, i));
		PY[i] = (float)(height / 2 * pow(-1, i >= 2));
	}

	for (int i = 0; i < 4; i++) {
		float PosHandleX;
		float PosHandleY;
		PosHandleX = PX[i];
		PosHandleY = PY[i];
		PX[i] = PosHandleX * cosf(radian) - PosHandleY * sinf(radian);
		PY[i] = PosHandleY * cosf(radian) + PosHandleX * sinf(radian);
	}

	Novice::DrawQuad(int(PX[0] + posX), int(-(PY[0] + posY) + 720),
		int(PX[1] + posX), int(-(PY[1] + posY) + 720),
		int(PX[2] + posX), int(-(PY[2] + posY) + 720),
		int(PX[3] + posX), int(-(PY[3] + posY) + 720),
		(0 + ((Clock / 5) * (int)width)), 0, int(width), int(height), texture, color);
}

void showRadian2ColorTexture(float width, float height, float radian, int Clock, float posX, float posY,
	int texture, unsigned int color) {

	float PX[4];
	float PY[4];

	for (int i = 0; i < 4; i++) {
		PX[i] = (float)(width / 2 * pow(-1, i));
		PY[i] = (float)-(height / 2 * pow(-1, i >= 2));
	}

	for (int i = 0; i < 4; i++) {
		float PosHandleX;
		float PosHandleY;
		PosHandleX = PX[i];
		PosHandleY = PY[i];
		PX[i] = PosHandleX * cosf(radian) - PosHandleY * sinf(radian);
		PY[i] = PosHandleY * cosf(radian) + PosHandleX * sinf(radian);
	}

	Novice::DrawQuad(int(PX[0] + posX), int(PY[0] + posY),
		int(PX[1] + posX), int(PY[1] + posY),
		int(PX[2] + posX), int(PY[2] + posY),
		int(PX[3] + posX), int(PY[3] + posY),
		(0 + ((Clock / 5) * (int)width)), 0, int(width), int(height), texture, color);
}

void show4PointColorTexture(float XA, float YA, float XB, float YB, float XC, float YC, float XD, float YD, int Clock,
	int TW, int TH, int texture, unsigned int color) {
	Novice::DrawQuad(int(XA), int(YA),
		int(XB), int(YB),
		int(XC), int(YC),
		int(XD), int(YD),
		(0 + ((Clock / 5) * (int)TW)), 0, int(TW), int(TH), texture, color);
}

int colorClearnessChanger(int Color, float Clock, float Time) {
	int C3 = int((float)Color + (float)(0x000000FF - 0x00000000) * Clock / Time);
	return C3;
}