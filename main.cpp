#include <Novice.h>
#include <time.h>
#include "obj.h"
#include "enemy.h"
#include "gimmickObj.h" 

const char kWindowTitle[] = "5107_イノウエ_カン_ミハラ_リ";
const int kWindowWidth = 1280;
const int kWindowHeight = 720;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    // ライブラリの初期化
    Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

    srand(static_cast<unsigned>(time(NULL)));

    Obj player;
    InitPlayer(&player);

	Obj obj[objCount];
	InitObj(obj);

	Enemy enemy[ENEMY_COUNT];
	Enemy enemyHorming[ENEMY_COUNT];
	Enemy enemyShot[ENEMY_COUNT];
	InitEnemyNormal(enemy);
	InitEnemyHorming(enemyHorming);
	InitEnemyShot(enemyShot);

	EnemyBullet bullet[BULLET_COUNT];
	InitEnemyBullet(bullet);

	Handle handle;
	LoadImages(handle);

	System system;
	InitSystem(&system);

    AllResource texture;
    initializeResource(&texture);

    Vector2 scroll = { 0, 0 };

    GimmickObj gimmickObjs[MAX_GIMMICK]; // ギミックオブジェクトの配列
    InitGimmickObjs(gimmickObjs); // ギミックオブジェクトの初期化

    // キー入力結果を受け取る箱
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    // ウィンドウの×ボタンが押されるまでループ
    while (Novice::ProcessMessage() == 0) {
        // フレームの開始
        Novice::BeginFrame();

        // キー入力を受け取る
        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        /// ↓更新処理ここから

        if (keys[DIK_R] && !preKeys[DIK_R]) {
            player.pos = { 200.0f, 100.0f };
            player.angle = (float)(M_PI) / 8.0f;
        }

		UpdatePlayer(&player, obj, keys, preKeys);
		checkPlayerMoveRange(&player);

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

		//敵の移動処理
		EnemyMove(enemy);
		EnemyMoveHorming(enemyHorming, player);
		BulletShot(enemyShot, player, bullet);

		//敵の移動制限
		EnemyRange(enemy, enemyHorming);

		//敵の当たり判定
		UpdatePlayerEnemyEvent(enemy, player, keys, preKeys);
		UpdatePlayerEnemyEvent(enemyHorming, player, keys, preKeys);

		// ギミックオブジェクトの更新
		UpdateGimmickObjs(gimmickObjs, player);

		/// ↑更新処理ここまで
		/// ---------------------------------------------------------------------
		/// ↓描画処理ここから
		UpdateScroll(&player, &scroll);
		Novice::DrawBox(0, 0, kWindowWidth,kWindowHeight,0,0x002222FF,kFillModeSolid);
		RenderPlayer(&player,&scroll,&texture.player30_32);
		RenderMiniMap(obj,&scroll,&player);
		RenderObj(obj, &scroll, texture);
		//for (int i = 0; i < objCount; i++) {
		//	showCommonColorTexture(90, 90, 0, obj[i].pos.x, obj[i].pos.y, texture.bubble60_90, 0xFFAAAAFF,&scroll);
		//}
		RenderMiniMapEnemy(enemy, enemyHorming,enemyShot);
		Novice::DrawBox(-2 * kWindowWidth - int(scroll.x) + 100, -2 * kWindowHeight - int(scroll.y) + 100, 5 * kWindowWidth - 200, 5 * kWindowHeight - 200, 0, RED, kFillModeWireFrame);
		//showCommonColorTexture(130, 130, 0, 500, 500, texture.earthStar100_130, 0xFFFFFFFF, &scroll);


		// ギミックオブジェクトの描画
		RenderGimmickObjs(gimmickObjs, &scroll);

		RenderEnemy(enemy, scroll, handle.enemy, player.pos.x, player.pos.y);
		RenderEnemy(enemyHorming, scroll, handle.enemyHorming, player.pos.x, player.pos.y);
		RenderEnemy(enemyShot, scroll, handle.enemyShot, player.pos.x, player.pos.y);
		RenderBullet(bullet, scroll, handle.bullet);
		Novice::ScreenPrintf(0, 0, "scroll x : %.2f y : %.2f", scroll.x, scroll.y);


        // デバッグ表示
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
