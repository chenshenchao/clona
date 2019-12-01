#ifndef CLONA_SCRIPT_ARCHETYPE_H
#define CLOAN_SCRIPT_ARCHETYPE_H

#include <string>
#include <exception>

namespace clona {
	/**
	 * 解释异常
	 * 
	 */
	struct interpret_exception : public std::exception {

	};

	/**
	 * 词法异常
	 * 
	 */
	struct lex_exception : public interpret_exception {

	};

	/**
	 * 语法异常
	 * 
	 */
	struct syntax_exception : public interpret_exception {

	};

	/**
	 * 
	 * 
	 */
	struct invoker {
		void* data;
		void* code;
	};

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
			void *object;
			void *list;
			void *dictionary;
			invoker function;
		} value;

		~any() {
			if (kind == text) {
				delete[] value.text;
			}
		}
	};
}

#endif
