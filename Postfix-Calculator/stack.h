/* STACK HEADER FILE */

#ifndef __STACK_H_
#define __STACK_H_

#include <iostream>
#include "expression.h"

class Stack{
	const int stackSize;
	int top;
	Expression** items;
public:
	Stack();
	~Stack();
	void push(Expression* exp);
	Expression* pop();
	bool isFull();
	bool isEmpty();
};

#endif
