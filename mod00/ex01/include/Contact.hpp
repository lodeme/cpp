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

	public:
		Contact():
			firstName(""),
			lastName(""),
			nickname(""),
			phoneNumber(""),
			darkestSecret(""),
			createdAt(std::time(0)) {}
		std::time_t createdAt;
		void setContact();
		void displayFullContact() const;
		void displayContactRow() const;
};

#endif
