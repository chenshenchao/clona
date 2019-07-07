#ifndef CLONA_CONTENT_ROLE_H
#define CLONA_CONTENT_ROLE_H

namespace clona {
	/**
	 * 人物属性
	 * 
	 */
	struct quality final {
		float hp;
		float mp;
		float hp_max;
		float mp_max;
		float speed;
	};

	/**
	 * 角色
	 */
	class role final {
		quality raw;
		quality now;
	public:

	};
}

#endif
