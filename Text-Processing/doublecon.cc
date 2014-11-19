#include <iostream>
#include <string>
#include <sstream>
#include "doublecon.h"

using namespace std;

//Helper function declarations
bool isVowel(char c);
bool isAlpha(char c);

void DoubleCon::setSource(istream *inp){ //Sets the input stream
	tp.setSource(inp);
}

string DoubleCon::getWord(){ //Builds and returns the string with doublecon
	stringstream buffer;
	string target = tp.getWord(); //Recursive build of string

	for(unsigned int i = 0; i < target.length(); i++){
		if ( !isVowel(target[i]) && isAlpha(target[i]) ) //for non-vowel alphabeticals
			buffer << target[i] << target[i];
		else                                             //for all other chars
			buffer << target[i]; 
	}

	return buffer.str();
}

bool DoubleCon::fail() const{ //Returns the fail variable
	return tp.fail(); //Recursive call
}

bool isVowel(char c){ //Checks to see if char is vowel
	switch(c){
		case 'A':
		case 'a':
		case 'E':
		case 'e':
		case 'I':
		case 'i':
		case 'O':
		case 'o':
		case 'U':
		case 'u': { return true; break; }
		default: { return false; break;}
	}
}

bool isAlpha(char c){ //Checks to see if char is alphabetical
	string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	return alphabet.find(c) != string::npos;
}
