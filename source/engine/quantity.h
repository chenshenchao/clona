#pragma once

namespace clona {
	/**
	 * 3维量
	 * 
	 */
	struct f3 {
		float x;
		float y;
		float z;

		f3(): x(0.0f), y(0.0f), z(0.0f) {}
		f3(float x, float y, float z) : x(x), y(y), z(z) {}
	};

	f3 operator +(const f3 &one, const f3 &two) {
		return { one.x + two.x, one.y + two.y, one.z + two.z };
	}

	f3 operator -(const f3 &one, const f3 &two) {
		return { one.x - two.x, one.y - two.y, one.z - two.z };
	}

	f3 operator *(float length, const f3 &origin) {
		return { origin.x * length, origin.y * length, origin.z * length };
	}

	f3 operator *(const f3& origin, float length) {
		return length * origin;
	}
}
