#include <iostream>
#include <string>
#include "lower.h"

using namespace std;

void Lower::setSource(istream *inp){ //Sets input stream
	tp.setSource(inp);
}

string Lower::getWord(){ //Builds and returns the string with all lowercase
	string target = tp.getWord(); //Recursive build of string

	for(unsigned int i = 0; i < target.length(); i++)
		if( (target[i] >= 'A') && (target[i] <= 'Z') ) //Only need for Uppercase chars
			target[i] = target[i] - 'A' + 'a'; 
			//Replaced uppercase char with lowercase /by changing ASCII values
		
	return target;
}

bool Lower::fail() const{ //Returns the fail variable
	return tp.fail(); //Recursive call
}
