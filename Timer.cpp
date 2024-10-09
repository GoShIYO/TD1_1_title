#include <Novice.h>
#include"Timer.h"



void TimerRunAnimtion(Timer* Timer) {
	if (Timer->clock < Timer->time - 1) {
		Timer->clock++;
	}
	else {
		Timer->clock = 0;
	};
}

int TimerToFrame(const Timer Timer) {
	return (int)Timer.clock / 5;
}

void TimerRunZero(Timer* Timer) {
	if (Timer->clock < Timer->time - 1 && Timer->clock > 0) {
		Timer->clock++;
	}
	else {
		Timer->clock = 0;
	};
}