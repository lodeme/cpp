#pragma once

#include <string>

enum inferredType {
  CHAR,
  INT,
  FLOAT,
  DOUBLE,
};

class ScalarConverter {
  private:
    // Private constructor for non instantiable class
    ScalarConverter();

    // Type inference
    static bool isChar(std::string& literal);
    static bool isInt(std::string& literal);
    static bool isFloat(std::string& literal);
    static bool isDouble(std::string& literal);
    static inferredType inferType(std::string& literal);
 
    // Type conversion
    static char toChar(std::string& literal);
    static int toInt(std::string& literal);
    static float toFloat(std::string& literal);
    static double toDouble(std::string& literal);
  
    // Display
    static void printConversions(double d);

  public:
    // Type conversion
    static void convert(std::string& literal);
};

