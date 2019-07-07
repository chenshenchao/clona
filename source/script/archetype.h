#ifndef CLONA_SCRIPT_ARCHETYPE_H
#define CLOAN_SCRIPT_ARCHETYPE_H

#include <string>

namespace clona {
	/**
	 * 对象原型。
	 * 
	 */
	struct any {
		enum {
			null,
			boolean,
			integer,
			number,
			text,
			list,
			dictionary,
			function,
			object,
		} kind;

		union {
			bool boolean;
			int integer;
			double number;
			char *text;
		} value;

		~any() {
			if (kind == text) {
				delete[] value.text;
			}
		}
	};
}

#endif
