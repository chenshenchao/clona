#ifndef CLONA_SCRIPT_LEXICON_H
#define CLONA_SCRIPT_LEXICON_H

#include <istream>
#include <string>
#include "runtime.h"

namespace clona {
	/**
	 * 词素
	 * 
	 */
	struct lexeme {
		enum {
			literal_null, // 空
			literal_true, // 字面量 true
			literal_false, // 字面量 false
			literal_string,// 字符串字面量
			literal_number,// 数字字面量
			literal_list, // 数组字面量
			literal_dictionary, // 字典字面量
			keyword_if, // if 关键字
			keyword_else, // else 关键字
			keyword_while, // while 关键字
			keyword_return, // return 关键字
			identifier, // 标识符
			dot,// 点
			colon,// 冒号
			comman,// 逗号
			double_quote,// 双引号
			open_brace,// 左花括号
			close_brace,// 右花括号
			open_bracket,// 左中括号
			close_bracket,// 右中括号
			open_parenthesis,// 左括号
			close_parenthesis,// 右括号
		} token;

		union {
			int integer;
			double number;
			char* text;
		} value;

	};

	/**
	 * 词法分析器
	 * 
	 */
	class lexer final {
		enum {
			normal_mode,
			string_mode,
		} mode;
		int index;
		int character;
	public:
		lexer() :mode(normal_mode), index(0), character(' ') {}
		lexeme extract(std::istream& stream, scope &scope);
		void reset() {
			mode = normal_mode;
			index = 0;
			character = ' ';
		}
	private:

	};
}

#endif
