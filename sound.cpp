#include<Novice.h>
#include"sound.h"

void InitSound(Sound* sound)
{
	sound->collision_enemy.audio = Novice::LoadAudio("./Resources/Sound/collision_enemy.wav");
	sound->collision_wall.audio = Novice::LoadAudio("./Resources/Sound/collision_wall.wav");
	sound->enemy_dead.audio = Novice::LoadAudio("./Resources/Sound/enemy_dead.wav");
	sound->player_move.audio = Novice::LoadAudio("./Resources/Sound/player_move.wav");
	sound->shield.audio = Novice::LoadAudio("./Resources/Sound/shield.wav");
	sound->key.audio = Novice::LoadAudio("./Resources/Sound/key.wav");
	sound->bgm_game.audio = Novice::LoadAudio("./Resources/Sound/bgm_game.mp3");
	sound->explosion.audio = Novice::LoadAudio("./Resources/Sound/explosion.wav");
	sound->titieFlySound.audio = Novice::LoadAudio("./Resources/Sound/titieFlySound.wav");
	sound->titieStopFlySound.audio = Novice::LoadAudio("./Resources/Sound/titieStopFlySound.wav");
	sound->title_bgm.audio = Novice::LoadAudio("./Resources/Sound/title_bgm.mp3");



	sound->collision_enemy.play = -1;
	sound->collision_wall.play = -1;
	sound->enemy_dead.play = -1;
	sound->player_move.play = -1;
	sound->shield.play = -1;
	sound->key.play = -1;
	sound->bgm_game.play = -1;
	sound->titieFlySound.play = -1;
	sound->titieStopFlySound.play = -1;
	sound->title_bgm.play = -1;
}
