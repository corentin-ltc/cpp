#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &other){ (void)other; }
RPN& RPN::operator=(const RPN &other) { (void)other; return (*this); }
RPN::~RPN() {}

int RPN::evaluate(const std::string& expression)
    {
        std::stack<int> stack;
        std::istringstream iss(expression);
        std::string token;

        while (iss >> token)
        {
            // std::cout << "token = " << token << std::endl;
            if (isOperator(token))
            {
                if (stack.size() < 2)
                    throw std::runtime_error("Error: Insufficient operands.");

                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();
                
                stack.push(applyOperator(a, b, token));
            }
            else if (isNumber(token))
            {
                stack.push(atoi(token.c_str()));
            }
            else
            {
                throw std::runtime_error("Error: Invalid token.");
            }
        }

        if (stack.size() != 1)
            throw std::runtime_error("Error: Invalid expression.");

        return stack.top();
    }

bool RPN::isOperator(const std::string& token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isNumber(const std::string& token)
{
    if (token.empty())
        return false;
    for (std::size_t i = 0; i < token.size(); ++i)
    {
        if (!std::isdigit(token[i]))
            return false;
    }
    return true;
}

int RPN::applyOperator(int a, int b, const std::string& op)
{
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    else if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("Error: Division by zero.");
        return a / b;
    }
    throw std::runtime_error("Error: Unknown operator.");
}

