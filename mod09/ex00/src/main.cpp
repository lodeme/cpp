#include <BitcoinExchange.hpp>
#include <iostream>

int main(int argc, char** argv) {
// multiple times the same date
  // nnothing at all
  // line with one value and no separator
  // just a separator
  // invalid dates
  // invalid values
  // date to small
  // date too big
  // date on a weekend
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " filepath" << std::endl;
    return 1;
  }
  try {
    BitcoinExchange btc;
    btc.parseInputFile("test");
  } catch(std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  return 0;
}
