﻿#pragma once

#include <vector>

namespace clona {
	/**
	 * 脚本代码实体
	 * 
	 */
	class entity {
		void *code;
		std::vector<void*> constants;
	public:
		entity(void *code, std::vector<void*> &&constants) :
			code(code),
			constants(std::move(constants)){}
		~entity() {
			delete[] code;
		}
	};
}
