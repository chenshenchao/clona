#include "ticker.h"

/**
 * 初始化时间。
 * 
 */
void clona::ticker::attach() {
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&now);
}

/**
 * 更新时间。
 * 
 */
void clona::ticker::update() {
	QueryPerformanceCounter(&counter);
	delta = static_cast<float>((counter.QuadPart - now.QuadPart) / frequency.QuadPart / 1000000);
	now = counter;
}