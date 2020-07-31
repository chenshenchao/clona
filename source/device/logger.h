#pragma once

#include <SDL.h>

namespace clona {
	/**
	 * 日志器
	 * 
	 */
	class logger final {
		static void logging(void*, int, SDL_LogPriority, const char*);
	public:
		logger() { }
		logger(logger&&) = delete;
		logger(const logger&) = delete;

		void attach();

		void detach();

		template<typename ...AL>
		void put(const char* message, AL ...arguments) {
			SDL_Log(message, arguments...);
		}
	};
}
