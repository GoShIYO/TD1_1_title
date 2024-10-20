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
};

void InitSound(Sound* sound);