#include <iostream>
#include <string>
#include <cstdlib>
#include "expression.h"

using namespace std;

/* Abstract Non-Virtual Method Definitions */
Expression::~Expression(){} //Destructor

/* NumberExpression Definitions */
void NumberExpression::prettyPrint(){ //Prints integer
	cout << this->number;
}

int NumberExpression::evaluate(){ //Returns integer
	return this->number;
}

NumberExpression::NumberExpression(int number):number(number){} //Constructor

NumberExpression::~NumberExpression(){} //Destructor

/* UnaryExpression Definitions */
void UnaryExpression::prettyPrint(){ //Prints unary operation
	if (this->op == "NEG"){
		cout << "-"; 
		(this->operand)->prettyPrint();
	}
	else if (this->op == "ABS"){
		cout << "|";
		(this->operand)->prettyPrint();
		cout << "|";
	}
}

int UnaryExpression::evaluate(){ //Returns unary operation
	if (this->op == "NEG")
		return ( -1 * (this->operand)->evaluate() );
	else if (this->op == "ABS")
		return abs( (this->operand)->evaluate() );
	else 
		return -1;
}

//Constructor
UnaryExpression::UnaryExpression(Expression* operand, string op):operand(operand), op(op) {}

UnaryExpression::~UnaryExpression(){ //Destructor
	delete this->operand;
	this->operand = NULL;
}

/* BinaryExpression Definition */
void BinaryExpression::prettyPrint(){ //Prints binary operation
	cout << "(";
	(this->operand1)->prettyPrint();
	cout << " " << this->op << " ";
	(this->operand2)->prettyPrint();
	cout << ")";
}

int BinaryExpression::evaluate(){ //Performs binary operator
	switch(this->op){
		case '+':{
			return (this->operand1)->evaluate() + (this->operand2)->evaluate();
		}

		case '-':{
			return (this->operand1)->evaluate() - (this->operand2)->evaluate();
		}

		case '*':{
			return (this->operand1)->evaluate() * (this->operand2)->evaluate();
		}

		case '/':{
			return (this->operand1)->evaluate() / (this->operand2)->evaluate();
		}
	}
	return -1;
}

//Constructor
BinaryExpression::BinaryExpression(Expression* operand1, Expression* operand2, char op)
	:operand1(operand1), operand2(operand2), op(op) {}

BinaryExpression::~BinaryExpression(){ //Destructor
	delete this->operand1;
	this->operand1 = NULL;
	delete this->operand2;
	this->operand2 = NULL;
}
