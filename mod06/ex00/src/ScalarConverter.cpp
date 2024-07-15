#include <ScalarConverter.hpp>
#include <cctype>
#include <iostream>
#include <climits>
#include <cerrno>
#include <limits>
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
bool ScalarConverter::isChar(std::string& literal) {
  if (literal.length() == 1 &&
    literal[0] >= 0 && literal[0] <= 127 &&
    std::isdigit(literal[0])
  )
    return true;
  return false;
}

bool ScalarConverter::isInt(std::string& literal) {
  size_t i = 0;
  if (literal[i] == '-' || literal[i] == '+')
    i++;
  return literal.find_first_not_of("0123456789", i) == std::string::npos;
}

bool ScalarConverter::isFloat(std::string& literal) {
  if (literal == "nanf" || literal == "+inff" || literal == "-inff")
    return true;
  if (literal.back() != 'f')
      return false;
  return isDouble(literal);
}

bool ScalarConverter::isDouble(std::string& literal) {
  if (literal == "nan" || literal == "+inf" || literal == "-inf")
    return true;
  
  size_t i = 0;
  if (literal[i] == '-' || literal[i] == '+')
    i++;

  bool hasDigits = false;
  bool hasDecimalPoint = false;

  for (; i < literal.length(); i++) {
    if (std::isdigit(literal[i]))
      hasDigits = true;
    else if (literal[i] == '.' && !hasDecimalPoint)
      hasDecimalPoint = true;
    else
      return false;
  }

  return hasDigits;
}

inferredType ScalarConverter::inferType(std::string& literal) {
  if (literal.empty())
    throw std::invalid_argument("Input cannot be empty");

  if (isChar(literal))
    return CHAR;
  if (isInt(literal))
    return INT;
  if (isFloat(literal))
    return FLOAT;
  if (isDouble(literal))
    return DOUBLE;

  throw std::invalid_argument("Literal type could not be inferred");
}

// Conversions
char ScalarConverter::toChar(std::string& literal) {
  return literal[0];
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
  if (literal == "nanf")
    return std::numeric_limits<float>::quiet_NaN();
  if (literal == "+inff") 
    return std::numeric_limits<float>::infinity();
  if (literal == "-inff")
    return -std::numeric_limits<float>::infinity();

  errno = 0;
  char *end;
  float result = strtof(literal.c_str(), &end);

  if (errno == ERANGE)
    throw std::out_of_range("Out of float range");
  if (*end != '\0')
    throw std::invalid_argument("Number could not be converted to a float");

  return static_cast<float>(result);
}

double ScalarConverter::toDouble(std::string& literal) {
  if (literal == "nan")
    return std::numeric_limits<double>::quiet_NaN();
  if (literal == "+inf") 
    return std::numeric_limits<double>::infinity();
  if (literal == "-inf")
    return -std::numeric_limits<double>::infinity();

  errno = 0;
  char *end;
  float result = strtod(literal.c_str(), &end);

  if (errno == ERANGE)
    throw std::out_of_range("Out of double range");
  if (*end != '\0')
    throw std::invalid_argument("Number could not be converted to a double");

  return static_cast<double>(result);
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
    case FLOAT: {
      int f = toFloat(literal);
      printConversions(static_cast<double>(f));
      break;
    }
    case DOUBLE: {
      double d = toDouble(literal);
      printConversions(d);
      break;
    }
  }
}

// Display
void ScalarConverter::printConversions(double d) {
  std::cout << "char: " << static_cast<char>(d) << std::endl;
  std::cout << "int: " << static_cast<int>(d) << std::endl;
  std::cout << "float: " << static_cast<float>(d) << std::endl;
  std::cout << "double: " << d << std::endl;
}
