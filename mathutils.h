#ifndef MATHUTILS_H
#define MATHUTILS_H

#include <string>

using namespace std;

class MathUtils {
    public:
        MathUtils();

        static bool isFloat(string str);
        static bool isOperator(string str);
        static float performOperation(float value1, float value2, string op, bool &legalAnswer);
        static bool isLetter(string str);
        static bool isLegalAssignment(string input);
        static bool firstIsLetter(string str);
        static bool secondAndFourthAreSpace(string str);
        static bool thirdIsEquals(string str);
};

#endif

