#include <PmergeMe.hpp>
#include <exception>
#include <iostream>

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " space_separated_positive_ints" << std::endl;
    return 1;
  }
  try {
    PmergeMe fjs(argc, argv);
    fjs.sort();
    fjs.displayResults();
  } catch(std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  return 0;
}
