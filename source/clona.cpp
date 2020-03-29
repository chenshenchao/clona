#include <SDL.h>
#include "clona.h"
#include "device/keyboard.h"
#include "device/logger.h"
#include "device/mouse.h"
#include "device/organizer.h"
#include "device/ticker.h"
#include "script/interpreter.h"

namespace {
	const Uint32 SDL_INIT_FLAG =
		SDL_INIT_AUDIO |
		SDL_INIT_TIMER |
		SDL_INIT_VIDEO;

	SDL_Event event;
}

/**
 * 程序主入口
 * 
 */
int main(int count, char* arguments[]) {
	using namespace clona;

	try {
		if (0 != SDL_Init(SDL_INIT_FLAG)) {
			return -1;
		}

		the<ticker>.attach();
		the<logger>.attach();
		the<organizer>.attach();
		the<interpreter>.attach();

		the<logger>.put("start game.");

		while (the<ticker>.is_active()) {
			while (0 != SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT) {
					the<ticker>.set_active(false);
					break;
				}
				if (event.type == SDL_KEYDOWN) {
					switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
						the<ticker>.set_active(false);
						break;
					}
				}
				the<mouse>.update();
				the<keyboard>.update();
			}
			the<ticker>.update();
			the<organizer>.update();
		}
	}
	catch (...) {
		the<logger>.put("exception game.");
	}
	the<interpreter>.detach();
	the<organizer>.detach();
	the<logger>.detach();
	SDL_Quit();
	return 0;
}