#pragma once

#include <string>

class ScalarConverter {
  public:
    // Canonical Form
    ScalarConverter();
    virtual ~ScalarConverter() = 0;
    ScalarConverter& operator=(ScalarConverter& other);
    ScalarConverter(ScalarConverter& other);
  
    // Special members
    static void convert(std::string& source);
};
