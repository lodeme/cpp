#include "PhoneBook.hpp"

int PhoneBook::getOldestContact() const
{
	int oldest = 0;
	for (int i = 0; i < 7; i++)
	{
		if (contacts[i].createdAt > contacts[i + 1].createdAt)
			oldest = i + 1;
	}
	return oldest;
}

void PhoneBook::addContact()
{
	int index = getOldestContact();
	contacts[index].setContact();
}

void PhoneBook::displayHeader() const
{
	std::cout
		<< std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << "|"
		<< std::endl
		<< std::string(10, '-') << "|"
		<< std::string(10, '-') << "|"
		<< std::string(10, '-') << "|"
		<< std::string(10, '-') << "|"
		<< std::endl;
}

void PhoneBook::displayPhoneBook() const
{
	displayHeader();
	for (int i = 0; i < 8; i++)
		contacts[i].displayContactRow(i);
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
