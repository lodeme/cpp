#pragma once

#include <iostream>

template <typename T, typename F>
void iter(T* arr, int len, F& func) {
  for (int i = 0; i < len; i++) {
    arr[i] = func(arr[i]);
  }
}

template <typename T>
void printArr(T* arr, int len) {
  for (int i = 0; i < len; i++) {
    std::cout << arr[i] << (i == len - 1 ? "" : ", ");
  }
  std::cout << std::endl;
}

