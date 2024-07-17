#pragma once

#include <vector>

class Span {
  private:
    unsigned int _size;
    std::vector<int> _vec;

  public:
    // Constructors and destructors
    Span();
    ~Span();
    Span(const Span& other);
    Span& operator=(const Span& other);
    Span(unsigned int size);

    // Member functions
    void addNumber(int n);
    unsigned int shortestSpan();
    unsigned int longestSpan();
    void fillAll();
};


