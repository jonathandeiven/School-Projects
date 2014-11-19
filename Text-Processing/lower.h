#ifndef __LOWER_H__
#define __LOWER_H__

#include <iostream>
#include <string>
#include "parser.h"

/* Class used for decorating text with all lowercase letters */

class Lower : public Parser{
	std::istream *source;
	bool failed;
public:
	Lower(TextProcessor& tp) : Parser(tp) {}
	void setSource(std::istream *inp);
	std::string getWord();
	bool fail() const;
};

#endif
