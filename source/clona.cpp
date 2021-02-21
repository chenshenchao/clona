#include <SDL.h>
#include "clona.h"
#include "device/keyboard.h"
#include "device/logger.h"
#include "device/mouse.h"
#include "device/organizer.h"
#include "device/ticker.h"
#include "script/interpreter.h"
#include "engine/director.h"

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
		// 初始化
		if (0 != SDL_Init(SDL_INIT_FLAG)) {
			return -1;
		}
		the<ticker>.attach();
		the<logger>.attach();
		the<organizer>.attach();
		the<interpreter>.attach();
		the<director>.attach();

		// 主循环
		the<logger>.put("start game.");
		while (the<ticker>.is_active()) {
			// 用户输入等事件处理
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
				// 更新状态
				the<mouse>.update();
				the<keyboard>.update();
			}

			// 游戏运行
			the<ticker>.update();
			the<organizer>.update();
		}
	}
	catch (...) {
		the<logger>.put("exception game.");
	}

	// 回收
	the<director>.detach();
	the<interpreter>.detach();
	the<organizer>.detach();
	the<logger>.detach();
	SDL_Quit();
	return 0;
}