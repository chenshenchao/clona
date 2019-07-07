#ifndef CLONA_DEVICE_TICKER_H
#define CLONA_DEVICE_TICKER_H

#include <Windows.h>

namespace clona {
	class ticker final {
		bool able;
		float delta;
		LARGE_INTEGER now;
		LARGE_INTEGER counter;
		LARGE_INTEGER frequency;
	public:
		ticker(): able(true), delta(0.0f), now(), counter(), frequency(){}
		void attach();
		void update();
		bool is_active() { return able; }
		void set_active(bool value) { able = value; }
		float get_delta() { return delta; }
	};
}

#endif
