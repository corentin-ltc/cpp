#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <stdlib.h>
#include <stdexcept>

class RPN
{
    public:
        static int evaluate(const std::string& expression);

    private:
        RPN();
        static bool isOperator(const std::string& token);
        static bool isNumber(const std::string& token);
        static int applyOperator(int a, int b, const std::string& op);
};

