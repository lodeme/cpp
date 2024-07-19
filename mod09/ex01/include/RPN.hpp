#pragma once

#include <string>

class RPN {
  private:
    bool isOperator(std::string& token);
    int performOperation(int a, int b, std::string token);

  public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    int calculate(const std::string& expression);
};
