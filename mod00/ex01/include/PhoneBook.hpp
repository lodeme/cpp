#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int	getOldestContact() const;
		void displayHeader() const;
		void displayPhoneBook() const;
		void getSingleContact() const;

	public:
		void addContact();
		void searchContact() const;
};

#endif
