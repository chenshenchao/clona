#pragma once

#include <set>
#include "axis.h"
#include "sprite.h"

namespace clona {
	/**
	 * 场景类
	 * 
	 */
	class scene {
		std::multiset<sprite, z_axis> sprites;
	public:
	};
}