#pragma once

#include <string>
#include <map>

class BitcoinExchange {
  private:
    std::map<std::string, double> priceData;
    bool isValidDate(std::string& date);
    bool isValidValue(std::string& value);
    std::string trimWhitespace(const std::string& str);
    void loadPriceData();
    void parseInputLine(std::string& line);

  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    void parseInputFile(const std::string& file);
};
