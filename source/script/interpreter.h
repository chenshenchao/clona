#pragma once

#include <map>
#include <string>
#include "archetype.h"

namespace clona {
	/**
	 * 脚本解释器
	 * 
	 */
	class interpreter final {
		std::map<std::string, any> globals;
		std::map<std::string, any> functions;
	public:
		interpreter() : globals(), functions() {}
		any interpret(std::istream&);
		void attach();
		void detach();
	};
}
