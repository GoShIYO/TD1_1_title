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
	sound->bgm_title.audio = Novice::LoadAudio("./Resources/Sound/title_bgm.mp3");


	sound->collision_enemy.play = -1;
	sound->collision_wall.play = -1;
	sound->enemy_dead.play = -1;
	sound->player_move.play = -1;
	sound->shield.play = -1;
	sound->key.play = -1;
	sound->bgm_title.play = -1;
}
