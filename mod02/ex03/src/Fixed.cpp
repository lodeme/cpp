#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

// Canonical Form
Fixed::Fixed(void) : _value(0) {
}

Fixed::Fixed(const int intValue) : _value(intValue << _fractionalBits) {
}

Fixed::Fixed(const float floatValue) : _value(roundf(floatValue * (1 << _fractionalBits))) {
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed::~Fixed(void) {
}

// Operator overloading
Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->_value = other._value;
	}
	return *this;
}

Fixed& Fixed::operator++() {
	++_value;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++*this;
	return temp;
}

Fixed& Fixed::operator--() {
	--_value;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--*this;
	return temp;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fi) {
	os << fi.toFloat();
	return os;
}

bool Fixed::operator>(const Fixed& right) const {
	return this->_value > right._value;
}

bool Fixed::operator<(const Fixed& right) const {
	return this->_value < right._value;
}

bool Fixed::operator>=(const Fixed& right) const {
	return this->_value >= right._value;
}

bool Fixed::operator<=(const Fixed& right) const {
	return this->_value <= right._value;
}

bool Fixed::operator==(const Fixed& right) const {
	return this->_value == right._value;
}

bool Fixed::operator!=(const Fixed& right) const {
	return this->_value != right._value;
}

Fixed Fixed::operator+(const Fixed& right) const {
	return Fixed(this->_value + right._value);
}

Fixed Fixed::operator-(const Fixed& right) const {
	return Fixed(this->_value - right._value);
}

Fixed Fixed::operator*(const Fixed& right) const {
	return Fixed(this->toFloat() * right.toFloat());
}

Fixed Fixed::operator/(const Fixed& right) const {
	if (right._value == 0)
		throw std::runtime_error("Error: Division by zero");
	return Fixed(this->toFloat() / right.toFloat());
}

// min / max overloading
Fixed& Fixed::min(Fixed& left, Fixed& right) {
  if (left._value > right._value)
    return right;
  return left;
};

const Fixed& Fixed::min(const Fixed& left, const Fixed& right) {
  if (left._value > right._value)
    return right;
  return left;
};

Fixed& Fixed::max(Fixed& left, Fixed& right) {
  if (left._value > right._value)
    return left;
  return right;
};

const Fixed& Fixed::max(const Fixed& left, const Fixed& right) {
  if (left._value > right._value)
    return left;
  return right;
};

// Other member functions
int Fixed::toInt(void) const {
	return _value >> _fractionalBits;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::getRawBits(void) const {
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}
