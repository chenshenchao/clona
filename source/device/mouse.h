#pragma once

#include <SDL.h>

#define BUTTON(x) SDL_BUTTON_##x

namespace clona {
	/**
	 * 鼠标类
	 * 
	 */
	class mouse {
		int mx, my;
		Uint32 now;
		Uint32 old;
	public:
		const int& x;
		const int& y;

		/**
		 * 初始化。
		 * 
		 */
		mouse() :mx(0), my(0), now(0), old(0), x(mx), y(my) {}

		mouse& operator=(const mouse&) = delete;
		mouse& operator=(const mouse&&) = delete;

		/**
		 * 按钮是否被按下。
		 * 
		 */
		bool is_down(int button) const {
			return now & SDL_BUTTON(button);
		}

		/**
		 * 按钮是否释放。
		 *
		 */
		bool is_up(int button) const {
			return !(now & SDL_BUTTON(button));
		}

		/**
		 * 按钮是否被按下，交替瞬间有效。
		 *
		 */
		bool is_press(int button) const {
			int mark = SDL_BUTTON(button);
			return (now & mark) && !(old & mark);
		}

		/**
		 * 按钮是否被释放，交替瞬间有效。
		 *
		 */
		bool is_loose(int button) const {
			int mark = SDL_BUTTON(button);
			return !(now & mark) && (old & mark);
		}

		/**
		 * 更新状态的交替瞬间。
		 */
		void update() {
			old = now;
			now = SDL_GetMouseState(&mx, &my);
		}
	};
}
