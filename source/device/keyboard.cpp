#include "keyboard.h"

/**
 * 键盘更新状态
 * 
 */
void clona::keyboard::update() {
	int count = 0;
	const Uint8* state = SDL_GetKeyboardState(&count);
	if (nullptr == now) now = new Uint8[count]{ 0 };
	if (nullptr == old) old = new Uint8[count]{ 0 };
	Uint8* temp = now;
	now = old;
	old = temp;
	for (int i = 0; i != count; ++i) now[i] = state[i];
}