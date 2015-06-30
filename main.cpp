#include "linkedlist.h"
#include "userinput.h"
#include <iostream>
#include <string>
using namespace std;


int main() {

    LinkedList mainList;
    UserInput userInput;

    userInput.setUserInput();

    if (userInput.stringIsAssignment()) {

        // if expression contains an operator
        if (userInput.stringContainsOperator(userInput.stringAfterAssignment())) {
            cout << "operator";
        } else {

            cout << "no operator";
        }
        
    }


}