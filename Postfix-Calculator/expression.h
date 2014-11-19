#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

#include <string>
#include <iostream>
#include <cstdlib>

//Expression class used for abstraction
class Expression{
	public:
		//Pure Virtual Methods
		virtual void prettyPrint() = 0; 
		virtual int evaluate() = 0;
		//Virtual Destructor
		virtual ~Expression();
};

//Concrete class used for number expressions
class NumberExpression : public Expression{
		int number; //Only single lone number in expression
	public:
		void prettyPrint();
		int evaluate();
		NumberExpression(int number); //Constructor
		~NumberExpression(); //Destructor
};

//Concrete class used for unary expressions
class UnaryExpression : public Expression{
		Expression* operand;
		std::string op; //must be string "NEG" or "ABS"
	public:
		void prettyPrint();
		int evaluate();
		UnaryExpression(Expression* operand, std::string op); //Constructor
		~UnaryExpression(); //Destructor
};

//Concrete class used for binary expressions
class BinaryExpression : public Expression{
		Expression* operand1; //Expression operands will facilitate cascading operations
		Expression* operand2; //( ex. (4+5)+6 )
		char op;
	public:
		void prettyPrint();
		int evaluate();
		BinaryExpression(Expression* operand1, Expression* operand2, char op); //Constructor
		~BinaryExpression(); //Destructor
};

#endif
