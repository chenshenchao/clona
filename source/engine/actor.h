#pragma once

#include <unordered_map>
#include <vector>
#include <memory>

namespace clona {
	/**
	 * 作用物类
	 */
	class actor {
		friend class director;

		unsigned int id;
		std::weak_ptr<actor> parent;
		std::vector<std::shared_ptr<actor>> children;

		actor(unsigned int id, std::shared_ptr<actor> parent) :
			id(id), parent(parent) {
		}
	public:
		
	};
}