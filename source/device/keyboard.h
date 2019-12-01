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
		*
		*/
		keyboard() :old(nullptr), now(nullptr) {}

		~keyboard() {
			if (nullptr != now) delete[] now;
			if (nullptr != old) delete[] old;
		}

		keyboard& operator=(const keyboard&) = delete;
		keyboard& operator=(const keyboard&&) = delete;

		bool is_down(int key) const {
			return now[key];
		}

		bool is_up(int key) const {
			return !now[key];
		}

		bool is_press(int key) const {
			return (now[key]) && (!old[key]);
		}

		bool is_loose(int key) const {
			return (!now[key]) && (old[key]);
		}

		void update();
	};
}

#endif
