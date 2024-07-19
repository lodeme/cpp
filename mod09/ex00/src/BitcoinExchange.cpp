#include <BitcoinExchange.hpp>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <fstream>

BitcoinExchange::BitcoinExchange(const std::string& file) {
  loadPriceData();
  parseInputFile(file);
}

void BitcoinExchange::loadPriceData() {
  std::ifstream inputFile("data.csv");
  std::string line;

  std::getline(inputFile, line);

  while (std::getline(inputFile, line)) {
    std::istringstream iss(line);
    std::string date;
    std::string value;

    if (std::getline(iss, date, ',') && std::getline(iss, value))
      priceData[date] = std::stod(value);
  }
}

void BitcoinExchange::parseInputFile(const std::string& file) {
  std::ifstream inputFile(file);
  std::string line;

  std::getline(inputFile, line);

  while (std::getline(inputFile, line)) {
    try {
      parseInputLine(line);
    } catch (std::exception& e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }
}

void BitcoinExchange::parseInputLine(std::string& line) {
    std::istringstream iss(line);
    std::string date;
    std::string quantity;

  if (!std::getline(iss, date, '|'))
    throw std::invalid_argument("bad input => " + line );
  else if (!std::getline(iss, quantity))
    throw std::invalid_argument("bad input => " + line);

  date = trimWhitespace(date);
  quantity = trimWhitespace(quantity);

  if (isValidDate(date) && isValidValue(quantity)) {
    double btcQuantity = std::atof(quantity.c_str());
    std::map<std::string, double>::iterator it = priceData.upper_bound(date);

    if (it != priceData.begin()) {
      it--;
      double exchangeRate = it->second;
      std::cout << date << " => " << quantity << " = " << (btcQuantity * exchangeRate) << std::endl;
    } else
      throw std::invalid_argument("bad input => " + line);
  } else
    throw std::invalid_argument("bad input => " + line);
}

std::string trimWhitespace(const std::string& str) {
  const char* whitespace = " \t\v\r\n";
  size_t start = str.find_first_not_of(whitespace);
  size_t end = str.find_last_not_of(whitespace);

  return start == end ? std::string() : str.substr(start, end - start + 1);
}
