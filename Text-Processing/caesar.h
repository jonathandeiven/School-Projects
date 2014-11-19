#ifndef __CAESAR_H__
#define __CAESAR_H__
#include "parser.h"

/* Class used for decorating text with Caesar X functionality. */

class Caesar : public Parser{
	int skip;
	std::istream *source;
	bool failed;
public:
	Caesar(TextProcessor& tp, int n) : Parser(tp), skip(n) {}
	void setSource(std::istream *inp);
	std::string getWord();
	bool fail() const;
};

#endif
