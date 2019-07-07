#include "ticker.h"

void clona::ticker::attach() {
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&now);
}

void clona::ticker::update() {
	QueryPerformanceCounter(&counter);
	delta = static_cast<float>((counter.QuadPart - now.QuadPart) / frequency.QuadPart / 1000000);
	now = counter;
}