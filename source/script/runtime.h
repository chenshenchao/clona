#ifndef CLONA_SCRIPT_RUNTIME_H
#define CLONA_SCRIPT_RUNTIME_H

#include <map>
#include "archetype.h"

namespace clona {
	/**
	 * 作用域
	 */
	class scope final {
		scope* parent;
		std::map<std::string, any> variables;
	public:
	};

	/**
	 * 表达式
	 * 
	 */
	class expression final {
		enum {
			boolean,
			integer,
			number,
			call,
		} kind;
	};

	/**
	 * 语句
	 */
	class statement final {
		enum {
			block,
			if_block,
			while_block,
			result,
		} kind;
	};
}

#endif
