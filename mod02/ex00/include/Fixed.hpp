#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed(void);
		int getRawBits(void);
		void setRawBits(int const raw);

	private:
		int value;
		static const int fractionalBits = 8;
};

#endif
