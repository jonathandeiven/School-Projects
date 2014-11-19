#ifndef __PARSER_H_
#define __PARSER_H_
#include "textprocess.h"

/*Abstract Class for the Decorator Subclasses*/

class Parser : public TextProcessor{
protected:
	TextProcessor& tp;
	Parser(TextProcessor& tp): tp(tp){}
	~Parser(){ delete &tp; }
};

#endif
