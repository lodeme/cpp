#include <ScalarConverter.hpp>
#include <iostream>

int main (int argc, char *argv[]) {

  if (argc != 2) {
    std::cerr << "Error: Only one argument expected" << std::endl;
    return 1;
  }
  try {
    std::string literal = argv[1];
    ScalarConverter::convert(literal);
  }
  catch (const std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return 0;
}
