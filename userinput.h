#ifndef USERINPUT_H
#define USERINPUT_H

#include <string>
using namespace std;

class UserInput {

    public:
        UserInput();
        void setUserInput();
        bool stringIsAssignment();
        string stringAfterAssignment();
        bool stringContainsOperator(string input);
        bool isLegalAssignment();

    private:
        string userInput;

};

#endif
