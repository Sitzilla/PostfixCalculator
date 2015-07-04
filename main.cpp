#include "linkedlist.h"
#include "stack.h"
#include "mathutils.h"
#include "tokenizer.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void calculatePostfixExpression(string input, Tokenizer tokenizer, string token, Stack &numberStack, LinkedList mainList) {
    while(tokenizer.nextToken(token)) {

        if (MathUtils::isFloat(token)) {
            numberStack.push(stof(token));
            
        } else if (MathUtils::isOperator(token)) {

            if (numberStack.size() < 2) {
                numberStack.clear();
                return;
            }

            float firstfloat = numberStack.pop();
            float secondfloat = numberStack.pop();
            bool legalAnswer = true;
            float answer = MathUtils::performOperation(secondfloat, firstfloat, token, legalAnswer);

            if (legalAnswer == false) {
                cout << "Cannot divide by zero." << endl;
                numberStack.clear();
                return;
            }
            numberStack.push(answer);

        } else if (MathUtils::isLetter(token)) {
            numberStack.push(mainList.get(token[0]));
        }
    }
}

bool popAnswer(Stack &numberStack, float &answer) {
    if (numberStack.size() == 1) {
        answer = numberStack.pop();
        cout << answer << endl;
        return true;
    } else {
        cout << "Error in calculation." << endl;
        return false;
    }
}

int main() {

    string printCommand = "?";
    string quitCommand = "quit";
    
    LinkedList mainList;
    // MathUtils mathutils;

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
                cout << "Current variables assigned:" << endl;
                mainList.print();
            }
            else if(input == quitCommand) {
                exit(0);                  
            }
            // Non-Assignment Calculation
            else if (input.find("=") == string::npos) {
                tokenizer.tokenize(input);

                // Does calculation on float/operator tokens in the input string
                calculatePostfixExpression(input, tokenizer, token, numberStack, mainList);
                float answer;
                popAnswer(numberStack, answer);               
            }
            // Assignment Calculation
            else {

                if (MathUtils::isLegalAssignment(input)) {

                    // Remove variable and equals sign from the input string
                    tokenizer.tokenize(input);
                    
                    tokenizer.nextToken(token);
                    symbol = token[0];

                    tokenizer.nextToken(token);

                    // Does calculation on float/operator tokens in the input string
                    calculatePostfixExpression(input, tokenizer, token, numberStack, mainList);
                    float answer;
                    bool legalAnswer = popAnswer(numberStack, answer);

                    if (legalAnswer) {
                        mainList.set(symbol, answer);
                    }
                } else {
                        cout << "Error in assignment statement." << endl;
                }
            }
        }
    }
}