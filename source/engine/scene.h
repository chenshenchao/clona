#pragma once

#include <set>
#include <memory>
#include "axis.h"
#include "actor.h"
#include "sprite.h"

namespace clona {
	/**
	 * 场景类
	 * 
	 */
	class scene {
		std::multiset<std::weak_ptr<sprite>, z_axis> sprites;
	public:
	};
}