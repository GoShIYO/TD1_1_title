#include <Novice.h>
#include"obj.h"
#include"enemy.h"

const char kWindowTitle[] = "5107_イノウエ_カン_ミハラ_リ";
const int kWindowWidth = 1280;
const int kWindowHeight = 720;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);


	Obj player;
	InitPlayer(&player);

	Obj obj[3];
	InitObj(obj);

	Enemy enemy;
	InitEnemy(enemy);

	System system;
	InitSystem(&system);

	AllResource texture;
	initializeResource(&texture);

	Vector2 scroll;
	scroll = { 0,0 };

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		/// ↓更新処理ここから

		if (keys[DIK_R] && !preKeys[DIK_R]) {
			player.pos = {200.0f,100.0f};
			player.angle = (float)(M_PI) / 8.0f;
		}

		UpdatePlayer(&player, obj, keys, preKeys);

		EnemyMove(enemy);

		if (keys[DIK_UP]) {
			scroll.y -= 10;
		}
		if (keys[DIK_DOWN]) {
			scroll.y += 10;

		}
		if (keys[DIK_LEFT]) {
			scroll.x -= 10;

		}
		if (keys[DIK_RIGHT]) {
			scroll.x += 10;

		}

		/// ↑更新処理ここまで
		/// ---------------------------------------------------------------------
		/// ↓描画処理ここから
		UpdateScroll(&player, &scroll);
		Novice::DrawBox(0, 0, kWindowWidth,kWindowHeight,0,0x002222FF,kFillModeSolid);
		RenderPlayer(&player,&scroll);
		//RenderObj(obj);
		for (int i = 0; i < 3; i++) {
			showCommonColorTexture(90, 90, 0, obj[i].pos.x, obj[i].pos.y, texture.booble60_90, 0xFFAAAAFF,&scroll);
		}
		Novice::DrawBox(-2 * kWindowWidth - int(scroll.x), -2 * kWindowHeight - int(scroll.y), 5 * kWindowWidth - 100, 5 * kWindowHeight - 100, 0, RED, kFillModeWireFrame);

		RenderEnmey(enemy);
		EnemyDebug(enemy);
		Novice::ScreenPrintf(0, 0, "scroll x : %.2f y : %.2f", scroll.x, scroll.y);

		viewDig(&system.digFlat, keys[DIK_P], preKeys[DIK_P], keys[DIK_LBRACKET], preKeys[DIK_LBRACKET], keys[DIK_RBRACKET], preKeys[DIK_RBRACKET]);

		/// ↑描画処理ここまで
		/// ---------------------------------------------------------------------


		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
