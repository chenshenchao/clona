#pragma once

#include <set>
#include "quantity.h"

namespace clona {
	/**
	 * 精灵
	 */
	class sprite {
		friend class z_axis;
		std::multiset<sprite, z_axis> table;

		f3 position;
	public:

	};
}
