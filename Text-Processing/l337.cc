#include <iostream>
#include <string>
#include "l337.h"

using namespace std;

void L337::setSource(istream *inp){ //Sets source
	tp.setSource(inp);
}

string L337::getWord(){ //Builds and returns the decorated string
	string leetspeak = tp.getWord(); //Recursive build of string

	for(unsigned int i = 0; i < leetspeak.length(); i++){
		char c = leetspeak[i];
		//Use switch to find cases where a L337 character swap is needed
		switch(c){
			case 'a':
			case 'A':{ leetspeak[i] = '4'; break; }

			case 'b':
			case 'B':{ leetspeak[i] = '8'; break; }

			case 'z':
			case 'Z':{ leetspeak[i] = '2'; break; }

			case 'e':
			case 'E':{ leetspeak[i] = '3'; break; }

			case 'g':
			case 'G':{ leetspeak[i] = '6'; break; }

			case '!':{ leetspeak[i] = '1'; break; }

			case 't':
			case 'T':{ leetspeak[i] = '7'; break; }

			case 'i':
			case 'I':{ leetspeak[i] = '1'; break; }

			case 'q':
			case 'Q':{ leetspeak[i] = '9'; break; }

			case 'o':
			case 'O':{ leetspeak[i] = '0'; break; }

			case 's':
			case 'S':{ leetspeak[i] = '5'; break; }

			default:{ break; }
		}
	}
	return leetspeak;
}

bool L337::fail() const{  //Returns fail variable
	return tp.fail(); //Recursive call
}
