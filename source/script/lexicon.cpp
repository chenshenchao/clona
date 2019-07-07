#include <cctype>
#include "lexicon.h"

/**
 * 提取出词素。
 * 
 */
clona::lexeme clona::lexer::extract(std::istream& stream, clona::scope& scope) {
	character = stream.get();

	// 跳过空白符号
	while (std::isblank(character)) {
		character = stream.get();
	}

	// 处理数字
	if (std::isdigit(character)) {

	}
	// 处理字符串
	else if ('"' == character) {

	}
	// 处理标识符
	else if (std::isalpha(character)) {

	}
	return lexeme();
}