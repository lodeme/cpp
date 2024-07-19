#pragma once

#include <string>
#include <map>

class BitcoinExchange {
  private:
    std::map<std::string, double> priceData;
    bool isValidDate(std::string& date);
    bool isValidValue(std::string& value);
    std::string trimWhitespace(std::string& str);

  public:
    BitcoinExchange(const std::string& file);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void parseInputFile(const std::string& file);
    void parseInputLine(std::string& line);
};
