#pragma once

#include <ctime>
#include <list>
#include <vector>

class PmergeMe {
  private:
    std::list<int> _list;
    std::vector<int> _vector;
    std::clock_t _listTime;
    std::clock_t _vectorTime;

  public:
    // orthodox canonical form
    PmergeMe();
    PmergeMe(int argc, char** argv);
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    // private functions
    void FordJohnsonList();
    void FordJohsonVector();
    void sort();
    void displayResults();
};
