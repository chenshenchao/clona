#ifndef CLONA_QUANTITY_H
#define CLONA_QUANTITY_H

namespace clona {
	struct quantity {
		float x;
		float y;
		float z;

		quantity(): x(0.0f), y(0.0f), z(0.0f) {}

		static quantity operator + (quantity one, quantity two) {
			quantity result;
			result.x = one.x + two.x;
			result.y = one.y + two.y;
			result.z = one.z + two.z;
			return result;
		}

		static quantity operator - (quantity one, quantity two) {
			quantity result;
			result.x = one.x - two.x;
			result.y = one.y - two.y;
			result.z = one.z - two.z;
			return result;
		}
	};
}

#endif
