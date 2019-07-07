#ifndef CLONA_SCRIPT_INTERPRETER_H
#define CLONA_SCRIPT_INTERPRETER_H

#include <map>
#include <string>
#include "archetype.h"

namespace clona {
	/**
	 * 脚本解释器
	 */
	class interpreter final {
		std::map<std::string, void*> globals;
		std::map<std::string, void*> functions;
	public:
		interpreter() : globals(), functions() {}
		any interpret(std::istream&);
		void attach();
		void detach();
	};
}

#endif
