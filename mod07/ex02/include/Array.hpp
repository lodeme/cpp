#pragma once

template <typename T>
class Array {
 
  private:
    unsigned int _size;
    T* _array;

  public:
    // Canonical Form
    Array();
    ~Array();
    Array(Array& other);
    Array& operator=(Array& other);
    Array(unsigned int i);

    // Other member functions
    unsigned int size() const;
    T& operator[](unsigned int i);
    void printArr();
};


#include <../src/Array.tpp>

