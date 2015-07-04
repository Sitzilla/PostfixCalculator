/*
 * File:	stack.h
 * Author:	Luke Godfrey
 */

#ifndef STACK_H
#define STACK_H

#include <vector>
using namespace std;

class Stack
{
	public:
		Stack();
		void push(float x);
		float pop();
		float top() const;
		int size() const;
		void print() const;
	private:
		vector<float> elements;
};

#endif
