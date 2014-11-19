#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#include "stack.h"
//#include "expression.h"

using namespace std;

//Function declarations
string buildPostfix();

int main(){
	Stack s; //Create stack of size 10
	string postfix = buildPostfix(); //Get postfix from stdin
	istringstream postfixBuffer(postfix); //Buffer for converting to infix
	string temp;

	while( getline(postfixBuffer, temp, ' ') ){ 
	//Gets operands/operators separated by a single whitespace (formatted in buildPostfix)
		if ( s.isFull() ){ //Overflow case
			while ( !s.isEmpty() ){ //Loop through and delete all nodes in Stack
				Expression* garbageCleaner = s.pop();
				delete garbageCleaner;
				garbageCleaner = NULL;
			}
			cerr << "Stack overflow" << endl;
			return EXIT_FAILURE; //Failure return
		}

		else if (temp == "NEG" || temp == "ABS"){ 
		//Unary operand found in postfix string
			Expression* operand = s.pop(); //Perform unary operation on last item in stack
			Expression* unaryExp = new UnaryExpression(operand, temp);
			s.push(unaryExp); //Push new expression to stack
		}
			
		else if (temp == "+" || temp == "-" || temp == "*" || temp == "/"){ 
		//Binary operand found in postfix string
			Expression* operand2 = s.pop(); //Get last two operands in stack
			Expression* operand1 = s.pop();
			if (operand1 == NULL || operand2 == NULL){
				delete operand1;
				delete operand2;
				operand1 = NULL;
				operand2 = NULL;
			}
			Expression* binaryExp = new BinaryExpression(operand1, operand2, temp[0]);
			s.push(binaryExp); //Push new expression to stack
		}

		else{
			istringstream convertToInt(temp);
			int num;
			convertToInt >> num; //Convert string to int

			if( !convertToInt.fail() ){ //Only push if actually an int
				Expression* numberExp = new NumberExpression(num);
				s.push(numberExp); //Push new number to stack
			}
			convertToInt.clear();
		}

	}

	Expression* infix = s.pop(); //Pop last item on stack
	infix->prettyPrint(); //Call its print method

	int finalValue = infix->evaluate(); //Call its evaluate method
	cout << "\n= " << finalValue << endl;

	delete infix; //Deallocate the remaining node from freestore
	infix = NULL;
}

//This method will build a Postfix expression from stdin
string buildPostfix(){
	stringstream buffer; //buffer stream
	string temp; //temporary storage of a string
	string postfix;

	while(getline(cin,temp)){ //put stdin into buffer
		buffer << temp;
	}

	while(buffer >> temp){ //this process will remove any unnecessary whitespace
		postfix += temp; //build postfix sans whitespace
		postfix += " "; //add single whitespace
	}

	return postfix;
}
