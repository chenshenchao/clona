#pragma once

#include <memory>
#include <unordered_map>
#include "actor.h"

namespace clona {
	/**
	 * 导演类
	 * 
	 */
	class director {
		unsigned int actor_autoid;
		std::unordered_map<int, std::weak_ptr<actor>> actors;
	public:
		director() :actor_autoid(1), actors() {}

		void attach();
		void detach();
		void update();

		std::shared_ptr<actor> new_actor(std::shared_ptr<actor> parent) {
			unsigned int id = actor_autoid++;
			std::shared_ptr<actor> result(new actor(id, parent));
			actors.emplace(id, result);
			return result;
		}
	};
}