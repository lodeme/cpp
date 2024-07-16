// vim: set filetype=cpp :

#include <iostream>
#include <Array.hpp>
#include <stdexcept>

// Canonical Form
template <typename T>
Array<T>::Array(): _size(0), _array(0) {}

template <typename T>
Array<T>::~Array() {
  delete[] _array;
}

template <typename T>
Array<T>::Array(Array& other): _size(other._size), _array(_size == 0 ? 0 : new T[_size]) {
  for (unsigned int i = 0; i < _size; i++) {
    _array[i] = other._array[i];
  }
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>& other) {
  if (*this != other) {
    delete[] _array;
    _size = other._size;
    _array = _size == 0 ? 0 : new T[_size];
    for (unsigned int i = 0; i < _size; i++) {
      _array[i] = other._array[i];
    }
  }
  return *this;
}

template <typename T>
Array<T>::Array(unsigned int i): _size(i), _array(_size == 0 ? 0 : new T[_size]) {}

// Other member functions
template <typename T>
unsigned int Array<T>::size() const {
  return _size;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) {
  if (i >= _size)
    throw std::out_of_range("index outside of array");
  return _array[i];
}


template <typename T>
void Array<T>::printArr() {
  for (unsigned int i = 0; i < _size; i++) {
    std::cout << _array[i] << (i == _size - 1 ? "" : ", ");
  }
  std::cout << std::endl;
}
