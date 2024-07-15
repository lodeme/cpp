#include <Serializer.hpp>
#include <Data.hpp>
#include <cstdint>
#include <iostream>

int main(void) {

  Data* dataPtr = new Data;
  std::cout << "Data pointer before: " << dataPtr << std::endl;

  uintptr_t intPtr = Serializer::serialize(dataPtr);
  std::cout << "Data pointer serialized: " << intPtr << std::endl;

  Data* newDataPtr = Serializer::deserialize(intPtr);
  std::cout << "Data pointer deserialized: " << newDataPtr << std::endl;

  delete dataPtr;

  return 0;
}
