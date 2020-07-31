#pragma once

#include <Windows.h>

namespace clona {
	/**
	 * 核心类
	 * 
	 */
	class ticker final {
		bool able;
		float delta;
		LARGE_INTEGER now;
		LARGE_INTEGER counter;
		LARGE_INTEGER frequency;
	public:
		ticker(): able(true), delta(0.0f), now(), counter(), frequency(){}
		/**
		 * 初始化时间。
		 *
		 */
		void attach() {
			QueryPerformanceFrequency(&frequency);
			QueryPerformanceCounter(&now);
		}

		/**
		 * 更新时间。
		 *
		 */
		void update() {
			QueryPerformanceCounter(&counter);
			delta = static_cast<float>((counter.QuadPart - now.QuadPart) / frequency.QuadPart / 1000000);
			now = counter;
		}
		bool is_active() { return able; }
		void set_active(bool value) { able = value; }
		float get_delta() { return delta; }
	};
}
