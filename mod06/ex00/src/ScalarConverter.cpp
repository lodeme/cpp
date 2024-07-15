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
    !std::isdigit(literal[0])
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
  std::string truncFloat = literal.substr(0, literal.size() - 1);
  return isDouble(truncFloat);
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
  if (*end != 'f')
    throw std::invalid_argument("Number could not be converted to a float");

  return result;
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
  double result = strtod(literal.c_str(), &end);

  if (errno == ERANGE)
    throw std::out_of_range("Out of double range");
  if (*end != '\0')
    throw std::invalid_argument("Number could not be converted to a double");

  return result;
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
      float f = toFloat(literal);
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
  std::cout << "char: "
    << (std::isprint(static_cast<int>(d))
    ? ("'" + std::string(1, static_cast<char>(d)) + "'")
    : std::isnan(d) || std::isinf(d) || d > 127 || d < 0
    ? "impossible"
    : "non displayable")
    << std::endl;

  std::cout << "int: ";
  if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || std::isnan(d) || std::isinf(d))
    std::cout << "impossible" << std::endl;
  else
    std::cout << static_cast<int>(d) << std::endl;

  std::cout << "float: ";
  if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
    std::cout << "impossible" << std::endl;
  else if (abs(d - std::round(d)) > 0.0f || isinf(d) || isnan(d))
    std::cout << static_cast<float>(d) << "f" << std::endl;
  else
    std::cout << static_cast<float>(d) << ".0f" << std::endl;

  std::cout << "double: ";
  if (abs(d - std::round(d)) > 0.0 ||isinf(d) || isnan(d))
    std::cout << d << std::endl;
  else
    std::cout << d << ".0" << std::endl;
}
