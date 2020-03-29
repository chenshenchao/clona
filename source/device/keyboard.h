#ifndef CLONA_DEVICE_KEYBOARD_H
#define CLONA_DEVICE_KEYBOARD_H

#include <SDL.h>

#define KEY(x) SDL_SCANCODE_##x

namespace clona {
	/**
	 * 键盘类
	 * 
	 */
	class keyboard final {
		Uint8* old;
		Uint8* now;
	public:

		/**
		 * 初始化。
		 */
		keyboard() :old(nullptr), now(nullptr) {}

		/**
		 * 析构。
		 */
		~keyboard() {
			if (nullptr != now) delete[] now;
			if (nullptr != old) delete[] old;
		}

		keyboard& operator=(const keyboard&) = delete;
		keyboard& operator=(const keyboard&&) = delete;

		/**
		 * 按键是否处于按下状态。
		 * 
		 */
		bool is_down(int key) const {
			return now[key];
		}

		/**
		 * 按键是否处于释放状态。
		 * 
		 */
		bool is_up(int key) const {
			return !now[key];
		}

		/**
		 * 按键是否被按下，交替时起效。
		 * 
		 */
		bool is_press(int key) const {
			return (now[key]) && (!old[key]);
		}

		/**
		 * 按键是否被释放，交替时起效。
		 *
		 */
		bool is_loose(int key) const {
			return (!now[key]) && (old[key]);
		}

		/**
		 * 键盘状态更新的瞬间。
		 * 
		 */
		void update() {
			int count = 0;
			const Uint8* state = SDL_GetKeyboardState(&count);
			if (nullptr == now) now = new Uint8[count]{ 0 };
			if (nullptr == old) old = new Uint8[count]{ 0 };
			Uint8* temp = now;
			now = old;
			old = temp;
			for (int i = 0; i != count; ++i) now[i] = state[i];
		}
	};
}

#endif
