#ifndef __L337_H__
#define __L337_H__

#include <iostream>
#include <string>
#include "parser.h"

/* Class used for decorating text with L337 */

class L337 : public Parser{
	std::istream *source;
    bool failed;
 public:
    L337(TextProcessor &tp) : Parser(tp) {}
    void setSource(std::istream *inp);
    std::string getWord();
    bool fail() const;
};

#endif
