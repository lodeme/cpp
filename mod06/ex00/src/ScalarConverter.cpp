#include <ScalarConverter.hpp>
#include <iostream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& other) {
  (void)other;
  return *this;
}

ScalarConverter::ScalarConverter(ScalarConverter& other) {
  *this = other;
}

void ScalarConverter::convert(std::string& literal) {
  switch (inferType(literal)) {
    case CHAR: {
      char c = toChar(literal);
      printConversions(c);
      break;
    }
    case ERROR: {
      std::cout << "Error: type conversion failed" << std::endl;
    }
  }
}

