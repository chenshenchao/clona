#ifndef CLONA_SCRIPT_RUNTIME_H
#define CLONA_SCRIPT_RUNTIME_H

#include <map>
#include "archetype.h"

namespace clona {
	/**
	 * ������
	 */
	class scope final {
		scope* parent;
		std::map<std::string, any> variables;
	public:
	};

	/**
	 * ���ʽ
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
	 * ���
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
