#include <Data.hpp>

Data::Data(): _message("Default") {}

Data::~Data() {}

Data::Data(Data& other) {
  *this = other;
}

Data& Data::operator=(Data& other) {
  (void)other;
  return *this;
}
