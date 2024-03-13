#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
		std::time_t createdAt;

	public:
		void setContact();
		void displayFullContact() const;
		void displayContactRow() const;
		
};

#endif
