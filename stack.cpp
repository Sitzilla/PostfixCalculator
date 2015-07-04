/*
 * File:	stack.cpp
 * Author:	Luke Godfrey
 */

#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack()
{
}

void Stack::push(float x)
{
	elements.push_back(x);
}

float Stack::pop()
{
	float x = elements[size() - 1];
	elements.pop_back();
	return x;
}

float Stack::top() const
{
	return elements[size() - 1];
}

int Stack::size() const
{
	return elements.size();
}

void Stack::print() const
{
	// print backwards so it looks like the stack actually looks
	for(int i = size() - 1; i >= 0; i--)
	{
		cout << elements[i] << endl;
	}
}
