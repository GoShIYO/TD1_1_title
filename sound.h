#pragma once

struct AudioHandle
{
	int audio;
	int play;
};
struct Sound
{
	AudioHandle player_move;
	AudioHandle collision_enemy;
	AudioHandle collision_wall;
	AudioHandle enemy_dead;
	AudioHandle shield;
	AudioHandle key;
	AudioHandle explosion;
	AudioHandle bgm_game;
	AudioHandle titieFlySound;
	AudioHandle titieStopFlySound;
	AudioHandle title_bgm;
};

void InitSound(Sound* sound);