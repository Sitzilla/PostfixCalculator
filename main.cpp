#include "linkedlist.h"
#include "stack.h"
#include "tokenizer.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <math.h> 
#include <sstream>

using namespace std;


bool isNumber(string str) {
    // if ((str.find("1") != string::npos) || 
    //     (str.find("2") != string::npos) || 
    //     (str.find("3") != string::npos) || 
    //     (str.find("4") != string::npos) ||
    //     (str.find("5") != string::npos) || 
    //     (str.find("6") != string::npos) || 
    //     (str.find("7") != string::npos) || 
    //     (str.find("8") != string::npos) || 
    //     (str.find("9") != string::npos) || 
    //     (str.find("0") != string::npos)) {
    //     return true;
    // }
// return false;

    istringstream iss(str);
    float f;
    iss >> noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail(); 
}

bool isOperator(string str) {
    if ((str.find("-") != string::npos) || 
        (str.find("+") != string::npos) || 
        (str.find("*") != string::npos) || 
        (str.find("/") != string::npos) ||
        (str.find("^") != string::npos)) {
        return true;
    }
    return false;
}

float performOperation(float value1, float value2, string op) {

    if (op == "+") {
        return value1 + value2;
    } else if (op == "-") {
        return value1 - value2;
    } else if (op == "*") {
        return value1 * value2;
    } else if (op == "/") {
        return value1 / value2;
    } else if (op == "^") {
        return pow(value1, value2);
    }
    return 0;
}

bool firstIsLetter(string str) {
    int firstChar;

    // Checks User Input
    firstChar = static_cast<int>(str[0]); 

    if ((firstChar >= 65 && firstChar <= 90) || (firstChar >= 97 && firstChar <= 122)) {
        return true;
    }
    return false;
}

void calculatePostfixExpression(string input, Tokenizer tokenizer, string token, Stack &numberStack, LinkedList mainList) {
    while(tokenizer.nextToken(token)) {

        if (isNumber(token)) {
            numberStack.push(stof(token));
            
        } else if (isOperator(token)) {

            float firstfloat = numberStack.pop();
            float secondfloat = numberStack.pop();

            float answer = performOperation(secondfloat, firstfloat, token);
            numberStack.push(answer);

        } else if (firstIsLetter(token)) {
            numberStack.push(mainList.get(token[0]));
        }
    }
}

int main() {

    string printCommand = "?";
    string quitCommand = "quit";
    

    LinkedList mainList;

    cout << "Welcome to the PostFix calc!" << endl;
    while (true) {

        while (true) {
            string input;
            Tokenizer tokenizer;
            string token;
            char symbol;
            Stack numberStack;

            cout << "Enter calculation..." << endl;
            getline(cin, input);

            if(input == printCommand) {
                mainList.print();
            }
            else if(input == quitCommand) {
                exit(0);                  
            }
            else if (input.find("=") == string::npos) {
                tokenizer.tokenize(input);

                calculatePostfixExpression(input, tokenizer, token, numberStack, mainList);
                if (numberStack.size() == 1 ) {
                    cout << numberStack.pop() << endl;
                } else {
                    cout << "Error in calculation." << endl;
                }
            }

            //MAIN FUNCTION
            else {

                if (input[1] != ' ') {
                    cout << "Need to have spaces between all independent values and variables can only be one character" << endl;
                    break;
                } 

                if (firstIsLetter(input)) {

                    tokenizer.tokenize(input);
                    
                    tokenizer.nextToken(token);
                    symbol = token[0];

                    tokenizer.nextToken(token);

                    // cout << "TOKEN: " << token << endl;
                    if (token != "=") {
                        cout << "Incorrect assignment";
                        break;
                    }

                    // Does Calculations!
                    calculatePostfixExpression(input, tokenizer, token, numberStack, mainList);

                    if (numberStack.size() == 1 ) {
                        float answer = numberStack.pop();
                        mainList.append(symbol, answer);
                        cout << answer << endl;

                    } else {
                        cout << "Error in calculation.";

                    }
                }
            }
        }
    }
}