#include <algorithm>
#include <iter.hpp>
#include <string>

int triple(int i) {
  return i * 3;
}

std::string& reverseString(std::string& str) {
  std::reverse(str.begin(), str.end());
  return str;
}

int main() {

  // Test with int array
  int len = 3;
  int arr1[] = {1, 2, 3};
  ::iter(arr1, len, triple);
  ::printArr(arr1, len);

  // Test with string array
  len = 4;
  std::string arr2[] = {"This", "is", "a", "test"};
  ::iter(arr2, len, reverseString);
  ::printArr(arr2, len);

  return 0;
}
