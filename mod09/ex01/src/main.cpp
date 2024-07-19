#include <RPN.hpp>
#include <exception>
#include <iostream>

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " expression" << std::endl;
    return 1;
  }
  try {
    RPN calc;
    int res = calc.calculate(argv[1]);
    std::cout << "Result: " << res << std::endl;
  } catch (std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  return 0;
}
