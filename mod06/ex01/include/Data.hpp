#pragma once

#include <string>

class Data {
  private:
    const std::string _message;

  public:
    Data();
    ~Data();
    Data(Data& other);
    Data& operator=(Data& other);
};
