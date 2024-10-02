#include <Novice.h>
#include"obj.h"

const char kWindowTitle[] = "5107_イノウe_カン_ミハラ_リ";
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




		/// ↑更新処理ここまで
		/// ---------------------------------------------------------------------
		/// ↓描画処理ここから




		RenderPlayer(&player);
		RenderObj(obj);




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
