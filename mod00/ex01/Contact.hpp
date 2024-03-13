#ifndef CONTACT_HPP
#define CONTACT_HPP

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
		void displayContact() const;
		void displayHeader() const;
};

#endif
