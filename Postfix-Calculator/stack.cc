/* STACK IMPLEMENTATION FILE */

#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

Stack::Stack():stackSize(10){ //Stack size is 10
        top = -1; //Currently empty stack
        items = new Expression*[stackSize];
}

Stack::~Stack(){ //Destructor
        delete[] items;
        items = NULL;
}

void Stack::push(Expression* exp){ //Push next into stack
        items[++top] = exp;
}

Expression* Stack::pop(){ //Pop one from stack
        if(top > -1 ) return items[top--];
        else return NULL;
}

bool Stack::isFull(){ //Checks to see if stack is full
        if (top + 1 == stackSize) return true;
        else return false;
}

bool Stack::isEmpty(){ //Checks to see if stack is empty
        if (top == -1) return true;
        else return false;
}

