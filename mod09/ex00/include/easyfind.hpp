#pragma once

#include <stdexcept>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
  typename T::iterator iter = std::find(container.begin(), container.end(), value);

  if (iter == container.end())
    throw std::runtime_error("value not found in container");

  return iter;
}
