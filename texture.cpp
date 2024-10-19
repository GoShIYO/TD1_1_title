#include "texture.h"
#include "math.h"

/////////////////////////////////////////////////////////////////Normalization/////////////////////////////////////////////////////////////
 void initializeResource(AllResource* texture) {
	///Title
	texture->bubble60_90 = Novice::LoadTexture("./Resources/booble60-90.png");
	texture->earthStar100_130 = Novice::LoadTexture("./Resources/Star/earthStar100x130.png");
	texture->electricStar65_160 = Novice::LoadTexture("./Resources/Star/electricStar65x160.png");
	texture->fireStar100_130 = Novice::LoadTexture("./Resources/Star/fireStar100x130.png");
	texture->gasStar150_203 = Novice::LoadTexture("./Resources/Star/gasStar150x203.png");
	texture->iceStar100_130 = Novice::LoadTexture("./Resources/Star/iceStar100x130.png");
	texture->waterStar80_106 = Novice::LoadTexture("./Resources/Star/waterStar80x106.png");
	texture->meteorStar60_65 = Novice::LoadTexture("./Resources/Star/meteorStar60x65.png");
	texture->posionStar150_203 = Novice::LoadTexture("./Resources/Star/poisonStar150x203.png");
	texture->sandStar100_130 = Novice::LoadTexture("./Resources/Star/sandStar100x130.png");
	texture->sun65_160 = Novice::LoadTexture("./Resources/Star/sun65x160.png");
	texture->player30_32 = Novice::LoadTexture("./Resources/player30_32.png");
	texture->attackShield40x38 = Novice::LoadTexture("./Resources/Effect/attackShield40x38.png");
}

////////////////////////////////////////////////////////////////////Order//////////////////////////////////////////////////////////////////


void showCommonColorTexture(float width, float height, int Clock, float posX, float posY,
	int texture, unsigned int color, Vector2* scroll) {

	Novice::DrawQuad(
		int(posX - width / 2 - scroll->x), int(posY - height / 2 - scroll->y),
		int(posX + width / 2 - scroll->x), int(posY - height / 2 - scroll->y),
		int(posX - width / 2 - scroll->x), int(posY + height / 2 - scroll->y),
		int(posX + width / 2 - scroll->x), int(posY + height / 2 - scroll->y),
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