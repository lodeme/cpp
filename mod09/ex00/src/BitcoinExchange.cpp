#include <BitcoinExchange.hpp>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <fstream>

BitcoinExchange::BitcoinExchange() {
  loadPriceData();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): priceData(other.priceData) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		*this = other;
	return *this;
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

std::string BitcoinExchange::trimWhitespace(const std::string& str) {
  const char* whitespace = " \t\v\r\n";
  size_t start = str.find_first_not_of(whitespace);
  size_t end = str.find_last_not_of(whitespace);

  return start == std::string::npos ? std::string() : str.substr(start, end - start + 1);
}

bool BitcoinExchange::isValidDate(std::string& date) {
  if (date.length() != 10)
    throw std::invalid_argument("bad input => " + date);

  if (date[4] != '-' || date[7] != '-')
    return false;

  for (int i = 0; i < 10; i++) {
    if (i == 4 || i == 7)
      continue;
    if (date[i] < '0' || date[i] > '9')
      return false;
  }

  int year = atoi(date.substr(0, 4).c_str());
  int month = atoi(date.substr(5, 2).c_str());
  int day = atoi(date.substr(8, 2).c_str());

  if (month < 1 || month > 12)
    return false;
  if (day < 1 || day > 31)
    return false;
  if (month == 4 || month == 6 || month == 9 || month == 11) {
      if (day > 30)
        return false;
  }
  if (month == 2) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
      if (day > 29)
        return false;
    } else {
      if (day > 28)
        return false;
    }
  }
  return true;
}

bool BitcoinExchange::isValidValue(std::string& value) {
  char* end;
  double v = strtod(value.c_str(), &end);

  if (*end != '\0')
    return false;
  if (v < 0)
    throw std::invalid_argument("not a positive number");
  if (v > 1000)
    throw std::invalid_argument("too large a number");
  return true;
}

