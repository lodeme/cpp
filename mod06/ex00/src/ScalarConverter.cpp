#include <ScalarConverter.hpp>
#include <iostream>
#include <climits>
#include <cerrno>
#include <stdexcept>

// Canonical Form
ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& other) {
  (void)other;
  return *this;
}

ScalarConverter::ScalarConverter(ScalarConverter& other) {
  *this = other;
}

// Type inference

bool ScalarConverter::isInt(std::string& literal) {
  return false;
}

bool ScalarConverter::isFloat(std::string& literal) {
  return false;
}

bool ScalarConverter::isDouble(std::string& literal) {
  return false;
}

inferredType ScalarConverter::inferType(std::string& literal) {
  if (literal.empty())
    return ERROR;

  if (literal.length() == 1 &&
    literal[0] >= 0 && literal[0] <= 127 &&
    (literal[0] < '0' || literal[0] > '9'))
    return CHAR;

  if (literal == "nanf" || literal == "+inff" || literal == "-inff")
    return FLOAT;

  if (literal == "nan" || literal == "+inf" || literal == "-inf")
    return DOUBLE;

  if (isInt(literal))
    return INT;

  if (isFloat(literal))
      return FLOAT;

  if (isDouble(literal))
    return DOUBLE;

  return ERROR;
}

// Conversions
char ScalarConverter::toChar(std::string& literal) {
  
}

int ScalarConverter::toInt(std::string& literal) {
  errno = 0;
  char *end;
  long result = strtol(literal.c_str(), &end, 10);

  if (errno == ERANGE || result < INT_MIN || result > INT_MAX)
    throw std::out_of_range("Out of int range");
  if (*end != '\0')
    throw std::invalid_argument("Number could not be converted to an int");

  return static_cast<int>(result);
}


float ScalarConverter::toFloat(std::string& literal) {

}

double ScalarConverter::toDouble(std::string& literal) {

}

void ScalarConverter::convert(std::string& literal) {
  switch (inferType(literal)) {
    case CHAR: {
      char c = toChar(literal);
      printConversions(static_cast<double>(c));
      break;
    }
    case INT: {
      int i = toInt(literal);
      printConversions(static_cast<double>(i));
      break;
    }
    case ERROR: {
      std::cout << "Error: type conversion failed" << std::endl;
    }
  }
}

// Display
static void printConversions(double d) {
  std::cout << "char: " << static_cast<char>(d) << std::endl;
  std::cout << "int: " << static_cast<int>(d) << std::endl;
  std::cout << "float: " << static_cast<float>(d) << std::endl;
  std::cout << "double: " << d << std::endl;
}
