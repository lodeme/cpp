#pragma once

#include <string>

enum inferredType {
  CHAR,
  ERROR,
};

class ScalarConverter {
  private:
    // Type inference
    static inferredType inferType(std::string& literal);
 
    // Type conversion
    static char toChar(std::string& literal);
  
    // Display
    static void printConversions();

  public:
    // Canonical Form
    ScalarConverter();
    virtual ~ScalarConverter() = 0;
    ScalarConverter& operator=(ScalarConverter& other);
    ScalarConverter(ScalarConverter& other);

    // Type conversion
    static void convert(std::string& literal);
};

