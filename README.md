# PostfixCalculator
Homework assignment from Programming Foundations II. Problem statement found at:
http://csce.uark.edu/~lbg002/csce2014/homework/homework-3-postfix-calculator/

Problem statement for assignment:

A postfix calculator is a calculator that accepts an expression with the operator after the operands. Here are a few examples:

Expression | Postfix Expression | Value

  2 + 3    |       2 3 +        |   5
  
  8 – 12   |	     8 12 –	      |  -4
  
  4 * 9    |	     4 9 *	      |  36
  
  7 / 10   |	     7 10 /       |	 0.7 (assuming float division)
  
The goal of this programming project is to implement a postfix calculator that allows the user to define and reuse variables in their calculations. For example, if the user types in “A = 2 3 +” the value 5 will be stored in variable A. If they then type in “B = A 6 *” the value 30 will be stored in B.

This assignment consists two main parts. First, you must use a linked list to create a symbol table that contains the current value of all variables that have been defined. Second, you must use a stack to store and evaluate postfix expressions.
