#pragma once

#include "sprite.h"

namespace clona {
	/**
	 * Z轴
	 */
	struct z_axis {
		bool operator ()(const sprite& one, const sprite& two) {
			return one.position.z > two.position.z;
		}
	};
}
