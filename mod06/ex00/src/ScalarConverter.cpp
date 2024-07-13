#include <ScalarConverter.hpp>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& other) {
  (void)other;
  return *this;
}

ScalarConverter::ScalarConverter(ScalarConverter& other) {
  *this = other;
}
