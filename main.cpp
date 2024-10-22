#include <Novice.h>
#include <time.h>
#include "obj.h"
#include "enemy.h"
#include "gimmickObj.h" 
#include"sound.h"
#include"number.h"

const char kWindowTitle[] = "5107_イノウエ_カン_ミハラ_リ";
const int kWindowWidth = 1280;
const int kWindowHeight = 720;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	srand(static_cast<unsigned>(time(NULL)));

	Obj player;

	Obj obj[objCount];

	ScoreBoard scoreBoard;

	Enemy enemy[ENEMY_COUNT];
	Enemy enemyHorming[ENEMY_COUNT];
	Enemy enemyShot[ENEMY_COUNT];

	BossKeys bossKeys[keyCount];
	Enemy boss;

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
	InitBoss(boss);
	InitSystem(&system);
	initializeResource(&texture);
	InitGimmickObjs(gimmickObjs);
	InitScoreBoard(&scoreBoard);

	UI ui;
	InitUI(ui);

	//アニメション用変数
	Vector2 earthStar = { -980.0f,-280.0f };
	Vector2 textStart = { 565.0f,940.0f };
	Vector2 title = { 150.0f,-216.0f };
	Vector2 titlePlayer = { 1380.0f, 920.0f };
	Vector2 titleParticles = { 1705.0f, 1105.0f };
	float titleTimer = 0;
	float startTimer = 0;
	float scale = 1500;
	float titleEarthAngle = 0;
	bool isPlayTitleAnimation = true;
	bool isSceneChange = false;
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
			//BGM
			Novice::StopAudio(sound.bgm_game.play);
			if (!Novice::IsPlayingAudio(sound.title_bgm.play) && sound.title_bgm.play == -1) {
				sound.title_bgm.play = Novice::PlayAudio(sound.title_bgm.audio, 1, 0.1f);
			}
			if (isPlayTitleAnimation) {
				if (titleTimer < 1.0f) {
					titleTimer += 0.005f;
				}
				else {
					isPlayTitleAnimation = false;
				}
				earthStar.x = EaseOutElastic(-980.0f, -480.0f, titleTimer);
				title.y = EaseOutElastic(-216.0f, -16.0f, titleTimer);
				titlePlayer.x = EaseOutElastic(1380.0f, 880.0f, titleTimer);
				titlePlayer.y = EaseOutElastic(920.0f, 420.0f, titleTimer);
				titleParticles.x = EaseOutElastic(1700.0f, 1200.0f, titleTimer);
				titleParticles.y = EaseOutElastic(1100.0f, 600.0f, titleTimer);
				textStart.y = EaseOutElastic(940.0f, 540.0f, titleTimer);
				
			}
			else {
				titleTimer = 0;
			}
			if (!Novice::IsPlayingAudio(sound.titieStopFlySound.play) && sound.titieStopFlySound.play ==-1) {
				sound.titieStopFlySound.play = Novice::PlayAudio(sound.titieStopFlySound.audio, 0, 1.5f);
			}
			Novice::DrawSprite(0, 0, texture.BG3_3, 1, 1, 0, WHITE);
			Novice::DrawSprite(int(earthStar.x), int(earthStar.y), texture.earthStar1000, scale / 1000.0f, scale / 1000.0f, titleEarthAngle, WHITE);
			Novice::DrawSprite(int(title.x), int(title.y), texture.title932x430, 1, 1, 0, WHITE);
			Novice::DrawSprite(int(textStart.x), int(textStart.y), texture.textStart151x56, 1, 1, 0, WHITE);
			for (int i = 0; i < MAX_PARTICLES; i++) {
				if (!particles[i].isActive) {
					InitParticle(
						&particles[i], titleParticles.x, titleParticles.y, 0.8236f);
					break;
				}
			}
			for (int i = 0; i < MAX_PARTICLES; i++) {
				UpdateParticle(&particles[i]);
				if (particles[i].isActive) {
					Novice::DrawEllipse(
						int(particles[i].pos.x), int(particles[i].pos.y),
						int(particles[i].size), int(particles[i].size),
						0, particles[i].color, kFillModeSolid);
				}
			}
			Novice::DrawSprite(int(titlePlayer.x), int(titlePlayer.y), texture.titlePlayer337x279, 1, 1, 0, WHITE);



			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN] && !isSceneChange && !isPlayTitleAnimation) {
				isSceneChange = true;
				startTimer = 0;
				Novice::StopAudio(sound.title_bgm.play);
				if (!Novice::IsPlayingAudio(sound.titieFlySound.play)) {
					sound.titieFlySound.play = Novice::PlayAudio(sound.titieFlySound.audio, 0, 1.0f);
				}
			}
			if (isSceneChange) {
				startTimer += 0.01f;
				earthStar.x = EaseOutCubic(-480.0f, obj[0].pos.x - 66, startTimer);
				earthStar.y = EaseOutCubic(-280.0f, obj[0].pos.y - 66, startTimer);
				scale = EaseOutCubic(1500.0f, 131.0f, startTimer);
				titleEarthAngle = EaseOutCubic(0, float(M_PI) * 2, startTimer);

				title.y = EaseOutCubic(-16.0f, -616.0f, startTimer);
				titlePlayer.x = EaseInBounce(880.0f, -480.0f, startTimer);
				titlePlayer.y = EaseInBounce(420.0f, -20.0f, startTimer);
				titleParticles.x = EaseInBounce(1200.0f, -800.0f, startTimer);
				titleParticles.y = EaseInBounce(600.0f, -200.0f, startTimer);
				textStart.y = EaseOutCubic(540.0f, 940.0f, startTimer);

				
				if (startTimer > 1) {
					isSceneChange = false;
					scale = 1500.0f;
					titleEarthAngle = 0;
					earthStar = { -980.0f,-280.0f };
					scene = PLAY;
				}
			}
			if (scene == PLAY) {
				InitScoreBoard(&scoreBoard);
				InitPlayer(&player);
				InitObj(obj);
				InitEnemyNormal(enemy);
				InitEnemyHorming(enemyHorming);
				InitEnemyShot(enemyShot);
				InitEnemyBullet(bullet);
				InitBossKeys(bossKeys, enemyShot);
				InitBoss(boss);
				InitSystem(&system);
				initializeResource(&texture);
				InitGimmickObjs(gimmickObjs); // ギミックオブジェクトの初期化
				scroll = { 0,0 };
				sound.title_bgm.play = -1;

			}

			break;
		case HELP:

			break;
		case PLAY:

			//BGM

			if (!Novice::IsPlayingAudio(sound.bgm_game.play)) {
				sound.bgm_game.play = Novice::PlayAudio(sound.bgm_game.audio, 1, 0.1f);
			}

			if (keys[DIK_R] && !preKeys[DIK_R]) {
				player.pos = { 200.0f, 100.0f };
				player.angle = (float)(M_PI) / 8.0f;
			}
			UpdatePlayer(&player, obj, keys, preKeys, &sound, &ui);
			checkPlayerMoveRange(&player, &sound);
			EmitParticle(particles, &player);
			for (int i = 0; i < MAX_PARTICLES; i++) {
				UpdateParticle(&particles[i]);
			}

			//敵の移動処理
			EnemyMove(enemy);
			EnemyMoveHorming(enemyHorming, player);
			BulletShot(enemyShot, player, bullet);

			BossUpdate(boss, scene);

			//敵の移動制限
			EnemyRange(enemy, enemyHorming);

			//敵の当たり判定
			UpdatePlayerEnemyEvent(enemy, player, sound, boss);
			UpdatePlayerEnemyEvent(enemyHorming, player, sound, boss);
			UpdatePlayerEnemyEvent(enemyShot, player, sound, boss);

			//弾のアニメーション
			BulletAnim(bullet);
			//プレイヤーと弾の当たり判定
			UpdatePlayerBulletEvent(player, bullet);


			// ギミックオブジェクトの更新
			UpdateGimmickObjs(gimmickObjs, player);

			//鍵の更新
			//UpdateKeys(bossKeys, enemyShot);
			UpdatePlayerKeyEvent(bossKeys, sound, enemyShot, boss,player);

			if (player.deathTimer <= 0) {
				scene = GAME_OVER;
			}
			/// ↑更新処理ここまで
			/// ---------------------------------------------------------------------
			/// ↓描画処理ここから
			UpdateScroll(&player, &scroll);
			Novice::DrawSprite(
				-3840 - int(scroll.x * 0.5f),
				-2160 - int(scroll.y * 0.5f),
				texture.bg7x7, 1, 1, 0, WHITE);
			RenderObj(obj, &scroll, texture);
			RenderPlayer(&player, &scroll, &texture, &ui);
			RenderParticle(particles, &scroll);
			Novice::DrawSprite(
				-3 * kWindowWidth - int(scroll.x),
				-3 * kWindowHeight - int(scroll.y),
				texture.outsideRockWall, 1, 1, 0, WHITE);


			// ギミックオブジェクトの描画
			RenderGimmickObjs(gimmickObjs, &scroll);

			RenderEnemy(enemy, scroll, handle.enemy, player.pos.x, player.pos.y, texture.enemyExplosion50);
			RenderEnemy(enemyHorming, scroll, handle.enemyHorming, player.pos.x, player.pos.y, texture.enemyExplosion50);
			RenderEnemy(enemyShot, scroll, handle.enemyShot, player.pos.x, player.pos.y, texture.enemyExplosion50);
			RenderBullet(bullet, scroll, handle.bullet);
			RenderKeys(bossKeys, scroll, texture.key18x38);
			RenderBoss(boss, scroll, handle.boss, handle.bossEye);
			//ミニマップ
			RenderMiniMap(obj, &player);
			RenderMiniMapEnemy(enemy, enemyHorming, enemyShot);

			Novice::DrawSprite(10, 675, texture.textScore84_25, 1, 1, 0, WHITE);
			showNumber(ui.score.x, ui.score.y, 5, player.score, 18, 25, texture.textNumber18_25);
			//DEBUG INFO
			//Novice::ScreenPrintf(0, 0, "keyCount : %d", remainingKeys);
			//Novice::ScreenPrintf(0, 20, "player.health : %d", player.health);
			//Novice::ScreenPrintf(0, 40, "moveX : %d", bullet[0].moveX);

			// デバッグ表示
			viewDig(&system.digFlat, keys[DIK_P], preKeys[DIK_P], keys[DIK_LBRACKET], preKeys[DIK_LBRACKET], keys[DIK_RBRACKET], preKeys[DIK_RBRACKET]);

			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				isPlayTitleAnimation = true;
				isSceneChange = false;
				titleTimer = 0;
				startTimer = 0;

				scene = TITLE;
			}
			break;
		case GAME_OVER:
			

			Novice::DrawSprite(0, 0, texture.GameOver, 1, 1, 0, WHITE);
			if (scoreBoard.flat == 1) {
				TimerToMix(&scoreBoard.timer);
				Novice::DrawSprite(165, int(EaseOutCubic(scoreBoard.pos.y, 63.0f, scoreBoard.timer.clock/ scoreBoard.timer.time)), texture.ScoreBoard950x574, 1, 1, 0, WHITE);
				showNumber(745.0f, EaseOutCubic(-298.0f, 390.0f, scoreBoard.timer.clock / scoreBoard.timer.time), 5, player.score,53,65, texture.textScores53x65);
			}

			//BGM
			Novice::StopAudio(sound.bgm_game.play);


			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				if (scoreBoard.flat == 0) {
					scoreBoard.flat++;
				} else {
					isPlayTitleAnimation = true;
					isSceneChange = false;
					titleTimer = 0;
					startTimer = 0;

					scene = TITLE;
				}
			}
			break;
		case CLEAR:
			Novice::DrawSprite(0, 0, texture.GameClear, 1, 1, 0, WHITE);
			if (scoreBoard.flat == 1) {
				TimerToMix(&scoreBoard.timer);
				Novice::DrawSprite(165, int(EaseOutCubic(scoreBoard.pos.y, 63.0f, scoreBoard.timer.clock / scoreBoard.timer.time)), texture.ScoreBoard950x574, 1, 1, 0, WHITE);
				showNumber(745.0f, EaseOutCubic(-298.0f, 390.0f, scoreBoard.timer.clock / scoreBoard.timer.time), 5, player.score, 53, 65, texture.textScores53x65);
			}
			//BGM
			Novice::StopAudio(sound.bgm_game.play);


			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				if (scoreBoard.flat == 0) {
					scoreBoard.flat++;
				} else {
					isPlayTitleAnimation = true;
					isSceneChange = false;
					titleTimer = 0;
					startTimer = 0;

					scene = TITLE;
				}
			}
			break;
		default:
			break;
		}

		Novice::ScreenPrintf(0, 0, "boss.health : %d", boss.health);

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
