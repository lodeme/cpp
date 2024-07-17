#include <Span.hpp>
#include <algorithm>
#include <limits>
#include <stdexcept>

// Constructors and destructors
Span::Span(): _size(0) {}

Span::~Span() {}

Span::Span(const Span& other): _size(other._size), _vec(other._vec) {}

Span& Span::operator=(const Span& other) {
  if (this != &other) {
    _size = other._size;
    _vec = other._vec;
  }
  return *this;
}

Span::Span(unsigned int size): _size(size) {}

// Member functions
void Span::addNumber(int n) {
  if (_vec.size() < _size)
    _vec.push_back(n);
  else
    throw std::out_of_range("vector reached maximum size");
}

unsigned int Span::longestSpan() {
  if (_vec.size() <= 1)
    throw std::runtime_error("cannot get span with less than two values");

  std::vector<int>::iterator min = std::min_element(_vec.begin(), _vec.end());
  std::vector<int>::iterator max = std::max_element(_vec.begin(), _vec.end());

  return *max - *min;
}

unsigned int Span::shortestSpan() {
  if (_vec.size() <= 1)
    throw std::runtime_error("cannot get span with less than two values");

  std::vector<int> sorted_vector = _vec;
  sort(sorted_vector.begin(), sorted_vector.end());

  unsigned int shortSpan = std::numeric_limits<unsigned int>::max();
  for (unsigned int i = 0; i < sorted_vector.size() - 1; i++) {
    unsigned int span = static_cast<unsigned int>(std::abs(sorted_vector[i] - sorted_vector[i + 1]));
    if (span < shortSpan)
      shortSpan = span;
  }

  return shortSpan;
}

void Span::fillAll() {
  static bool seeded = false;
  if (!seeded) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    seeded = true;
  }

  _vec.clear();
  _vec.resize(_size);
  std::generate(_vec.begin(), _vec.end(), std::rand);
}

