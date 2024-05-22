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
		std::string formatField(std::string) const;
		bool isAscii(std::string str) const;
		void promptFieldValue(std::string prompt, std::string& field);

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
		void displayContactRow(int id) const;
};

#endif
