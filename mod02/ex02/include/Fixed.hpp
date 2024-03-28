#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed(void);
		Fixed(const int intValue);
		Fixed(const float floatValue);
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		bool operator>(const Fixed& right) const;
		bool operator<(const Fixed& right) const;
		bool operator>=(const Fixed& right) const;
		bool operator<=(const Fixed& right) const;
		bool operator==(const Fixed& right) const;
		bool operator!=(const Fixed& right) const;
		Fixed operator+(const Fixed& right) const;
		Fixed operator-(const Fixed& right) const;
		Fixed operator*(const Fixed& right) const;
		Fixed operator/(const Fixed& right) const;
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		~Fixed(void);
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int _value;
		static const int _fractionalBits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fi);

#endif
