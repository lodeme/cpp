#include "PhoneBook.hpp"

void PhoneBook::addContact()
{
	int index = getOldestContact();
	contacts[index].setContact();
}

void PhoneBook::displayHeader() const
{
	std::cout
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << "|"
		<< std::setw(10) << "Phone Number" << "|"
		<< std::setw(10) << "Darkest Secret"
		<< std::endl;
}

void PhoneBook::displayPhoneBook() const
{
	displayHeader();
	for (int i = 0; i < 8; i++)
		contacts[i].displayContactRow();
}

void PhoneBook::getSingleContact() const
{
	int input;
	while (true)
	{
		std::cout << "Enter a contact number (0-7): ";
		if (std::cin >> input && input >= 0 && input <= 7)
			break ;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max());
		std::cout << "Incorrect value: ";
	}
	contacts[input].displayFullContact();
}

void PhoneBook::searchContact() const
{
	displayPhoneBook();
	getSingleContact();
}
