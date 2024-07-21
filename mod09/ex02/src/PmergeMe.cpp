#include <PmergeMe.hpp>
#include <algorithm>
#include <cstddef>
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <iostream>

// Constructors and destructors
PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(int argc, char** argv) {
  parseInput(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe& other)
  : _numbersInput(other._numbersInput), _list(other._list), _vector(other._vector), _listTime(other._listTime), _vectorTime(other._vectorTime) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  if (this != &other) {
    _numbersInput = other._numbersInput;
    _list = other._list;
    _vector = other._vector;
    _listTime = other._listTime;
    _vectorTime = other._vectorTime;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

// private functions
void PmergeMe::parseInput(int argc, char** argv) {
  int num;
  for (int i = 1; i < argc; i++) {
    std::istringstream iss(argv[i]);
    if (!(iss >> num) || num < 0)
      throw std::invalid_argument("invalid argument: " + std::string(argv[i]));
  _numbersInput.push_back(num);
  _list.push_back(num);
  _vector.push_back(num);
  }
}

void PmergeMe::sort() {
  clock_t start = clock();
  FordJohnsonListSort();
  _listTime = clock() - start;

  start = clock();
  FordJohsonVectorSort();
  _vectorTime = clock() - start;
}

void PmergeMe::displayResults() {
  std::cout << "Before: ";
  for (size_t i = 0; i < _numbersInput.size(); i++) {
    std::cout << _numbersInput.front() << " ";
    _numbersInput.pop_front();
  }
  std::cout << std::endl;

  std::cout << "After: ";
  for (size_t i = 0; i < _vector.size(); i++) {
    std::cout << _vector[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "Time to process a range of " << _vector.size() << " elements with std::list<int> : "
    << std::fixed << std::setprecision(5) << static_cast<double>(_listTime) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;
  std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector<int> : "
    << std::fixed << std::setprecision(5) << static_cast<double>(_vectorTime) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;
}

void PmergeMe::FordJohsonVectorSort() {
  if (_vector.size() <= 1)
    return;

  for (size_t i = 0; i < _vector.size() - 1; i+=2) {
    if (_vector[i] > _vector[i + 1])
      std::swap(_vector[i], _vector[i + 1]);
  }

  std::vector<int> bigger;
  for (size_t i = 1; i < _vector.size(); i+=2)
    bigger.push_back(_vector[i]);

  FordJohsonVectorSort(bigger);

  _vector.clear();
  size_t j = 0;
  for (size_t i = 0; i < bigger.size(); i++) {
    _vector.push_back(bigger[i]);
    if (i * 2 < _vector.size() - 1) {
      std::vector<int>::iterator it = std::lower_bound(arr.begin(), arr.end(), _vector[i * 2]);
    }
  }

}
