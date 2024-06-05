#pragma once
#include <string>

class Brain {
  private:
    std::string _ideas[100];

  public:
    Brain(void);
    ~Brain(void);
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
};
