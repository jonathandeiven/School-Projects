#include <iostream>
#include <string>
#include "caesar.h"

using namespace std;

//Helper function declarations
bool isUpper(char c);
bool isLower(char c);

void Caesar::setSource(istream *inp){ //Sets the input stream
	tp.setSource(inp);
}

string Caesar::getWord(){
	string target = tp.getWord(); //Recursive build of string

	//No need to reduce efficiency if returning same string
	if (skip == 0) return target; 

	else{
		for(unsigned int i = 0; i < target.length(); i++){
			if( isUpper(target[i]) )
				target[i] = (( target[i] + skip - 65 ) % 26 ) + 65; 
				/*Modulo function used because of circular skip nature
				  (i.e. Z->A). Uses ASCII values.*/
			
			else if( isLower(target[i]) )
				target[i] = (( target[i] + skip - 97 ) % 26 ) + 97; 
				//Same as above but uses ASCII values for lowercase 
		}
		return target;
	}
}

bool Caesar::fail() const{ //Returns the fail variable
	return tp.fail(); 
}

bool isUpper(char c){ //Checks to see if char is an uppercase letter
	string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	return uppercase.find(c) != string::npos;
}

bool isLower(char c){ //Checks to see if char is a lowercase letter
	string lowercase = "abcdefghijklmnopqrstuvwxyz";
	return lowercase.find(c) != string::npos;
}
