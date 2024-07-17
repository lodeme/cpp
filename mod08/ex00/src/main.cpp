#include <easyfind.hpp>

#include <exception>
#include <iostream>
#include <vector>
#include <deque>
#include <list>

int main() {

  std::vector<int> vector;
  for (int i = 0; i < 5; i++) {
    vector.push_back(i);
  }
  try {
    easyfind(vector, 2);
    std::cout << "Value found" << std::endl;
    easyfind(vector, 5);
    std::cout << "Value found" << std::endl;
  } catch (std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }


  std::deque<int> deque;
  for (int i = 0; i < 5; i++) {
    deque.push_back(i);
  }
  try {
    easyfind(deque, 2);
    std::cout << "Value found" << std::endl;
    easyfind(deque, 5);
    std::cout << "Value found" << std::endl;
  } catch (std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }


  std::list<int> list;
  for (int i = 0; i < 5; i++) {
    list.push_back(i);
  }
  try {
    easyfind(list, 2);
    std::cout << "Value found" << std::endl;
    easyfind(list, 5);
    std::cout << "Value found" << std::endl;
  } catch (std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return 0;
}

