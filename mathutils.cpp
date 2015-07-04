#include <stdlib.h>
#include <iomanip>
#include <string>
#include <math.h> 
#include <sstream>
#include "mathutils.h"

using namespace std;

MathUtils::MathUtils() {}

bool MathUtils::isFloat(string str) {
    istringstream iss(str);
    float f;
    iss >> noskipws >> f;
    return iss.eof() && !iss.fail(); 
}

bool MathUtils::isOperator(string str) {
    if ((str.find("-") != string::npos) || 
        (str.find("+") != string::npos) || 
        (str.find("*") != string::npos) || 
        (str.find("/") != string::npos) ||
        (str.find("^") != string::npos)) {
        return true;
    }
    return false;
}

float MathUtils::performOperation(float value1, float value2, string op, bool &legalAnswer) {

    if (op == "+") {
        return value1 + value2;
    } else if (op == "-") {
        return value1 - value2;
    } else if (op == "*") {
        return value1 * value2;
    } else if (op == "/") {
        if (value2 == 0) {
            legalAnswer = false;
            return 0;
        }
        return value1 / value2;
    } else if (op == "^") {
        return pow(value1, value2);
    }
    return 0;
}

bool MathUtils::isLetter(string str) {
    if (firstIsLetter(str) && str.length() == 1) {
        return true;
    }
    return false;
}

bool MathUtils::isLegalAssignment(string input) {
    if (!firstIsLetter(input)) {
        return false;
    } else if (!secondAndFourthAreSpace(input)) {
        return false;
    } else if (!thirdIsEquals(input)) {
        return false;
    }
    return true;
}

bool MathUtils::firstIsLetter(string str) {
    int firstChar;

    firstChar = static_cast<int>(str[0]); 

    if ((firstChar >= 65 && firstChar <= 90) || (firstChar >= 97 && firstChar <= 122)) {
        return true;
    }
    return false;
}

bool MathUtils::secondAndFourthAreSpace(string str) {
    int secondChar;
    int fourthChar;

    secondChar = static_cast<int>(str[1]); 
    fourthChar = static_cast<int>(str[3]); 

    if (secondChar == ' ' && fourthChar == ' ') {
        return true;
    }
    return false;
}

bool MathUtils::thirdIsEquals(string str) {
    int thirdChar;

    thirdChar = static_cast<int>(str[2]); 

    if (thirdChar != '=') {
        return false;
    }
    return true;
}