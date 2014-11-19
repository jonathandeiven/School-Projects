#ifndef __DOUBLECON_H__
#define __DOUBLECON_H__

#include <iostream>
#include <string>
#include "parser.h"

/* Class used for decorating text with double consonants. */

class DoubleCon : public Parser{
	std::istream *source;
	bool failed;
public:
	DoubleCon(TextProcessor& tp) : Parser(tp) {}
	void setSource(std::istream *inp);
	std::string getWord();
	bool fail() const;
};

#endif
