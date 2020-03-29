#ifndef CLONA_DEVICE_MOUSE_H
#define CLONA_DEVICE_MOUSE_H

#include <SDL.h>

#define BUTTON(x) SDL_BUTTON_##x

namespace clona {
	/**
	 * �����
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
		 * ��ʼ����
		 * 
		 */
		mouse() :mx(0), my(0), now(0), old(0), x(mx), y(my) {}

		mouse& operator=(const mouse&) = delete;
		mouse& operator=(const mouse&&) = delete;

		/**
		 * ��ť�Ƿ񱻰��¡�
		 * 
		 */
		bool is_down(int button) const {
			return now & SDL_BUTTON(button);
		}

		/**
		 * ��ť�Ƿ��ͷš�
		 *
		 */
		bool is_up(int button) const {
			return !(now & SDL_BUTTON(button));
		}

		/**
		 * ��ť�Ƿ񱻰��£�����˲����Ч��
		 *
		 */
		bool is_press(int button) const {
			int mark = SDL_BUTTON(button);
			return (now & mark) && !(old & mark);
		}

		/**
		 * ��ť�Ƿ��ͷţ�����˲����Ч��
		 *
		 */
		bool is_loose(int button) const {
			int mark = SDL_BUTTON(button);
			return !(now & mark) && (old & mark);
		}

		/**
		 * ����״̬�Ľ���˲�䡣
		 */
		void update() {
			old = now;
			now = SDL_GetMouseState(&mx, &my);
		}
	};
}

#endif

