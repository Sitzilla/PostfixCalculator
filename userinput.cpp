#include "userinput.h"
#include <iostream>
#include <string>

using namespace std;

UserInput::UserInput() {
    userInput = "";
}

void UserInput::setUserInput() {
    cout << "Please type in a command\n";
    
    getline(cin, userInput);
}

bool UserInput::stringIsAssignment() {
    // If contains '=' for assignent
    if (userInput.find("=") != string::npos) {
        return true;
    }
    return false;
}

bool UserInput::stringContainsOperator(string input) {
    // If contains '=' for assignent
    if ((input.find("+") != string::npos) || (input.find("-") != string::npos) || (input.find("*") != string::npos) || (input.find("/") != string::npos)) {
        return true;
    }
    return false;
}


string UserInput::stringAfterAssignment() {
    return userInput.substr(4, userInput.length());
}

bool UserInput::isLegalAssignment() {
    int firstChar;

    // Checks User Input
    firstChar = static_cast<int>(userInput[0]); 

    if ((firstChar >= 65 && firstChar <= 90) || (firstChar >= 97 && firstChar <= 122)) {
        return true;
    }
    return false;
}