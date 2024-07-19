#include <RPN.hpp>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

RPN::RPN() {};

RPN::RPN(const RPN& other) {
  (void)other;
};

RPN& RPN::operator=(const RPN& other) {
  (void)other;
  return *this;
};

RPN::~RPN() {};

int RPN::calculate(const std::string& expression) {
  std::istringstream iss(expression);
  std::string token;
  std::stack<int> stack;

  while (iss >> token) {
    if (isOperator(token) && stack.size() >= 2) {
      int b = stack.top();
      stack.pop();
      int a = stack.top();
      stack.pop();
      int result = performOperation(a, b, token);
      stack.push(result);
    }
    else if (!isOperator(token)) {
      char* endptr;
      int num = std::strtol(token.c_str(), &endptr, 10);

      if (*endptr != '\0' || num >= 10)
        throw std::invalid_argument("invalid number: " + token);

      stack.push(num);
    }
  }

  if (stack.size() != 1)
    throw std::invalid_argument("incorrect combination of operators and operands");

  return stack.top();
};

bool RPN::isOperator(std::string& token) {
  return token == "-" || token == "+" || token == "*" || token == "/";
}

int RPN::performOperation(int a, int b, std::string token) {
  if (token == "-")
    return a - b;
  else if (token == "+")
    return a + b;
  else if (token == "*")
    return a * b;
  else {
    if (b == 0)
      throw std::logic_error("cannot divide by 0");
    return a / b;
  }
}
