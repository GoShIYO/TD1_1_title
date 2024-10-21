#include <Novice.h>
#include <time.h>
#include "obj.h"
#include "enemy.h"
#include "gimmickObj.h" 
#include"sound.h"

const char kWindowTitle[] = "5107_イノウエ_カン_ミハラ_リ";
const int kWindowWidth = 1280;
const int kWindowHeight = 720;

enum Scene
{
	TITLE,
	HELP,
	PLAY,
	GAME_OVER,
	CLEAR
};
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	int witeHandle = Novice::LoadTexture("white1x1.png");
	srand(static_cast<unsigned>(time(NULL)));

	Obj player;

	Obj obj[objCount];

	Enemy enemy[ENEMY_COUNT];
	Enemy enemyHorming[ENEMY_COUNT];
	Enemy enemyShot[ENEMY_COUNT];

	BossKeys bossKeys[keyCount];

	EnemyBullet bullet[BULLET_COUNT];

	Handle handle;
	LoadImages(handle);

	System system;

	AllResource texture;

	Vector2 scroll = { 0, 0 };

	GimmickObj gimmickObjs[MAX_GIMMICK]; // ギミックオブジェクトの配列

	Particle particles[MAX_PARTICLES];


	Sound sound;
	InitSound(&sound);

	Scene scene = PLAY;
	InitPlayer(&player);
	InitObj(obj);
	InitEnemyNormal(enemy);
	InitEnemyHorming(enemyHorming);
	InitEnemyShot(enemyShot);
	InitEnemyBullet(bullet);
	InitBossKeys(bossKeys, enemyShot);
	InitSystem(&system);
	initializeResource(&texture);
	InitGimmickObjs(gimmickObjs);
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
		switch (scene)
		{
		case TITLE:
			Novice::DrawSprite(0, 0, witeHandle, kWindowWidth, kWindowHeight, 0, 0xf0bce0FF);
			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				scene = PLAY;
			}

			if (scene == PLAY) {
				InitPlayer(&player);
				InitObj(obj);
				InitEnemyNormal(enemy);
				InitEnemyHorming(enemyHorming);
				InitEnemyShot(enemyShot);
				InitEnemyBullet(bullet);
				InitBossKeys(bossKeys, enemyShot);
				InitSystem(&system);
				initializeResource(&texture);
				InitGimmickObjs(gimmickObjs); // ギミックオブジェクトの初期化
				scroll = { 0,0 };
			}

			break;
		case HELP:

			break;
		case PLAY:

			if (keys[DIK_R] && !preKeys[DIK_R]) {
				player.pos = { 200.0f, 100.0f };
				player.angle = (float)(M_PI) / 8.0f;
			}

			UpdatePlayer(&player, obj, keys, preKeys, &sound);
			checkPlayerMoveRange(&player, &sound);
			EmitParticle(particles, &player);
			for (int i = 0; i < MAX_PARTICLES; i++) {
				UpdateParticle(&particles[i]);
			}

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
			UpdatePlayerEnemyEvent(enemy, player, sound);
			UpdatePlayerEnemyEvent(enemyHorming, player, sound);
			UpdatePlayerEnemyEvent(enemyShot, player, sound);

			//弾のアニメーション
			BulletAnim(bullet);

			//プレイヤーと弾の当たり判定
			UpdatePlayerBulletEvent(player, bullet);

			// ギミックオブジェクトの更新
			UpdateGimmickObjs(gimmickObjs, player);

			//鍵の更新
			//UpdateKeys(bossKeys, enemyShot);
			UpdatePlayerKeyEvent(player, bossKeys,sound);

			if (player.health <= 0) {
				scene = GAME_OVER;
			}
			/// ↑更新処理ここまで
			/// ---------------------------------------------------------------------
			/// ↓描画処理ここから
			UpdateScroll(&player, &scroll);
			//Novice::DrawBox(0, 0, kWindowWidth, kWindowHeight, 0, 0x002222FF, kFillModeSolid);
			Novice::DrawSprite(
				-3840 - int(scroll.x * 0.5f), 
				-2160 - int(scroll.y * 0.5f), 
				texture.bg7x7, 1, 1, 0, WHITE);
			RenderObj(obj, &scroll, texture);
			RenderPlayer(&player, &scroll, &texture.player30_32, &texture.attackShield50_48);
			RenderParticle(particles, &scroll);			
			Novice::DrawSprite(
				-3 * kWindowWidth - int(scroll.x),
				-3 * kWindowHeight - int(scroll.y),
				texture.outsideRockWall,1, 1, 0, WHITE);


			// ギミックオブジェクトの描画
			RenderGimmickObjs(gimmickObjs, &scroll);

			RenderEnemy(enemy, scroll, handle.enemy, player.pos.x, player.pos.y);
			RenderEnemy(enemyHorming, scroll, handle.enemyHorming, player.pos.x, player.pos.y);
			RenderEnemy(enemyShot, scroll, handle.enemyShot, player.pos.x, player.pos.y);
			RenderBullet(bullet, scroll, handle.bullet);
			RenderKeys(bossKeys, scroll, texture.key18x38);
			//ミニマップ
			RenderMiniMap(obj, &player);
			RenderMiniMapEnemy(enemy, enemyHorming, enemyShot);
			//DEBUG INFO
			Novice::ScreenPrintf(0, 0, "keyCount : %d", remainingKeys);
			Novice::ScreenPrintf(0, 20, "player.health : %d", player.health);
			Novice::ScreenPrintf(0, 40, "moveX : %d", bullet[0].moveX);

			// デバッグ表示
			viewDig(&system.digFlat, keys[DIK_P], preKeys[DIK_P], keys[DIK_LBRACKET], preKeys[DIK_LBRACKET], keys[DIK_RBRACKET], preKeys[DIK_RBRACKET]);
			break;
		case GAME_OVER:
			Novice::DrawSprite(0, 0, texture.GameOver, 1, 1, 0, 0xfabb01FF);

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				scene = TITLE;
			}
			break;
		case CLEAR:
			Novice::DrawSprite(0, 0, texture.GameClear, 1, 1, 0, 0x0078f3FF);

			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				scene = TITLE;
			}
			break;
		default:
			break;
		}



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
